import mido

# Ouvrir le port MIDI (assurez-vous que le port MIDI est correct)
input_port = mido.open_input('Arduino MIDI 1')  # Remplacez par le nom de votre port MIDI

def traiter_message_midi(msg):
    if msg.type == 'note_on':
        print(f"Note ON: {msg.note}, Vélocité: {msg.velocity}")
    elif msg.type == 'note_off':
        print(f"Note OFF: {msg.note}")
    else:
        print(f"Autre message: {msg}")

# Lire les messages MIDI en boucle
for msg in input_port:
    traiter_message_midi(msg)
