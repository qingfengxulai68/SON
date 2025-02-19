import tkinter as tk
import json

# Charger le fichier JSON
with open("vinyl.dsp.json", "r") as file:
    faust_config = json.load(file)

class FaustGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Contrôle FAUST")

        self.sliders = {}

        # Zone d'affichage des valeurs
        self.values_display = tk.Text(self.root, height=10, width=50, state="disabled", bg="#f0f0f0")
        self.values_display.pack(pady=10)
    
        # Vérifier si la section "ui" existe
        if "ui" not in faust_config:
            print("Erreur : Pas de section 'ui' dans le JSON FAUST")
            return

        # Parcourir les groupes et ajouter les sliders
        for group in faust_config["ui"]:
            if "items" in group:
                for param in group["items"]:
                    if param["type"] == "hslider":
                        self.create_slider(param)

        # Bouton pour récupérer les valeurs des sliders
        self.get_values_button = tk.Button(self.root, text="Valider", command=self.get_values)
        self.get_values_button.pack(pady=10)

        self.get_values()
        
    def create_slider(self, param):
        """Crée un slider Tkinter en fonction des paramètres FAUST"""
        frame = tk.Frame(self.root)
        frame.pack(pady=5)

        label = tk.Label(frame, text=param["label"])
        label.pack()

        slider = tk.Scale(frame, from_=param["min"], to=param["max"],
                          resolution=param["step"], orient="horizontal")
        slider.set(param["init"])
        slider.pack()

        # Stocker le slider avec son adresse FAUST
        self.sliders[param["address"]] = slider

    def get_values(self):
        """Récupère et affiche les valeurs actuelles des sliders"""
        values = {address: slider.get() for address, slider in self.sliders.items()}

        # Affichage formaté dans la console
        print("\n=== Valeurs actuelles ===")
        for key, value in values.items():
            print(f"{key}: {value}")

        # Affichage formaté dans la fenêtre Tkinter
        self.values_display.config(state="normal")
        self.values_display.delete("1.0", tk.END)
        self.values_display.insert(tk.END, "=== Valeurs actuelles ===\n")
        for key, value in values.items():
            self.values_display.insert(tk.END, f"{key}: {value}\n")
        self.values_display.config(state="disabled")

root = tk.Tk()
app = FaustGUI(root)
root.mainloop()
