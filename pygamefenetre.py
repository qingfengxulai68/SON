import pygame
import glob

LightPink = (224,205,169)
DarkPink = (188,158,130)
White = (255,255,255)
Black = (0,0,0)

class Fenetre:
    def __init__(self, midi_controller):
        pygame.init()
        pygame.display.set_caption("Vinyl Simulation")
        self.midi_controller = midi_controller
        self.running = True
        self.screen = pygame.display.set_mode((1104, 621))        
        self.clock = pygame.time.Clock()
        self.FPS = 10
        self.screen.fill([255, 255, 255])

        # Charger les frames du GIF et les redimensionner
        self.frames = [
            pygame.transform.scale(pygame.image.load(img), 
                (int(pygame.image.load(img).get_width() * 0.6), 
                int(pygame.image.load(img).get_height() * 0.6))
            ) 
            for img in sorted(glob.glob("images\\frame_*.png"))
        ]
        self.frame_index = 0
    
        self.stage = "vinyl"

        self.controls = [
                    {"label": "Lowpass Filter", "min": 100, "max": 20000, "value": 1000, "step": 100},
                    {"label": "Distortion", "min": 0, "max": 1, "value": 0.04, "step": 0.01},
                    {"label": "White Noise", "min": 0, "max": 1, "value": 0.7, "step": 0.01},
                    {"label": "Dust", "min": 0, "max": 0.1, "value": 0.007, "step": 0.001},
                    {"label": "Rumble", "min": 0, "max": 1, "value": 1, "step": 0.01},
                    {"label": "Motor Noise", "min": 0, "max": 1, "value": 0.3, "step": 0.01},
                    {"label": "Echo Feedback", "min": 0, "max": 1, "value": 0.5, "step": 0.01},
                    {"label": "Echo Delay", "min": 0, "max": 0.25, "value": 0.1, "step": 0.01},
                    {"label": "Volume", "min": 0, "max": 1, "value": 0.5, "step": 0.01}
                ]
        self.y_offset = 20
        self.init = self.controls
        self.dragging = None
        
        self.start()

    def start(self):
        self.button_options = self.button_create("OPTIONS", (450, 250, 150, 40), LightPink, DarkPink, self.on_click_button_options)
        self.button_pause = self.button_create("Pause/Play", (100, 30, 200, 40), LightPink, DarkPink, self.send_pauseplay)
        self.button_k = self.button_create("K", (50, 100, 300, 30), LightPink, DarkPink, self.title_0)
        self.button_lost = self.button_create("Lost Stars", (50, 145, 300, 30), LightPink, DarkPink, self.title_1)
        self.button_yintian = self.button_create("Yintian", (50, 190, 300, 30), LightPink, DarkPink, self.title_2)
        self.button_bg = self.button_create("Beautiful Girls", (50, 235, 300, 30), LightPink, DarkPink, self.title_3)
        self.button_return = self.button_create("RETURN", (400, 500, 150, 40), LightPink, DarkPink, self.on_click_button_return)
        self.button_remove = self.button_create("remove effects", (250, 450, 300, 30), LightPink, DarkPink, self.remove)
        self.button_reset = self.button_create("reset effects", (600, 450, 300, 30), LightPink, DarkPink, self.reset)
        self.button_send = self.button_create("SEND", (600, 500, 150, 40), LightPink, DarkPink, self.send_values)
        self.send_values()
        self.main_loop()

    def update(self):
        pygame.display.update()
        self.clock.tick(self.FPS)

    def draw_background(self):
        if self.stage == "vinyl":
            background = pygame.transform.scale(pygame.image.load("images\\background_pixel.jpg"),
                (int(pygame.image.load("images\\background_pixel.jpg").get_width() * 1.5), 
                int(pygame.image.load("images\\background_pixel.jpg").get_height() * 1.5))
            ) 
            self.screen.blit(background, (0,0))
            
            # Afficher l'image actuelle du GIF (redimensionnée)
            self.screen.blit(self.frames[self.frame_index], (695, 180))

            # Passer à la frame suivante
            self.frame_index = (self.frame_index + 1) % 2
        
        else:
            background = pygame.transform.scale(pygame.image.load("images\\background_pixel_options.jpg"),
                (int(pygame.image.load("images\\background_pixel_options.jpg").get_width() * 1.5), 
                int(pygame.image.load("images\\background_pixel_options.jpg").get_height() * 1.5))
            ) 
            self.screen.blit(background, (0,0))

    def button_create(self,text, rect, inactive_color, active_color, action):
        self.font = pygame.font.Font("Pokemon GB.ttf", 16)
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

    def create_sliders(self):
        self.y_offset = 20
        for control in self.controls:
            text = self.font.render(f"{control['label']}: {round(control['value'], 2)}", True, White)
            self.screen.blit(text, (50, self.y_offset))
            pygame.draw.rect(self.screen, (100, 100, 100), (500, self.y_offset, 500, 10))
            pos = int(500 + (control['value'] - control['min']) / (control['max'] - control['min']) * 500)
            pygame.draw.circle(self.screen, (200, 0, 0), (pos, self.y_offset + 5), 5)
            self.y_offset += 40

    def on_click_button_return(self):
        self.stage = 'vinyl'
        print('You clicked Button Return')

    def on_click_button_options(self):
        self.stage = 'options'
        print('You clicked Button Options')

    def title_0(self):
        self.midi_controller.send_title("k.wav")
    def title_1(self):
        self.midi_controller.send_title("loststars.wav")
    def title_2(self):
        self.midi_controller.send_title("yintian.wav")
    def title_3(self):
        self.midi_controller.send_title("beautifulgirls.wav")

    def send_pauseplay(self):
        self.midi_controller.send_etat()
    
    def reset(self):
        init = {"Lowpass Filter": 1000, "Distortion": 0.04, 
                   "White Noise": 0.7, "Echo Feedback": 0.5, "Echo Delay": 0.1, 
                   "Dust": 0.007, "Rumble": 1, "Motor Noise": 0.3}
        
        for name, value in init.items():
            for slider in self.controls:
                if name == slider["label"]:
                    slider["value"] = value
        self.send_values()
            
    def remove(self):
        effects = {"Lowpass Filter": 20000, "Distortion": 0, 
                   "White Noise": 0, "Echo Feedback": 0, "Echo Delay": 0, 
                   "Dust": 0, "Rumble": 0, "Motor Noise": 0}
        
        for name, value in effects.items():
            for slider in self.controls:
                if name == slider["label"]:
                    slider["value"] = value
        self.send_values()

    def send_values(self):
        values = {}
        for effet in self.controls:
            values[effet['label']] = effet['value']
        self.midi_controller.send_values(values)

    def manage_events(self, event):
        if event.type == pygame.QUIT:
            self.quit()
        if self.stage == 'vinyl':
            self.button_check(self.button_options, event)
            self.button_check(self.button_pause, event)
            self.button_check(self.button_k, event)
            self.button_check(self.button_lost, event)
            self.button_check(self.button_yintian, event)
            self.button_check(self.button_bg, event)

                
        elif self.stage == 'options':
            self.button_check(self.button_remove, event)
            self.button_check(self.button_reset, event)
            self.button_check(self.button_return, event)
            self.button_check(self.button_send, event)
            if event.type == pygame.MOUSEBUTTONDOWN:
                x, y = event.pos
                for i, control in enumerate(self.controls):
                    y_slider = 20 + i * 40
                    pos = int(500 + (control['value'] - control['min']) / (control['max'] - control['min']) * 500)
                    if pos - 5 <= x <= pos + 5 and y_slider <= y <= y_slider + 10:
                        self.dragging = i

            elif event.type == pygame.MOUSEBUTTONUP:
                self.dragging = None

            elif event.type == pygame.MOUSEMOTION and self.dragging is not None:
                x, _ = event.pos
                ratio = max(0, min(1, (x - 500) / 500))
                self.controls[self.dragging]['value'] = self.controls[self.dragging]['min'] + ratio * (self.controls[self.dragging]['max'] - self.controls[self.dragging]['min'])
       
    def main_loop(self):
        while self.running:
            if self.stage == 'vinyl':
                self.draw_background()
                self.button_draw(self.button_options)
                self.button_draw(self.button_pause)
                self.button_draw(self.button_k)
                self.button_draw(self.button_lost)
                self.button_draw(self.button_yintian)
                self.button_draw(self.button_bg)
            
            elif self.stage == "options":
                self.draw_background()
                self.button_draw(self.button_return)
                self.button_draw(self.button_reset)
                self.button_draw(self.button_remove)
                self.button_draw(self.button_send)
                self.create_sliders()
            
            for event in pygame.event.get():    
                self.manage_events(event)
            self.update()
        self.quit()

