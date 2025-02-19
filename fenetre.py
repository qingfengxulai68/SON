import tkinter as tk

class Fenetre(tk.Tk):
    def __init__(self):
        super().__init__()
        # Création de la fenêtre principale
        self.title("Réglages Vinyl")

        # Création des labels et des jauges (scales)
        self.volume_label = tk.Label(self, text="Volume")
        self.volume_label.grid(row=0, column=0, padx=10, pady=10)
        self.volume_scale = tk.Scale(self, from_=0, to=100, orient="horizontal")
        self.volume_scale.grid(row=0, column=1, padx=10, pady=10)

        self.hf_attenuation_label = tk.Label(self, text="Atténuation hautes fréquences")
        self.hf_attenuation_label.grid(row=1, column=0, padx=10, pady=10)
        self.hf_attenuation_scale = tk.Scale(self, from_=0, to=100, orient="horizontal")
        self.hf_attenuation_scale.grid(row=1, column=1, padx=10, pady=10)

        self.mechanical_noise_label = tk.Label(self, text="Bruits mécaniques")
        self.mechanical_noise_label.grid(row=2, column=0, padx=10, pady=10)
        self.mechanical_noise_scale = tk.Scale(self, from_=0, to=100, orient="horizontal")
        self.mechanical_noise_scale.grid(row=2, column=1, padx=10, pady=10)

        self.distance_label = tk.Label(self, text="Distance")
        self.distance_label.grid(row=3, column=0, padx=10, pady=10)
        self.distance_scale = tk.Scale(self, from_=0, to=100, orient="horizontal")
        self.distance_scale.grid(row=3, column=1, padx=10, pady=10)

        # Bouton pour appliquer les réglages
        self.apply_button = tk.Button(self, text="Appliquer", command=self.get_values)
        self.apply_button.grid(row=4, column=0, columnspan=2, pady=20)

    # Fonction pour récupérer les valeurs des jauges
    def get_values(self):
        print(f"Volume: {self.volume_scale.get()}")
        print(f"Atténuation hautes fréquences: {self.hf_attenuation_scale.get()}")
        print(f"Bruits mécaniques: {self.mechanical_noise_scale.get()}")
        print(f"Distance: {self.distance_scale.get()}")

if __name__ == "__main__":
    fenetre = Fenetre()
    fenetre.mainloop()
