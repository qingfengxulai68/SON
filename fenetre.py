import tkinter as tk
from tkinter import ttk
import json

class Fenetre:
    def __init__(self, root, midi_controller, json_file="parametres.json"):
        self.root = root
        self.root.title("Contrôle Audio")
        self.root.geometry("700x660")
        self.root.configure(bg="#2C3E50")

        self.midi_controller = midi_controller
        self.sliders = {}
        self.titles = ["k.wav", "yintian.wav", "loststars.wav", "beautifulgirls.wav"]
        self.selected_title = tk.StringVar(value=self.titles[0])
        self.send_title()

        self.init_values = {}

        style = ttk.Style()
        style.configure("TButton", padding=10, relief="flat", background="#34495E", foreground="#34495E", font=("Georgia", 10))
        style.configure("TLabel", background="#2C3E50", foreground="white", font=("Georgia", 10))

        title_frame = ttk.LabelFrame(self.root, padding=5)
        title_frame.pack(pady=5, padx=10, fill="x")

        ttk.Label(title_frame, text="Title :", style="TLabel").pack(side="left", padx=5)
        self.title_menu = ttk.Combobox(title_frame, textvariable=self.selected_title, values=self.titles, state="readonly")
        self.title_menu.pack(side="right", padx=5, fill="x", expand=True)

        control_frame = ttk.Frame(self.root, padding=5)
        control_frame.pack(pady=5, padx=10, fill="x")
        ttk.Button(control_frame, text="Change song", command=self.send_title, style="TButton").pack(side="left", pady=5, expand=True)
        
        ttk.Button(control_frame, text="Pause/Play", command=self.send_pauseplay, style="TButton").pack(side="right", padx=5, expand=True)

        with open(json_file, "r") as file:
            self.faust_config = json.load(file)

        slider_frame = ttk.Frame(self.root)
        slider_frame.pack(pady=10, padx=10, fill="both")

        left_frame = ttk.Frame(slider_frame)
        left_frame.pack(side="left", fill="both", expand=True, padx=10)
        right_frame = ttk.Frame(slider_frame)
        right_frame.pack(side="right", fill="both", expand=True, padx=10)

        for group in self.faust_config["ui"]:
            if "items" in group:
                for param in group["items"]:
                    if param["type"] in ["hslider", "nentry"]:
                        if param["shortname"] == "Volume":
                            self.create_slider(param, self.root)
                        elif len(self.sliders) % 2 == 0:
                            self.create_slider(param, left_frame)
                        else:
                            self.create_slider(param, right_frame)
                        self.init_values[param["shortname"]] = param["init"]

        button_frame = ttk.Frame(self.root, padding=5)
        button_frame.pack(pady=10, padx=10, fill="x")

        ttk.Button(button_frame, text="Valider", command=self.send_midi, style="TButton").pack(side="left", padx=5, expand=True)
        ttk.Button(button_frame, text="Reset", command=self.reset, style="TButton").pack(side="right", padx=5, expand=True)
        ttk.Button(button_frame, text="Supprimer Effet", command=self.remove_effect, style="TButton").pack(side="bottom", pady=5, expand=True)

        self.send_midi()

    def create_slider(self, param, parent):
        frame = ttk.LabelFrame(parent, text=param["shortname"], padding=5)
        frame.pack(pady=2, padx=10, fill="x")

        slider = ttk.Scale(frame, from_=param["min"], to=param["max"], orient="horizontal", length=300)
        slider.set(param["init"])
        slider.pack(pady=2, fill="x", expand=True)
        
        value_label = ttk.Label(frame, text=f"{param['init']}", style="TLabel")
        value_label.pack(side="top", padx=5)
        
        def update_label(value):
            value_label.config(text=f"{float(value):.2f}")
        
        slider.config(command=update_label)
        self.sliders[param["shortname"]] = slider

    def reset(self):
        for name, slider in self.sliders.items():
            for n, value in self.init_values.items():
                if name == n:
                    slider.set(value)
        self.send_midi()

    def remove_effect(self):
        effects = {"Lowpass Filter": 20000, "Distortion": 0, 
                   "White Noise": 0, "Echo Feedback": 0, "Echo Delay": 0, 
                   "Dust": 0, "Rumble": 0, "Motor Noise": 0}
        for name, value in effects.items():
            if name in self.sliders:
                self.sliders[name].set(value)
        self.send_midi()

    def send_midi(self):
        values = {name: slider.get() for name, slider in self.sliders.items()}
        print(values)
        self.midi_controller.send_values(values)

    def send_title(self):
        self.midi_controller.send_title(self.selected_title.get())

    def send_pauseplay(self):
        self.midi_controller.send_etat()
