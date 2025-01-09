# Rapport S1.01 - Jeu Pac-Man

## Auteurs
**Ben Gadha Imen, Hernandez Loïc, Mekidiche Idris, Ratiananahary Karmen, Ribbe Jules**  
**Groupe 1**

**Github : https://github.com/PGP667/S1.01**

---

## Sommaire
1. [Introduction](#introduction)
2. [Début du Projet](#début-du-projet)
3. [Utilisation de la Bibliothèque MinGL 2](#utilisation-de-la-bibliothèque-mingl-2)
4. [Fonctionnalités du Jeu](#fonctionnalités-du-jeu)
   - [Modélisation de la Map](#modélisation-de-la-map)
   - [Déplacement de Pac-Man](#déplacement-de-pac-man)
   - [Comportement des Fantômes](#comportement-des-fantômes)
   - [Conditions de Victoire et de Défaite](#conditions-de-victoire-et-de-défaite)
5. [Structures et Fonctions Principales](#structures-et-fonctions-principales)
6. [Conclusion](#conclusion)

---

## Introduction

Dans le cadre de ce projet, nous avons conçu une version simplifiée de **Pac-Man**, intégrée au système "voleur/contrebandier".  
Nous avons adopté un **dépôt Git partagé** pour une collaboration efficace, facilitant la synchronisation des contributions de chaque membre via des commandes `pull` et `push`. Cela nous a permis de maintenir une organisation structurée et un suivi clair des modifications.

---

## Début du Projet

Le projet a débuté par une approche textuelle dans le terminal.  
- **Représentation de la map** : Matrice de vecteurs permettant de gérer les éléments tels que les murs, les points et les fantômes.  
- **Premières étapes** : Développement d’une version basique avec des contrôles simples pour Pac-Man et des comportements aléatoires pour les fantômes.  

Après validation de la logique de base, nous avons intégré des graphismes avec la bibliothèque **MinGL 2**. Cette étape a nécessité :  
- L’introduction de téléporteurs pour relier les zones de la map.  
- Une synchronisation des déplacements entre Pac-Man et les fantômes.  

Pour garantir la qualité du code et documenter nos travaux, nous avons utilisé **Doxygen**.

---

## Utilisation de la Bibliothèque MinGL 2

**MinGL 2** nous a permis d’introduire des éléments graphiques et sonores pour rendre le jeu plus immersif. Les fonctionnalités clés exploitées incluent :  
- **Formes géométriques** : Utilisation de la classe `Circle` pour dessiner Pac-Man et les fantômes.  
- **Affichage de texte** : Score du joueur et messages de jeu via la classe `Texte`.  
- **Contrôles clavier/souris** : Déplacements de Pac-Man grâce à `Clavier` et `Souris`.  
- **Animations et transitions** : Fluidité des mouvements et animations des personnages.  
- **Audio** : Effets sonores (manger un point, attraper un fantôme) et musique de fond.  

---

## Fonctionnalités du Jeu

### Modélisation de la Map
- **Structure** : Map représentée sous forme de matrice, où chaque case correspond à un élément (mur, point, gomme, etc.).  
- **Design** : Les couleurs et la structure respectent le style du jeu Pac-Man original.

### Déplacement de Pac-Man
- Pac-Man peut se déplacer dans 4 directions : haut, bas, gauche, droite.  
- **Règles** :  
  - Les murs sont infranchissables.  
  - Les téléporteurs déplacent Pac-Man de l’autre côté de la map.  
  - Les points et gommes augmentent le score lorsqu’ils sont mangés.  

### Comportement des Fantômes
- Déplacements semi-aléatoires avec des contraintes :  
  - Les fantômes évitent de revenir sur leurs pas.  
  - Lorsqu’une gomme est mangée, ils deviennent vulnérables temporairement.  
  - Après une élimination, ils réapparaissent à leur position initiale après un délai.  

### Conditions de Victoire et de Défaite
- **Victoire** : Pac-Man mange tous les points et gommes de la map.  
- **Défaite** : Collision entre Pac-Man et un fantôme non vulnérable.

---

## Structures et Fonctions Principales

### Structures
- **CPosition** : Représente une coordonnée sur la map (ligne, colonne).  
- **CDirection** : Définit une direction de déplacement (verticale et horizontale).  
- **struct pacman** : Contient la position et la direction du joueur.  
- **Token**: Caractère représentant le fantôme.
- **TokenUnder** Caractère que le fantôme remplace temporairement lorsqu’il se déplace sur une case.
- **Cooldown** Compteur qui détermine quand est ce que le fantôme doit se déplacer ou effectuer une action en particulier. 

### Fonctions
- **clearScreen()** : Efface le terminal pour un affichage propre.  
- **showMatrix()** : Affiche la map et les éléments du jeu.  
- **movePlayer()** : Gère les déplacements de Pac-Man et les interactions avec la map.  
- **initMat()** : Initialise la map, place Pac-Man et les fantômes, et configure le niveau.  
- **moveRandom()** : Déplace les fantômes aléatoirement tout en respectant les obstacles.

---

## Conclusion

Ce projet nous a permis de :  
1. **Renforcer nos compétences en C++**, notamment en structuration et gestion de projets collaboratifs.  
2. **Apprendre à utiliser une bibliothèque graphique** (MinGL 2) pour enrichir l’expérience utilisateur.  
3. **Collaborer efficacement en équipe**, en appliquant des méthodologies agiles et en exploitant des outils comme Git.  

Nous avons développé une version fonctionnelle de Pac-Man, posant les bases pour des projets encore plus ambitieux à l’avenir.
