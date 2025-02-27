# import tkinter as tk
# from fenetre import Fenetre
# from midi import MidiController

# if __name__ == "__main__":
#     root = tk.Tk()

#     midi_controller = MidiController()

#     app = Fenetre(root, midi_controller)
#     root.mainloop()

import pygame
from pygamefenetre import Fenetre 
from midi import MidiController

if __name__ == "__main__":
    pygame.init()

    # Initialisation du MIDI
    midi_controller = MidiController()

    # Lancer l’interface avec MIDI
    app = Fenetre(midi_controller)
    app.main_loop()
    pygame.QUIT
