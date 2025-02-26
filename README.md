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