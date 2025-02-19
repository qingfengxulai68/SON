import mido

# Liste des ports de sortie disponibles
for port_name in mido.get_output_names():
    print(f"Port de sortie disponible: {port_name}")

# Ouvrir un port de sortie MIDI (choisissez le port correspondant à votre Teensy)
output_port = mido.open_output(mido.get_output_names()[0])

# Créer et envoyer un message MIDI (par exemple, une note ON)
message = mido.Message('note_on', note=60, velocity=64)
output_port.send(message)
