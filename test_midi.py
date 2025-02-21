import mido
import time

# Liste des sorties MIDI disponibles
print("Ports MIDI disponibles :", mido.get_output_names())

# Ouvrir le port MIDI correspondant au Teensy
port_name = None
for name in mido.get_output_names():
    if "Teensy" in name:  # Adaptez ce filtre selon le nom exact du port
        port_name = name
        break

if port_name is None:
    print("Aucun périphérique Teensy MIDI trouvé.")
else:
    with mido.open_output(port_name) as port:
        note = 60  # Do central (C4)
        velocity = 100  # Intensité de la note
        channel = 0  # Canal MIDI (0 pour le premier)

        # Envoyer un message Note On (Note activée)
        msg_on = mido.Message('note_on', note=note, velocity=velocity, channel=channel)
        port.send(msg_on)
        print(f"Note {note} ON")

        # Attendre 1 seconde
        time.sleep(10)

        # Envoyer un message Note Off (Note désactivée)
        msg_off = mido.Message('note_off', note=note, velocity=0, channel=channel)
        port.send(msg_off)
        print(f"Note {note} OFF")
