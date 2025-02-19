import tkinter as tk
import json

# Charger le fichier JSON
with open("vinyl.dsp.json", "r") as file:
    faust_config = json.load(file)

class FaustGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Contrôle FAUST")

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

root = tk.Tk()
app = FaustGUI(root)
root.mainloop()
