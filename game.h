//
// Created by nicom on 22/11/2021.
//

#ifndef RM_GAME_H
#define RM_GAME_H
#include "grid/grid.h"

/**
 * À gauche l'attaquant, à droite le défenseur
 * docu des fonctions dans game.c
 */
void IAvsIA(const Grid* grid);
void PvsIA(const Grid* grid);
void IAvsP(const Grid* grid);
void PvsP(const Grid* grid);
void testAll(int size);

#endif //RM_GAME_H
