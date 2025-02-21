import tkinter as tk
from fenetre import Fenetre
from midi import MidiController

if __name__ == "__main__":
    root = tk.Tk()

    # Initialisation du MIDI
    midi_controller = MidiController()

    # Lancer l’interface avec MIDI
    app = Fenetre(root, midi_controller)
    root.mainloop()
