//
// Created by nicom on 18/11/2021.
//

#include "grid.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Constructeur de la structure Grid (pour allocation dynamique)
 * @param size : taille de la grille (size*size)
 * @return La grille prête à l'emploi
 */
Grid construct_grid(int size) {
    int* tableau = NULL;
    tableau = malloc(size*size*sizeof(int));
    for (int i = 0; i < (size*size); ++i) {
        tableau[i] = EMPTY;
    }
    Grid grid = {size, tableau};
    return grid;
}

/**
 * Déconstructeur de la structure Grid (pour free valeur)
 * @param grid : la grille à déconstruire
 */
void deconstruct_grid(const Grid* grid) {
    free(grid->list);
}

/**
 * Affiche une grille
 * @param grid : La grille à afficher
 */
void print_grid(const Grid* grid) {
    for (int i = 0; i < (grid->size*grid->size); ++i) {
        if (grid->list[i] == NON_EXISTING)
            printf("   ");
        else
            printf("%d  ", grid->list[i]);
        if((i+1) % grid->size == 0)
            printf("\n");
    }
}


/**
 * Modifie un point sur la grille
 * @param grid : la grille à affecter
 * @param x : abscisse du point
 * @param y : ordonnée du point
 * @param status : type du point
 */
void placer_point(const Grid* grid, int x, int y, PointStatus status) {
    int posX = 0, posY = 0;
    for (int i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && posY == y && grid->list[i] == 0) {
            grid->list[i] = status;
            return;
        }
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
}

/**
 * Vérifie si un point est attaqué
 * @param grid : la grille à vérifier
 * @param x : abscisse du point à vérifier
 * @param y : ordonnée du point à vérifier
 * @return int : 0 si non, 1 si oui
 */
int isPointAttacked(const Grid* grid, int x, int y) {
    int posX = 0, posY = 0;
    for (int i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && posY == y)
            return grid->list[i] == COLOR_A;
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
    return 0;
}
/**
 * Vérifie si un point est brisé
 * @param grid : la grille à vérifier
 * @param x : abscisse du point à vérifier
 * @param y : ordonnée du point à vérifier
 * @return int : 0 si non, 1 si oui
 */
int isPointCountered(const Grid* grid, int x, int y) {
    int posX = 0, posY = 0;
    for (int i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && posY == y)
            return grid->list[i] == COLOR_B;
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
    return 0;
}
/**
 * Vérifie si un point est joué par n'importe quelle équipe
 * @param grid : la grille à vérifier
 * @param x : abscisse du point à vérifier
 * @param y : ordonnée du point à vérifier
 * @return int : 0 si non, 1 si oui
 */
int isPointPlayed(const Grid* grid, int x, int y) {
    int posX = 0, posY = 0;
    for (int i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && posY == y)
            return grid->list[i] != EMPTY;
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
    return 0;
}

/**
 * Permet d'obtenir le status d'un point
 * @param grid : la grille à vérifier
 * @param x : l'abcisse du point
 * @param y l'ordonnée du point
 * @return PointStatus : le statut du point
 */
PointStatus getStatus(const Grid* grid, int x, int y) {
    int posX = 0, posY = 0;
    for (int i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && posY == y)
            return grid->list[i];
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
    return P_NULL;
}


