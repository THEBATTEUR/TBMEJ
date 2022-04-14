//
// Created by nicom on 18/11/2021.
//

#ifndef RM_IA_H
#define RM_IA_H

#include "grid/grid.h"

/**
 * Énuméraion du role de l'IA
 */
typedef enum Role Role;
enum Role {
    R_NULL = 0, ATTAQUANT = COLOR_A, BRISEUR = COLOR_B
};

/**
 * Énumération pour les différents paramètres de la grille
 * <br>-> En développement
 */
typedef enum GFlag GFlag;
enum GFlag {
    LINE = 0, COL = 1, DIAG = 2
};

/**
 * Docu des fonctions dans ia.c
 */
int isColAttacked(const Grid* grid, int x);
int isColCountered(const Grid* grid, int x);
int isColWin(const Grid* grid, int x);
int getNbOfAttacksPerCol(const Grid* grid, int x);
int getNbOfCounterPerCol(const Grid* grid, int x);


int isLineAttacked(const Grid* grid, int y);
int isLineCountered(const Grid* grid, int y);
int isLineWin(const Grid* grid, int y);
int getNbOfAttacksPerLine(const Grid* grid, int y);
int getNbOfCounterPerLine(const Grid* grid, int y);

int isDiagAttacked(const Grid* grid, int x, int y);
int isDiagCountered(const Grid* grid, int x, int y);
int isDiagWin(const Grid* grid, int x, int y);
int getNbOfAttacksPerDiag(const Grid* grid, int x, int y);
int getNbOfCounterPerDiag(const Grid* grid, int x, int y);

int isGameEnded(const Grid* grid);
Role getWinner(const Grid* grid);

void playAttack(const Grid* grid, GFlag flags);
void playCounter(const Grid* grid, GFlag flags);

#endif //RM_IA_H
