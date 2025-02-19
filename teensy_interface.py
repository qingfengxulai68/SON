from fenetre import Fenetre
from midi import *





if __name__ == "__main__":
    ports = port_dispo() 
    print(ports)
    sent_message('note_on', ports[0])
    fenetre = Fenetre()
    fenetre.mainloop()
    