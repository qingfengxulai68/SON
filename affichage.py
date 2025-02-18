import tkinter as tk
from tkinter import ttk

# Fonction pour récupérer les valeurs des jauges
def get_values():
    print(f"Volume: {volume_scale.get()}")
    print(f"Atténuation hautes fréquences: {hf_attenuation_scale.get()}")
    print(f"Bruits mécaniques: {mechanical_noise_scale.get()}")
    print(f"Distance: {distance_scale.get()}")

# Création de la fenêtre principale
root = tk.Tk()
root.title("Réglages audio")

# Création des labels et des jauges (scales)
volume_label = tk.Label(root, text="Volume")
volume_label.grid(row=0, column=0, padx=10, pady=10)
volume_scale = tk.Scale(root, from_=0, to=100, orient="horizontal")
volume_scale.grid(row=0, column=1, padx=10, pady=10)

hf_attenuation_label = tk.Label(root, text="Atténuation hautes fréquences")
hf_attenuation_label.grid(row=1, column=0, padx=10, pady=10)
hf_attenuation_scale = tk.Scale(root, from_=0, to=100, orient="horizontal")
hf_attenuation_scale.grid(row=1, column=1, padx=10, pady=10)

mechanical_noise_label = tk.Label(root, text="Bruits mécaniques")
mechanical_noise_label.grid(row=2, column=0, padx=10, pady=10)
mechanical_noise_scale = tk.Scale(root, from_=0, to=100, orient="horizontal")
mechanical_noise_scale.grid(row=2, column=1, padx=10, pady=10)

distance_label = tk.Label(root, text="Distance")
distance_label.grid(row=3, column=0, padx=10, pady=10)
distance_scale = tk.Scale(root, from_=0, to=100, orient="horizontal")
distance_scale.grid(row=3, column=1, padx=10, pady=10)

# Bouton pour afficher les valeurs des jauges
apply_button = tk.Button(root, text="Appliquer", command=get_values)
apply_button.grid(row=4, column=0, columnspan=2, pady=20)

# Lancement de la boucle principale
root.mainloop()
