# MATh en JEANS 2021-2022 : Traceur-Briseur
##Description
Programme réalisé sur l'année scolaire 2021-2022 dans le cadre du [projet MATh en JEANS](https://www.mathenjeans.fr) sur [le sujet du "Traceur-Briseur"](https://www.mathenjeans.fr/content/lycee-rene-perrin-ugine-2021-2022).

## Le sujet
"Pour jouer au jeu nous avons besoin d'un certain nombre *L* de lignes, chacune ayant le même nombre *p* de points. Deux joueurs, traceur et briseur, colorient chacun leur tour un point. Quand un pont a été colorié il ne change plus de couleur le long de la partie. Le but du traceur est de colorier tous les points d'une ligne, le but du briseur est que le traceur ne réussisse pas son objectif. Y a-t-il un des deux joueurs qui a une stratégie gagnante ? Cela dépend-t-il du nombre de lignes ? Du joueur qui commence ? De la configuration ?"

## Objectif du programme
Le but du programme est d'être mis à disposition des personnes travaillant sur le sujet.

## Adaptation informatique
### Grille
J'ai choisi le langage C, sans librairies, pour pouvoir m'entraîner sur celui-ci. J'ai donc subi quelques difficultées / restrictions dans mon projet. 
<br> Premièrement j'ai modéliser le système de lignes et de points par des grilles à la façon de matrices. J'ai fait en sorte que ce système puisse être réutiliser pour d'autres projets.
```text
---
Grille de depart
Taille : 3x3
0  0  0
0  0  0
0  0  0
---
```
* Un point libre est représenté par un `0`.
* Un point placé par le traceur définit par "attaquant" dans le code est représenté par un `1`.
* Un point placé par le briseur définit par "défenseur" dans le code est représenté par un `2`.
* Un point vide qui ne peut pas être joué et ne sera pas affiché est représenté par un `3`.
<br>*cf.* `ia.h`
### IA
J'ai donc voulu faire en sorte que n'importe qui puisse se battre contre un robot que définit par "IA" (***I**ntelligence **A**rtificielle, même si ça n'en n'est pas une à proprement parlé*).

Elle fonctionne de cette façon : 
* Vérification des lignes et colonnes prioritaires (*Exemple : si une ligne est attaquée par deux points, la défense va être prioritaire sur cette ligne par rapport à une ligne qui n'est qu'attaquée que d'un point*).
* Placement de la ligne/colonne/diagonnale (*en développement*) prioritaire.