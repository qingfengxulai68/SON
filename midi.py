import mido

class MidiController:
    def __init__(self):
        """Initialise la connexion MIDI"""
        self.midi_out = None
        try:
            self.midi_out = mido.open_output('Teensy MIDI 1')
            print(f"MIDI connecté à Teensy MIDI 1")
            print(f"Port MIDI ouvert ? {self.midi_out is not None}")

        except IndexError:
            print("Aucun périphérique MIDI détecté.")

        print("Périphériques MIDI disponibles :")
        print(mido.get_output_names())


    def send_values(self, values, channel=0):
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
            match key:
                case 'Volume':
                    midi_cc = 7
                case 'Left_Pop_Trigger':
                    midi_cc = 8
                case 'Left_Scratch_Trigger':
                    midi_cc = 9
                case 'Left_rumble_Trigger':
                    midi_cc = 10
                case 'Motor_Noise_Left_Trigger':
                    midi_cc = 11
                case  'Motor_Noise_Right_Trigger':
                    midi_cc = 12
                case 'Right_Pop_Trigger':
                    midi_cc = 13
                case 'Right_Scratch_Trigger':
                    midi_cc = 14
                case 'Right_rumble_Trigger':
                    midi_cc = 15
                case 'gain_left':
                    midi_cc = 16
                case 'gain_right':
                    midi_cc = 17
            # midi_cc = start_cc + i
            midi_value = int(value * 127)  # Convertit en plage MIDI 0-127
            msg = mido.Message('control_change', control=midi_cc, value=midi_value)
            self.midi_out.send(msg)
            print(f"CC {midi_cc} ({key}): {midi_value}")

        print("Envoi terminé.")

