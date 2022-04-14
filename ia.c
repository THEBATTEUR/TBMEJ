//
// Created by nicom on 18/11/2021.
//

#include "ia.h"
#include <stdio.h>

/**
 * Permet de vérifier si une colonne est attaquée
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : 0 si non, 1 si oui
 */
int isColAttacked(const Grid* grid, int x) {
    int posX = 0, posY = 0, i = 0;
    for (i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && grid->list[i] == COLOR_A)
            return 1;
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
    return 0;
}
/**
 * Permet de vérifier si une colonne est brisée
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : 0 si non, 1 si oui
 */
int isColCountered(const Grid* grid, int x) {
    int posX = 0, posY = 0, i = 0;
    for (i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && grid->list[i] == COLOR_B)
            return 1;
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
    return 0;
}
/**
 * Permet de vérifier si une colonne est gagnée par l'attaquant
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : 0 si non, 1 si oui
 */
int isColWin(const Grid* grid, int x) {
    int posX = 0, posY = 0, i = 0, nbOfPlayingPoints = 0;
    for (i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && grid->list[i] != NON_EXISTING)
            ++nbOfPlayingPoints;
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
    return getNbOfAttacksPerCol(grid, x) == nbOfPlayingPoints && nbOfPlayingPoints != 0;
}
/**
 * Permet d'obtenir le nombre d'attaques par colonnes
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : nombre d'attaques
 */
int getNbOfAttacksPerCol(const Grid* grid, int x) {
    int posX = 0, posY = 0, i = 0, attacks = 0;
    for (i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && grid->list[i] == COLOR_A)
            ++attacks;
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
    return attacks;
}
/**
 * Permet d'obtenir le nombre de brisages par colonnes
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : nombres de brisages
 */
int getNbOfCounterPerCol(const Grid* grid, int x) {
    int posX = 0, posY = 0, i = 0, counters = 0;
    for (i = 0; i < (grid->size*grid->size); ++i) {
        if(posX == x && grid->list[i] == COLOR_A)
            ++counters;
        ++posX;
        if((i+1) % grid->size == 0) {
            posX = 0;
            ++posY;
        }
    }
    return counters;
}

/**
 * Permet de vérifier si une ligne est attaquée
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : 0 si non, 1 si oui
 */
int isLineAttacked(const Grid* grid, int y) {
    for (int i = grid->size*y; i < ((grid->size*y)+grid->size); ++i) {
        if (grid->list[i] == COLOR_A)
            return 1;
    }
    return 0;
}
/**
 * Permet de vérifier si une ligne est brisée
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : 0 si non, 1 si oui
 */
int isLineCountered(const Grid* grid, int y) {
    for (int i = grid->size*y; i < ((grid->size*y)+grid->size); ++i) {
        if (grid->list[i] == COLOR_B)
            return 1;
    }
    return 0;
}
/**
 * Permet de vérifier si une ligne est gagnée par l'attaquant
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : 0 si non, 1 si oui
 */
int isLineWin(const Grid* grid, int y) {
    int nbOfPlayingPoints = 0;
    for (int i = grid->size*y; i < ((grid->size*y)+grid->size); ++i) {
        if (grid->list[i] != NON_EXISTING)
            ++nbOfPlayingPoints;
    }
    return getNbOfAttacksPerLine(grid, y) == nbOfPlayingPoints && nbOfPlayingPoints != 0;
}
/**
 * Permet d'obtenir le nombre d'attaques par lignes
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : nombre d'attaques
 */
int getNbOfAttacksPerLine(const Grid* grid, int y) {
    int attacks = 0, i = 0;
    for (i = grid->size*y; i < ((grid->size*y)+grid->size); ++i) {
        if (grid->list[i] == COLOR_A)
            ++attacks;
    }
    return attacks;
}
/**
 * Permet d'obtenir le nombre de brisages par lignes
 * @param grid : grille à vérifier
 * @param x : numéro de la colonne
 * @return int : nombre d'attaques
 */
int getNbOfCounterPerLine(const Grid* grid, int y) {
    int counters = 0, i = 0;
    for (i = grid->size*y; i < ((grid->size*y)+grid->size); ++i) {
        if (grid->list[i] == COLOR_B)
            ++counters;
    }
    return counters;
}

/**
 * Permet de vérifier si une diagonale est attaquée
 * @param grid : grille à vérifier
 * @param x : abcisse du point de la diagonale
 * @param y : ordonnée du point de la diagonale
 * @return int : 0 si non ; 1 si oui
 */
int isDiagAttacked(const Grid* grid, int x, int y) {
    if (x == 0 || (float) (grid->size) / 2 > (float) x) {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //Oo
            //oo
            for (int i = x, j = y; i < grid->size && j < grid->size; ++i) {
                if (isPointAttacked(grid, i, j))
                    return 1;
                ++j;
            }
        } else {
            //oo
            //Oo
            for (int i = x, j = y; i < grid->size && j >= 0; ++i) {
                if (isPointAttacked(grid, i, j))
                    return 1;
                --j;
            }
        }
    } else {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //oO
            //oo
            for (int i = x, j = y; i >= 0 && j < grid->size; --i) {
                if (isPointAttacked(grid, i, j))
                    return 1;
                ++j;
            }
        } else {
            //oo
            //oO
            for (int i = x, j = y; i >= 0 && j >= 0; --i) {
                if (isPointAttacked(grid, i, j))
                    return 1;
                --j;
            }
        }
    }
    //Case: desc
    /*for (int i = x, j = y; i != grid->size && j != grid->size; ++i) {
        if (isPointAttacked(grid, i, j))
            return 1;
        ++j;
    }*/
    return 0;
}

/**
 * Permet de vérifier si une diagonale est brisée
 * @param grid : grille à vérifier
 * @param x : abcisse du point de la diagonale
 * @param y : ordonnée du point de la diagonale
 * @return int : 0 si non ; 1 si oui
 */
int isDiagCountered(const Grid* grid, int x, int y) {
    if (x == 0 || (float) (grid->size) / 2 > (float) x) {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //Oo
            //oo
            for (int i = x, j = y; i < grid->size && j < grid->size; ++i) {
                if (isPointCountered(grid, i, j))
                    return 1;
                ++j;
            }
        } else {
            //oo
            //Oo
            for (int i = x, j = y; i < grid->size && j >= 0; ++i) {
                if (isPointCountered(grid, i, j))
                    return 1;
                --j;
            }
        }
    } else {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //oO
            //oo
            for (int i = x, j = y; i >= 0 && j < grid->size; --i) {
                if (isPointCountered(grid, i, j))
                    return 1;
                ++j;
            }
        } else {
            //oo
            //oO
            for (int i = x, j = y; i >= 0 && j >= 0; --i) {
                if (isPointCountered(grid, i, j))
                    return 1;
                --j;
            }
        }
    }
    return 0;
}

/**
 * Permet de vérifier si une diagonale est gagnée
 * @param grid : grille à vérifier
 * @param x : abcisse du point de la diagonale
 * @param y : ordonnée du point de la diagonale
 * @return int : 0 si non ; 1 si oui
 */
int isDiagWin(const Grid* grid, int x, int y) {
    if (x == 0 || (float) (grid->size) / 2 > (float) x) {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //Oo
            //oo
            for (int i = x, j = y; i < grid->size && j < grid->size; ++i) {
                if (!isPointAttacked(grid, i, j))
                    return 0;
                ++j;
            }
        } else {
            //oo
            //Oo
            for (int i = x, j = y; i < grid->size && j >= 0; ++i) {
                if (!isPointAttacked(grid, i, j))
                    return 0;
                --j;
            }
        }
    } else {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //oO
            //oo
            for (int i = x, j = y; i >= 0 && j < grid->size; --i) {
                if (!isPointAttacked(grid, i, j))
                    return 0;
                ++j;
            }
        } else {
            //oo
            //oO
            for (int i = x, j = y; i >= 0 && j >= 0; --i) {
                if (!isPointAttacked(grid, i, j))
                    return 0;
                --j;
            }
        }
    }
    return 1;
}
/**
 * Permet de d'obtenir le nombre d'attaque pour une diagonale
 * @param grid : grille à vérifier
 * @param x : abcisse du point de la diagonale
 * @param y : ordonnée du point de la diagonale
 * @return int : nombre d'attaques
 */
int getNbOfAttacksPerDiag(const Grid* grid, int x, int y) {
    int number = 0;
    if (x == 0 || (float) (grid->size) / 2 > (float) x) {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //Oo
            //oo
            for (int i = x, j = y; i < grid->size && j < grid->size; ++i) {
                if (isPointAttacked(grid, i, j))
                    ++number;
                ++j;
            }
        } else {
            //oo
            //Oo
            for (int i = x, j = y; i < grid->size && j >= 0; ++i) {
                if (isPointAttacked(grid, i, j))
                    ++number;
                --j;
            }
        }
    } else {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //oO
            //oo
            for (int i = x, j = y; i >= 0 && j < grid->size; --i) {
                if (isPointAttacked(grid, i, j))
                    ++number;
                ++j;
            }
        } else {
            //oo
            //oO
            for (int i = x, j = y; i >= 0 && j >= 0; --i) {
                if (isPointAttacked(grid, i, j))
                    ++number;
                --j;
            }
        }
    }
    return number;
}
/**
 * Permet de d'obtenir le nombre de brisage pour une diagonale
 * @param grid : grille à vérifier
 * @param x : abcisse du point de la diagonale
 * @param y : ordonnée du point de la diagonale
 * @return int : nombres de brisage
 */
int getNbOfCounterPerDiag(const Grid* grid, int x, int y) {
    int number = 0;
    if (x == 0 || (float) (grid->size) / 2 > (float) x) {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //Oo
            //oo
            for (int i = x, j = y; i < grid->size && j < grid->size; ++i) {
                if (isPointCountered(grid, i, j))
                    ++number;
                ++j;
            }
        } else {
            //oo
            //Oo
            for (int i = x, j = y; i < grid->size && j >= 0; ++i) {
                if (isPointCountered(grid, i, j))
                    ++number;
                --j;
            }
        }
    } else {
        if (y == 0 || (float) grid->size / 2 > (float) y) {
            //oO
            //oo
            for (int i = x, j = y; i >= 0 && j < grid->size; --i) {
                if (isPointCountered(grid, i, j))
                    ++number;
                ++j;
            }
        } else {
            //oo
            //oO
            for (int i = x, j = y; i >= 0 && j >= 0; --i) {
                if (isPointCountered(grid, i, j))
                    ++number;
                --j;
            }
        }
    }
    return number;
}

/**
 * Permet de vérifier si la partie est finie
 * @param grid : grille à vérifier
 * @return int : 0 si non, 1 si oui
 */
int isGameEnded(const Grid* grid) {
    int ended = 1, i = 0;
    for (i = 0; i < grid->size; ++i) {
        for (int j = 0; j < grid->size; ++j) {
            if (!isPointPlayed(grid, i, j) && getStatus(grid, i, j) != NON_EXISTING)
                ended = 0;
        }
    }
    return ended;
}
/**
 * Permet d'obtenir le gagnant d'un partie
 * @param grid : grille à vérifier
 * @return Role : le gagnant
 */
Role getWinner(const Grid* grid) {
    Role winner = R_NULL;
    if (isGameEnded(grid))
        winner = BRISEUR;
    for (int i = 0; i < grid->size; ++i) {
        if (isLineWin(grid, i) || isColWin(grid, i)/* || isDiagWin(grid, i, i)*/) {
            winner = ATTAQUANT;
        }
    }
    return winner;
}

/**
 * IA - Partie attaque
 * @param grid : grille à jouer
 * @param diag : boolean - prise en compte des diagonales
 */
void playAttack(const Grid* grid, GFlag flags) {
    printf("L'attaque joue\n");
    int priorityLevelCol = 0, priorityPosCol = 0, priorityLevelLine = 0, priorityPosLine = 0, priorityLevelDiag = 0,
    priorityPosDiag, i = 0;
    for (i = 0; i < grid->size; ++i) {
        if (isColAttacked(grid, i) && !isColCountered(grid, i)) {
            if (getNbOfAttacksPerCol(grid, i) >= priorityLevelCol) {
                priorityLevelCol = getNbOfAttacksPerCol(grid, i);
                priorityPosCol = i;
            }
        }
        if (isLineAttacked(grid, i) && !isLineCountered(grid, i)) {
            if (getNbOfAttacksPerLine(grid, i) >= priorityLevelLine) {
                priorityLevelLine = getNbOfAttacksPerLine(grid, i);
                priorityPosLine = i;
            }
        }
    }
    if (flags == DIAG) {
        for (i = 0; i < grid->size; i+=grid->size-2) { //TODO tester
            if (isDiagAttacked(grid, i, i) && !isDiagCountered(grid, i, i)) {
                if (getNbOfAttacksPerDiag(grid, i, i) >= priorityLevelDiag) {
                    priorityLevelDiag = getNbOfAttacksPerDiag(grid, i, i);
                    priorityPosDiag = i;
                }
            }
        }
    }
    if (priorityLevelCol >= priorityLevelLine  && (priorityLevelLine > 0 || priorityLevelCol > 0)) {
        printf("Priorite a la colonne %d\n", priorityLevelCol);
        for (i = 0; i < grid->size; ++i) {
            if (!isPointPlayed(grid, priorityPosCol, i) && getStatus(grid, priorityPosCol, i) != NON_EXISTING) {
                placer_point(grid, priorityPosCol, i, COLOR_A);
                return;
            }
        }
    } else if(priorityLevelLine >= priorityLevelCol && (priorityLevelLine > 0 || priorityLevelCol > 0)) {
        printf("Priorite a la ligne %d\n", priorityPosLine);
        for (i = 0; i < grid->size; ++i) {
            if (!isPointPlayed(grid, i, priorityPosLine) && getStatus(grid, i, priorityPosLine) != NON_EXISTING) {
                placer_point(grid, i, priorityPosLine, COLOR_A);
                return;
            }
        }
    } else if (flags == DIAG && priorityLevelDiag >= priorityLevelCol && priorityLevelDiag >= priorityLevelLine
    && (priorityLevelLine > 0 || priorityLevelCol > 0 || priorityLevelDiag > 0)) {
        printf("Priorite a la diagonale %d ; %d\n", priorityLevelDiag, priorityPosDiag);
        /*for (i = 0; i < grid->size; ++i) {

        }*/
    } else {
        printf("Aucune priorite\n");
        for (i = 0; i < grid->size; ++i) {
            for (int j = 0; j < grid->size; ++j) {
                if(!isColCountered(grid, i) && !isLineCountered(grid, j) && !isPointPlayed(grid, i, j)  && getStatus(grid, i, j) != NON_EXISTING) {
                    placer_point(grid, i, j, COLOR_A);
                    return;
                }
            }
        }
        for (i = 0; i < grid->size; ++i) {
            for (int j = 0; j < grid->size; ++j) {
                if(!isPointPlayed(grid, i, j) && getStatus(grid, i, j) != NON_EXISTING) {
                    placer_point(grid, i, j, COLOR_A);
                    return;
                }
            }
        }

    }
}
/**
 * IA - Partie défense
 * @param grid : grille à jouer
 */
void playCounter(const Grid* grid, GFlag flags) {
    printf("La defense joue\n");
    int priorityLevelCol = 0, priorityPosCol = 0, priorityLevelLine = 0, priorityPosLine = 0, priorityLevelDiag = 0,
            priorityPosDiag, i = 0;
    for (i = 0; i < grid->size; ++i) {
        if (isColAttacked(grid, i) && !isColCountered(grid, i)) {
            if (getNbOfAttacksPerCol(grid, i) >= priorityLevelCol) {
                priorityLevelCol = getNbOfAttacksPerCol(grid, i);
                priorityPosCol = i;
            }
        }
        if (isLineAttacked(grid, i) && !isLineCountered(grid, i)) {
            if (getNbOfAttacksPerLine(grid, i) >= priorityLevelLine) {
                priorityLevelLine = getNbOfAttacksPerLine(grid, i);
                priorityPosLine = i;
            }
        }
    }
    if (flags == DIAG) {
        for (i = 0; i < grid->size; i += grid->size-2) { //TODO tester
            if (isDiagAttacked(grid, i, i) && !isDiagCountered(grid, i, i)) {
                if (getNbOfAttacksPerLine(grid, i) >= priorityLevelLine) {
                    priorityLevelDiag = getNbOfAttacksPerLine(grid, i);
                    priorityPosDiag = i;
                }
            }
        }
    }
    if (priorityLevelCol >= priorityLevelLine  && (priorityLevelLine > 0 || priorityLevelCol > 0)) {
        printf("Priorite a la colonne %d\n", priorityPosCol);
        for (i = 0; i < grid->size; ++i) {
            if (!isPointPlayed(grid, priorityPosCol, i) && getStatus(grid, priorityPosCol, i) != NON_EXISTING) {
                placer_point(grid, priorityPosCol, i, COLOR_B);
                return;
            }
        }
    } else if(priorityLevelLine >= priorityLevelCol && (priorityLevelLine > 0 || priorityLevelCol > 0)) {
        printf("Priorite a la ligne %d\n", priorityPosLine);
        for (i = 0; i < grid->size; ++i) {
            if (!isPointPlayed(grid, i, priorityPosLine) && getStatus(grid, i, priorityPosLine) != NON_EXISTING) {
                placer_point(grid, i, priorityPosLine, COLOR_B);
                return;
            }
        }
    } else {
        printf("Aucune priorite\n");
        for (i = 0; i < grid->size; ++i) {
            for (int j = 0; j < grid->size; ++j) {
                if(!isPointPlayed(grid, i, j) && getStatus(grid, i, j) != NON_EXISTING) {
                    placer_point(grid, i, j, COLOR_B);
                    return;
                }
            }
        }
    }
}
