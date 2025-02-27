import pygame
import json

LightPink = (255,182,193)
DarkPink = (253,108,158)
White = (255,255,255)
Black = (0,0,0)
DirtBrown = (97,63,16)
GrassGreen = (44,176,55)
CloudWhite = (250,242,248)
oceanBlue = (79,66,181)
skyBlue = (135,206,235)
DarkBrown = (51,0,0)
LightBrown = (204,102,0)

class Fenetre:
    def __init__(self, midi_controller, json_file="parametres.json"):
        pygame.init()
        self.midi_controller = midi_controller
        self.title = "Vinyl Simulation"
        self.running = True
        self.screen = pygame.display.set_mode((1280, 720))        
        self.clock = pygame.time.Clock()
        
        self.screen.fill([255, 255, 255])
        background = pygame.image.load("images\\Background.png").convert()
        self.screen.blit(background, (0,0))

        self.titles = ["k.wav", "yintian.wav", "loststars.wav"]
        self.selected_title = self.titles[0]
        self.send_title()
        
        self.stage = "menu"

        self.sliders = {}
        self.init_values = {}
        
        with open(json_file, "r") as file:
            self.faust_config = json.load(file)

        self.start()

    def start(self):
        self.button_return = self.button_create("RETOUR", (540, 500, 200, 75), LightPink, DarkPink, self.on_click_button_return)
        self.button_play = self.button_create("Valider", (540, 500, 200, 75), LightPink, DarkPink, self.on_click_button_valider) 
        self.main_loop()

            
    def manage_events(self, event):
        if event.type == pygame.QUIT:
            self.quit()
        if self.stage == 'vinyl':
                self.button_check(self.button_1, event)
                self.button_check(self.button_2, event)
                self.button_check(self.button_3, event)
                
        elif self.stage == 'options':
                self.button_check(self.button_play, event)
                self.button_check(self.button_retrun, event)
        
    def update(self):
        self.clock.tick(self.FPS)
        pygame.display.update()

    def create_slider(self, param, y):

    def  (self):
        self.midi_controller.send_title(self.selected_title)

    def send_play(self):
        self.midi_controller.send_etat("play")

    def send_pause(self):
        self.midi_controller.send_etat("pause")
    
    def reset(self):
        for name, slider in self.sliders.items():
            for n, value in self.init_values.items():
                if name == n:
                    slider.set(value)

    def remove(self):
        effects = {"Lowpass Filter": 20000, "Distortion": 0, 
                   "White Noise": 0, "Echo Feedback": 0, "Echo Delay": 0, 
                   "Dust": 0, "Rumble": 0, "Motor Noise": 0}
        
        for name, value in effects.items():
            if name in self.sliders:
                self.sliders[name].set_current_value(value)

    def send_values(self):
        values = {name: slider.get_current_value() for name, slider in self.sliders.items()}
        self.midi_controller.send_values(values)

    def button_create(self,text, rect, inactive_color, active_color, action):
        self.font = pygame.font.Font(None, 40)
        button_rect = pygame.Rect(rect)
        text = self.font.render(text, True, Black)
        text_rect = text.get_rect(center=button_rect.center)

        return [text, text_rect, button_rect, inactive_color, active_color, action, False]

    
    def button_check(self,info, event):
        text, text_rect, rect, inactive_color, active_color, action, hover = info
        if event.type == pygame.MOUSEMOTION:
            # hover = True/False   
            info[-1] = rect.collidepoint(event.pos)

        elif event.type == pygame.MOUSEBUTTONDOWN:
            if hover and action:      
                action()

    def button_draw(self, info):
        text, text_rect, rect, inactive_color, active_color, action, hover = info
        if hover:
            color = active_color
        else:
            color = inactive_color
        pygame.draw.rect(self.screen, color, rect)
        self.screen.blit(text, text_rect)
    
    def zone_text(self, text, rect):
        text = self.font.render(text, True, Black)
        zone_rect = pygame.Rect(rect)
        text_rect = text.get_rect(center=zone_rect.center)
        pygame.draw.rect(self.screen, skyBlue, rect)
        self.screen.blit(text, text_rect)

    def on_click_button_return(self):
        self.stage = 'vinyl'
        self.click = []
        print('You clicked Button Return')

    def main_loop(self):
        while self.running:
            if self.stage == 'vinyl':
                self.button_draw(self.button_1)
                self.button_draw(self.button_2)
                self.button_draw(self.button_3)
            
            elif self.stage == "options":
                self.zone_text("Choix du véhicule",((50,50),(300,30)))
                self.zone_text("Choix du niveau",((500,50),(300,30)))
                self.zone_text("Choix des poutres",((950,50),(300,30)))
                self.button_draw(self.button_truck)
                self.button_draw(self.button_car)
                self.button_draw(self.button_velo)
                
            
            for event in pygame.event.get():    
                self.manage_events(event)
            self.update()
        self.quit()
