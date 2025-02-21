import tkinter as tk
import serial
import threading
import time

# Configurer la communication série (assurez-vous que le port est correct)
arduino = serial.Serial('Teensy 4.0', 9600, timeout=1)  # Remplacer COM3 par le port correct

# Fonction pour lire les données de l'Arduino dans un thread séparé
def lire_arduino():
    while True:
        if arduino.in_waiting > 0:
            temperature = arduino.readline().decode('utf-8').strip()
            afficher_temperature(temperature)
        time.sleep(0.1)

# Fonction pour afficher la température sur l'interface Tkinter
def afficher_temperature(temperature):
    label_temp.config(text=f"Température: {temperature} °C")

# Fonction pour envoyer une commande vers l'Arduino (par exemple, pour allumer/éteindre une LED)
def envoyer_commande():
    arduino.write(b"LED ON\n")  # Exemple de commande pour Arduino

# Initialiser l'interface Tkinter
root = tk.Tk()
root.title("Interface Arduino")

# Label pour afficher la température
label_temp = tk.Label(root, text="Température: N/A", font=("Helvetica", 16))
label_temp.pack(pady=20)

# Bouton pour envoyer une commande à l'Arduino
button_led_on = tk.Button(root, text="Allumer LED", command=envoyer_commande)
button_led_on.pack(pady=10)

# Lancer le thread pour lire les données Arduino
thread_lecture = threading.Thread(target=lire_arduino, daemon=True)
thread_lecture.start()

# Démarrer l'interface Tkinter
root.mainloop()
