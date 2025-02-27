# SON ：EP (Vinyl) Simulator 
Implement a system that plugs to your living room sound system and makes the sound of any device you plug to it sound like an EP. For that, you will first have to document yourself on the impact on sound of this analog technology. There exists a couple of scientific papers that describe this fairly well. 

différence son Vinyl :
- distorsion harmonique totale plus élevée (La distorsion de deuxième ordre est plus agréable à écouter que la distorsion de troisième ordre)
- bruit mécanique (grondement ou de bruit de moteur)
- atténuation plus importante des hautes fréquences
- image stéréo dans les basses fréquences est souvent réduite ou rendue mono
- modifier de volume sonore
- le vinyle peut compresser la plage dynamique
--> https://www.projethomestudio.fr/reglages-compresseur-audio/

(Le son provient de gros haut-parleurs de 1,20 m de haut, plutôt que de petits écouteurs (effet lointain))
--> https://www.projethomestudio.fr/reverbe-mixage/ 

format WAV

faust -json vinyl.dsp : generer json




POSTER
- expliquer fonction faust 
- schéma traitement signal  ok
- explication choix des paramètre (des filtres et tout)
- attention pas trop de textes
- schéma du signal avant/après


                {
					"type": "hslider",
					"label": "lowpass_freq",
					"shortname": "lowpass_freq",
					"address": "/vinyl/lowpass_freq",
					"init": 1000,
					"min": 500,
					"max": 5000,
					"step": 10
				},
                {
					"type": "hslider",
					"label": "gain",
					"shortname": "gain",
					"address": "/vinyl/gain",
					"init": 0.5,
					"min": 0,
					"max": 1,
					"step": 0.01
				},
				{
					"type": "hslider",
					"label": "distortion",
					"shortname": "distortion",
					"address": "/vinyl/distortion",
					"init": 0.04,
					"min": 0,
					"max": 1,
					"step": 0.01
				},
				{
					"type": "hslider",
					"label": "compress_threshold",
					"shortname": "compress_threshold",
					"address": "/vinyl/compress_threshold",
					"init": -10,
					"min": -40,
					"max": 0,
					"step": 1
				},
				{
					"type": "hslider",
					"label": "compress_ratio",
					"shortname": "compress_ratio",
					"address": "/vinyl/compress_ratio",
					"init": 3,
					"min": 1,
					"max": 10,
					"step": 0.01
				},
				{
					"type": "hslider",
					"label": "compress_attack",
					"shortname": "compress_attack",
					"address": "/vinyl/compress_attack",
					"init": 0.01,
					"min": 0.001,
					"max": 0.01,
					"step": 0.001
				},
				{
					"type": "hslider",
					"label": "compress_release",
					"shortname": "compress_release",
					"address": "/vinyl/compress_release",
					"init": 0.1,
					"min": 0.01,
					"max": 1,
					"step": 0.01
				},