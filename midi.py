import mido
import numpy as np

class MidiController:
    def __init__(self):
        self.midi_out = None
        self.previous_values = {}
        try:
            self.midi_out = mido.open_output(mido.get_output_names()[1])
            print(f"MIDI connecté à {mido.get_output_names()[1]}")
            print(f"Port MIDI ouvert ? {self.midi_out is not None}")

        except IndexError:
            print("Aucun périphérique MIDI détecté.")

        print("Périphériques MIDI disponibles :")
        print(mido.get_output_names())


    def send_values(self, values):
        if not self.midi_out:
            print("Pas de sortie MIDI disponible !")
            return

        modified_values = {
            key: value for key, value in values.items()
            if key not in self.previous_values or self.previous_values[key] != value
        }

        if not modified_values:
            print("Aucune valeur modifiée, rien à envoyer.")
            return

        print("\nEnvoi des valeurs MIDI (modifiées uniquement) :")
        for key, value in modified_values.items():
            midi_cc = {
                # 'compress_threshold':30,
                # 'compress_ratio':31,
                # 'compress_attack':32,
                # 'compress_release':33,
                'Lowpass Filter': 4,
                'Distortion': 5,
                # 'gain': 6,
                'Volume': 7,
                'White Noise': 8,
                'Echo Feedback': 9,
                'Dust': 10,
                'Rumble': 11,
                'Motor noise': 12,
                'Echo Delay': 13,
            }.get(key, None)

            if midi_cc is not None:
                if midi_cc == 4:
                    midi_value = int(1 + (np.log10(value/20)/np.log10(20000/20))*(127 - 1))
                # elif midi_cc == 30:
                    # midi_value = int((value + 40)*(127/40))
                # elif midi_cc == 31:
                #     midi_value = int(max(0, min(127, int(value * 12.7))))
                elif midi_cc == 10:
                    midi_value = int(max(0, min(127, int(value * 1270))))
                else:
                    midi_value = int(max(0, min(127, int(value * 127))))  # Convertit en plage MIDI 0-127
                msg = mido.Message('control_change', control=midi_cc, value=midi_value)
                self.midi_out.send(msg)
                print(f"CC {midi_cc} ({key}): {midi_value}")

        # Mettre à jour les valeurs précédentes
        self.previous_values.update(modified_values)

        print("Envoi terminé.")

    def send_title(self, title):
        if not self.midi_out:
            print("Pas de sortie MIDI disponible !")
            return

        print(f"Envoi du titre : {title}")
        match title:
            case "yintian.wav":
                index = 0
            case "k.wav":
                index = 1
            case "loststars.wav":
                index = 2
            case "beautifulgirls.wav":
                index = 3
        msg = mido.Message('control_change', control=26, value=index)
        self.midi_out.send(msg)
        print(f"CC 26: index :{index} -> ({title})")
        print("Titre envoyé.")

    def send_etat(self):
        if not self.midi_out:
            print("Pas de sortie MIDI disponible !")
            return
        msg = mido.Message('control_change', control=14, value=127)
        self.midi_out.send(msg)
        print(f"État press envoyé en MIDI (CC 14, valeur {127})")