import tkinter as tk
import json

class Fenetre:
    def __init__(self, root, midi_controller, json_file="parametres.json"):
        self.root = root
        self.root.title("Fenêtre de Contrôle")
        self.midi_controller = midi_controller  # Instance du MidiController

        self.sliders = {}  # Stocke les sliders avec leurs adresses

        # Zone d'affichage des valeurs actuelles
        # self.values_display = tk.Text(self.root, height=10, width=50, state="disabled", bg="#f0f0f0")
        # self.values_display.pack(pady=10)

        # Ajout du choix du titre
        self.titles = ["YINTIAN.WAV", "SONG_1.WAV", "SONG_2.WAV"]  # Liste des titres disponibles
        self.selected_title = tk.StringVar(value=self.titles[0])

        title_frame = tk.Frame(self.root)
        title_frame.pack(pady=10)

        tk.Label(title_frame, text="Choisir un titre:").pack(side="left", padx=5)
        self.title_menu = tk.OptionMenu(title_frame, self.selected_title, *self.titles)
        self.title_menu.pack(side="right", padx=5)

        # Ajout des boutons Play/Pause
        self.etat = "play"

        control_frame = tk.Frame(self.root)
        control_frame.pack(pady=5)

        self.song_button = tk.Button(control_frame, text="Change song", command=self.send_title)
        self.song_button.pack(side="top", padx=5)

        self.play_button = tk.Button(control_frame, text="Play", command=self.send_play)
        self.play_button.pack(side="left", padx=5)

        self.pause_button = tk.Button(control_frame, text="Pause", command=self.send_pause)
        self.pause_button.pack(side="right", padx=5)

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

        return values  # Retourne les valeurs

    def send_midi(self):
        """Récupère les valeurs et les envoie au MIDI"""
        values = self.get_values()
        self.midi_controller.send_values(values)

    def send_title(self):
        """Envoie le titre sélectionné au contrôleur MIDI"""
        self.midi_controller.send_title(self.selected_title.get())

    def send_play(self):
        """Envoie l'état Play au contrôleur MIDI"""
        self.etat = "play"
        self.midi_controller.send_etat(self.etat)

    def send_pause(self):
        """Envoie l'état Pause au contrôleur MIDI"""
        self.etat = "pause"
        self.midi_controller.send_etat(self.etat)
