import mido

class MidiController:
    def __init__(self):
        """Initialise la connexion MIDI avec le premier périphérique détecté."""
        self.midi_out = None
        try:
            self.midi_out = mido.open_output(mido.get_output_names()[0])
            print(f"MIDI connecté à {mido.get_output_names()[0]}")
        except IndexError:
            print("Aucun périphérique MIDI détecté ! Vérifie que le Teensy est bien branché.")

    def send_values(self, values, start_cc=20, channel=0):
        """
        Envoie les valeurs FAUST sous forme de messages MIDI CC.
        
        :param values: Dictionnaire {paramètre: valeur}
        :param start_cc: Premier numéro de CC (20 par défaut)
        :param channel: Canal MIDI (0 = canal 1)
        """
        if not self.midi_out:
            print("Pas de sortie MIDI disponible !")
            return

        print("\nEnvoi des valeurs MIDI :")
        for i, (key, value) in enumerate(values.items()):
            midi_cc = start_cc + i
            midi_value = int(value * 127)  # Convertit en plage MIDI 0-127
            msg = mido.Message('control_change', channel=channel, control=midi_cc, value=midi_value)
            self.midi_out.send(msg)
            print(f"CC {midi_cc} ({key}): {midi_value}")

        print("Envoi terminé.")

