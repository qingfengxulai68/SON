import mido
import tkinter as tk

print("Périphériques MIDI disponibles :")
print(mido.get_output_names())

# Ouvrir le port MIDI
output_port = mido.open_output(mido.get_output_names()[0])

# Fonction pour envoyer un message MIDI Control Change (Volume)
def envoyer_volume(volume):
    # Le contrôleur 7 est pour le volume
    controller = 7  # Contrôleur MIDI pour le volume
    message = mido.Message('control_change', control=controller, value=int(volume))
    output_port.send(message)  # Envoie le message MIDI

# Fonction pour mettre à jour le label avec la valeur du volume
def update_volume(val):
    label_volume.config(text=f"Volume: {int(val)}")
    envoyer_volume(val)  # Envoie la nouvelle valeur au Teensy

# Initialiser Tkinter
root = tk.Tk()
root.title("Contrôle MIDI Volume")

# Ajouter un curseur pour ajuster le volume
volume_slider = tk.Scale(root, from_=0, to=100, orient="horizontal", command=update_volume)
volume_slider.set(50)  # Valeur initiale du volume à 64
volume_slider.pack(pady=20)

# Ajouter un label pour afficher la valeur actuelle du volume
label_volume = tk.Label(root, text="Volume: 64", font=("Helvetica", 16))
label_volume.pack()

# Démarrer l'interface Tkinter
root.mainloop()
