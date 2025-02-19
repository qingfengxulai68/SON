import mido

def port_dispo():
    ports = []
    # Liste des ports de sortie disponibles
    for port_name in mido.get_output_names():
        ports.append(port_name)
    return ports

def sent_message(msg, port_name):
    # Créer et envoyer un message MIDI (par exemple, une note ON)
    message = mido.Message(msg, note=60, velocity=64)
    output_port = mido.open_output(port_name)
    output_port.send(message)


if __name__ == "__main__":
    for port_name in mido.get_output_names():
        print(f"Port de sortie disponible: {port_name}")
    
