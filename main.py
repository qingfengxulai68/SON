import tkinter as tk
from faustGUI import FaustGUI
from midi import MidiController

if __name__ == "__main__":
    root = tk.Tk()

    # Initialisation du MIDI
    midi_controller = MidiController()

    # Lancer l’interface avec MIDI
    app = FaustGUI(root, midi_controller)
    root.mainloop()
