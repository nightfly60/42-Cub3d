# 🧱 cub3D - 42 Project

## 🌍 Languages
[English](#english-version) | [Français](#version-française)

---

## English Version

# 🧱 cub3D - 42 Project

> _"My first RayCaster with miniLibX."_  
> _Inspired by the legendary Wolfenstein 3D, build your own 3D maze using raycasting._

---

## 📘 Overview
**cub3D** is a 42 graphics project inspired by *Wolfenstein 3D*, one of the first 3D games ever created.  
The goal is to build a simple 3D game engine using **raycasting**, where the player can explore a maze in first-person view.

![cub3D preview](https://imgur.com/a/oxLlMux)

This project introduces **mathematical rendering techniques**, **MiniLibX graphics**, and **real-time user input management**, all coded in pure **C**.

---

## 🎯 Project Goals
- Understand the principles of **raycasting** and projection.
- Learn to work with **MiniLibX**, the 42 graphical library.
- Manage **player movement**, **rotations**, and **keyboard events**.
- Parse and validate a **.cub configuration file** (map, textures, and colors).
- Render **walls**, **floor**, and **ceiling** in real time using 2D data.
- Develop clean, optimized, and modular C code.

---

## ⚙️ Mandatory Features
| Feature | Description |
|----------|-------------|
| **Raycasting Engine** | Render a 3D view of a 2D map using raycasting. |
| **Player Movement** | Move with `W`, `A`, `S`, `D` and rotate with `←` and `→`. |
| **Textures** | Different wall textures for each direction (`NO`, `SO`, `WE`, `EA`). |
| **Colors** | Custom floor (`F`) and ceiling (`C`) colors in RGB format. |
| **Map Parsing** | Read and validate a `.cub` file that defines textures, colors, and the map. |
| **Window Management** | Smooth opening, resizing, and closing behavior (ESC key or red cross). |
| **Error Handling** | Graceful exit with meaningful messages if the configuration is invalid. |

---

## 📂 Example of a `.cub` Map File
```cub
    NO ./textures/north.xpm
    EA ./textures/east.xpm
    F 220,100,0
    C 225,30,0
    SO ./textures/south.xpm
    WE ./textures/west.xpm
            1111111111111111111111111
            1000000000110000000000001
            1011000001110000000000001
            1001000000000000000000001
    111111111011000001110000000000001
    100000000011000001110111111111111
    11110111111111011100000000001
    11110111111111011101010010001
    11000000110101011100000010001
    10000000000000001100000010001
    10000000000000001101010010001
    11000001110101011111011110N0111
    11110111 1110101 101111010001
    11111111 1111111 111111111111
```

---

## 🧩 Bonus Features Implemented
Bonuses are only evaluated if the mandatory part is **100% functional**.  
We chose to implement the following bonus features:

| Bonus Feature | Description |
|----------------|--------------|
| **Wall Collision** | Prevents the player from walking through walls. The movement logic checks for map collisions in real time. |
| **Mouse Movement** | Allows camera rotation using mouse motion for smoother and more natural control. |
| **Minimap with Field of View** | Displays a 2D minimap showing the player’s position, walls, and a dynamic field of vision cone. |

These features enhance immersion and improve gameplay experience, bringing the project closer to a true FPS feel.

---

## 🛠️ Technical Details

### 🔹 Language & Tools
- **Language:** C  
- **Graphics Library:** MiniLibX  

---

## Version Française

> _« Mon premier RayCaster avec miniLibX. »_  
> _Inspiré du légendaire Wolfenstein 3D, construisez votre propre labyrinthe 3D grâce au raycasting._

---

## 📘 Aperçu
**cub3D** est un projet graphique de 42 inspiré du jeu *Wolfenstein 3D*, l’un des premiers jeux en pseudo-3D jamais créés.  
L’objectif est de concevoir un moteur de jeu 3D simple à l’aide de la technique du **raycasting**, permettant au joueur d’explorer un labyrinthe en vue à la première personne.

<p align="center">
  <img src="https://imgur.com/a/oxLlMux" alt="cub3D Screenshot" width="600"/>
</p>

Ce projet introduit les **bases du rendu mathématique**, la **librairie graphique MiniLibX**, et la **gestion des entrées utilisateur en temps réel**, le tout entièrement codé en **C**.

---

## 🎯 Objectifs du projet
- Comprendre les principes du **raycasting** et de la projection.  
- Apprendre à utiliser **MiniLibX**, la bibliothèque graphique de 42.  
- Gérer les **déplacements du joueur**, les **rotations** et les **événements clavier**.  
- Lire et valider un fichier de configuration **.cub** (carte, textures et couleurs).  
- Rendre les **murs**, le **sol** et le **plafond** en temps réel à partir de données 2D.  
- Développer un code **propre, optimisé et modulaire**.

---

## ⚙️ Fonctionnalités obligatoires
| Fonctionnalité | Description |
|----------------|-------------|
| **Moteur de Raycasting** | Génère une vue 3D d’une carte 2D à l’aide du raycasting. |
| **Déplacement du joueur** | Se déplace avec `W`, `A`, `S`, `D` et pivote avec `←` et `→`. |
| **Textures** | Différentes textures de mur selon la direction (`NO`, `SO`, `WE`, `EA`). |
| **Couleurs** | Couleurs personnalisées pour le sol (`F`) et le plafond (`C`) au format RGB. |
| **Analyse du fichier .cub** | Lecture et validation d’un fichier `.cub` définissant textures, couleurs et carte. |
| **Gestion de la fenêtre** | Ouverture, fermeture et rafraîchissement fluides (touche `ESC` ou croix rouge). |
| **Gestion des erreurs** | Fermeture propre avec messages d’erreur clairs en cas de configuration invalide. |

---

## 📂 Exemple de fichier `.cub`
```cub
    NO ./textures/north.xpm
    SO ./textures/south.xpm
    F 220,100,0
    C 225,30,0
    WE ./textures/west.xpm
    EA ./textures/east.xpm
    1111111111111111111111111
    1000000000110000000000001
    1011000001110000000000001
    1001000000000000000000001
    111111111011000001110000000000001
    100000000011000001110111111111111
    11110111111111011100000000001
    11110111111111011101010010001
    11000000110101011100000010001
    10000000000000001100000010001
    10000000000000001101010010001
    11000001110101011111011110N0111
    11110111 1110101 101111010001
    11111111 1111111 111111111111
```

---

## 🧩 Bonus implémentés
Les bonus ne sont évalués que si la partie obligatoire est **entièrement fonctionnelle**.  
Nous avons choisi d’implémenter les bonus suivants :

| Fonctionnalité Bonus | Description |
|-----------------------|-------------|
| **Collision avec les murs** | Empêche le joueur de traverser les murs. Le déplacement vérifie les collisions sur la carte en temps réel. |
| **Déplacement avec la souris** | Permet de faire pivoter la caméra avec les mouvements de la souris pour un contrôle plus fluide et naturel. |
| **Minimap avec champ de vision** | Affiche une mini-carte 2D indiquant la position du joueur, les murs, et un cône de vision dynamique. |

Ces ajouts renforcent l’immersion et rendent l’expérience plus réaliste, proche d’un véritable jeu de type FPS.

---

## 🛠️ Détails techniques

### 🔹 Langage et outils
- **Langage :** C
- **Bibliothèque graphique :** MiniLibX
