
# Robot Traceur

Le Robot Traceur est un projet qui vise à créer un robot roulant pour tracer des figures géométriques de base. Le robot est contrôlé par un microcontrôleur Arduino et utilise trois moteurs pas à pas pour se déplacer.


## License

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)

## Fonctionnalités
Le robot a des fonctions de bases permettant de:
- Avancer de x cm
- Tourner de x degrés

A l'aide des fonctions précédentes, le robot peut tracer les figures géométriques suivantes :
- Carré
- Triangle
- Cercle
- Cercle autour d'un triangle

## Comment ça marche
Le robot reçoit des commandes via une connexion Bluetooth. Chaque commande est une lettre qui correspond à une figure géométrique spécifique :

- 'c' pour un carré
- 't' pour un triangle
- 'r' pour un cercle
- 'b' pour un cercle autour d'un triangle
Lorsqu'une commande est reçue, le robot commence à tracer la figure correspondante.

## Installation
1. Téléchargez le code source du projet.
2. Ouvrez le fichier wingman.ino dans l'IDE Arduino.
3. Téléchargez le code sur votre microcontrôleur Arduino.

## Utilisation
1. Connectez-vous au robot via Bluetooth.
2. Envoyez une lettre correspondant à la figure que vous voulez que le robot trace.

## Badges
## Badges
[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=arduino&logoColor=white)](https://www.arduino.cc/)
[![Bluetooth](https://img.shields.io/badge/Bluetooth-0082FC?style=flat&logo=bluetooth&logoColor=white)](https://www.bluetooth.com/)
[![MIT App Inventor](https://img.shields.io/badge/MIT%20App%20Inventor-FF4088?style=flat&logo=mit-app-inventor&logoColor=white)](https://appinventor.mit.edu/)