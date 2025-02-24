import tkinter as tk
import json

class Fenetre:
    def __init__(self, root, midi_controller, json_file="vinyl.dsp.json"):
        self.root = root
        self.root.title("Fenêtre de Contrôle")
        self.midi_controller = midi_controller  # Instance du MidiController

        self.sliders = {}  # Stocke les sliders avec leurs adresses
        
        # Zone d'affichage des valeurs actuelles
        self.values_display = tk.Text(self.root, height=10, width=50, state="disabled", bg="#f0f0f0")
        self.values_display.pack(pady=10)

        # Charger le JSON FAUST
        with open(json_file, "r") as file:
            self.faust_config = json.load(file)

        # Générer les sliders
        for group in self.faust_config["ui"]:
            if "items" in group:
                for param in group["items"]:
                    if param["type"] in ["hslider", "nentry"]:
                        self.create_slider(param)

        # Boutons de contrôle
        button_frame = tk.Frame(self.root)
        button_frame.pack(pady=10)

        self.get_values_button = tk.Button(button_frame, text="Valider", command=self.get_values)
        self.get_values_button.pack(side="left", padx=5)

        self.send_midi_button = tk.Button(button_frame, text="Envoyer MIDI", command=self.send_midi)
        self.send_midi_button.pack(side="right", padx=5)

        self.get_values()

    def create_slider(self, param):
        """Crée un slider Tkinter en fonction des paramètres FAUST"""
        frame = tk.Frame(self.root)
        frame.pack(pady=5, fill="x")

        label = tk.Label(frame, text=param["shortname"], width=20, anchor="w")
        label.pack(side="left", padx=5)

        slider = tk.Scale(frame, from_=param["min"], to=param["max"],
                          resolution=param["step"], orient="horizontal", length=300)
        slider.set(param["init"])
        slider.pack(side="right", padx=5)

        # Stocker le slider avec son adresse FAUST
        self.sliders[param["shortname"]] = slider

    def get_values(self):
        """Récupère et affiche les valeurs actuelles des sliders"""
        values = {address: slider.get() for address, slider in self.sliders.items()}

        print("\n=== Valeurs actuelles ===")
        for key, value in values.items():
            print(f"{key}: {value}")

        # Mise à jour de l'affichage Tkinter
        self.values_display.config(state="normal")
        self.values_display.delete("1.0", tk.END)
        self.values_display.insert(tk.END, "=== Valeurs actuelles ===\n")
        for key, value in values.items():
            self.values_display.insert(tk.END, f"{key}: {value}\n")
        self.values_display.config(state="disabled")
        return values  # Retourne les valeurs

    def send_midi(self):
        """Récupère les valeurs et les envoie au MIDI"""
        values = self.get_values()
        self.midi_controller.send_values(values)
        self.midi_controller.send_msg()
