import mido

class MidiController:
    def __init__(self):
        """Initialise la connexion MIDI"""
        self.midi_out = None
        try:
            self.midi_out = mido.open_output(mido.get_output_names()[1])
            print(f"MIDI connecté à {mido.get_output_names()[1]}")
            print(f"Port MIDI ouvert ? {self.midi_out is not None}")

        except IndexError:
            print("Aucun périphérique MIDI détecté.")

        print("Périphériques MIDI disponibles :")
        print(mido.get_output_names())


    def send_values(self, values):
        """
        Envoie les valeurs FAUST sous forme de messages MIDI CC.
        
        :param values: Dictionnaire {paramètre: valeur}
        :param start_cc: Premier numéro de CC (20 par défaut)
        :param channel: Canal MIDI (0 = canal 1)
        """
        if not self.midi_out:
            print("Pas de sortie MIDI disponible !")
            return

        print(values)

        print("\nEnvoi des valeurs MIDI :")
        for i, (key, value) in enumerate(values.items()):
            match key:
                case 'Volume':
                    midi_cc = 7
                case 'white_noise':
                    midi_cc = 8
                case 'scratch_sound':
                    midi_cc = 9
                case 'dust_sound':
                    midi_cc = 10
                case 'rumble':
                    midi_cc = 11
                case 'motor_noise':
                    midi_cc = 12
            print(midi_cc)    

            midi_value = int(max(0, min(127, int(value * 127))))  # Convertit en plage MIDI 0-127
            msg = mido.Message('control_change', control=midi_cc, value=midi_value)
            self.midi_out.send(msg)
            print(f"CC {midi_cc} ({key}): {midi_value}")

        print("Envoi terminé.")

    def send_title(self, title):
        """Envoie le titre sélectionné en MIDI (converti en code ASCII)"""
        if not self.midi_out:
            print("Pas de sortie MIDI disponible !")
            return

        print(f"Envoi du titre : {title}")

        # Convertir en valeurs MIDI (ASCII de chaque lettre, max 7 caractères)
        title_bytes = [ord(char) for char in title[:7]]  # Max 7 caractères
        for i, byte in enumerate(title_bytes):
            msg = mido.Message('control_change', control=20 + i, value=byte)
            self.midi_out.send(msg)
            print(f"CC {20 + i}: {byte} ({title[i]})")

        print("Titre envoyé.")

    def send_etat(self, etat):
        """Envoie l'état Play/Pause sous forme de valeur MIDI"""
        if not self.midi_out:
            print("Pas de sortie MIDI disponible !")
            return

        etat_midi = 127 if etat == "play" else 0  # 127 = Play, 0 = Pause
        msg = mido.Message('control_change', control=14, value=etat_midi)
        self.midi_out.send(msg)
        print(f"État {etat} envoyé en MIDI (CC 14, valeur {etat_midi})")