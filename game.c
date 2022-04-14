//
// Created by nicom on 22/11/2021.
//

#include "game.h"
#include <stdio.h>
#include "grid/grid.h"
#include "ia.h"

/**
 * Joue une partie d'IA (attaquant) contre IA (défense)
 * @param grid : grille à jouer
 */
void IAvsIA(const Grid* grid) {
    printf("---\nGrille de depart\nTaille : %dx%d\n", grid->size, grid->size);
    print_grid(grid);
    printf("---\n");
    while (!isGameEnded(grid) && getWinner(grid) == R_NULL) {
        playAttack(grid, LINE | COL);
        print_grid(grid);
        printf("---\n");
        if (isGameEnded(grid) || getWinner(grid) != R_NULL) break;
        playCounter(grid, LINE | COL);
        print_grid(grid);
        printf("---\n");
    }
    if (getWinner(grid) == ATTAQUANT)
        printf("L'attaquant a gagne !\n");
    else if(getWinner(grid) == BRISEUR)
        printf("La defense a gagne !\n");
}
/**
 * Joue une partie de joueur (attaquant) contre IA (défense)
 * @param grid : grille à jouer
 */
void PvsIA(const Grid* grid) {
    printf("---\nGrille de depart\nTaille : %dx%d\n", grid->size, grid->size);
    print_grid(grid);
    printf("---\n");
    while (!isGameEnded(grid) && getWinner(grid) == R_NULL) {
        printf("Au tour de l'attaque\n");
        int inputX = 0, inputY = 0;
        printf("Entrez la colonne (x) entre %d et %d : ", 0, grid->size-1);
        scanf("%d", &inputX);
        printf("\nEntrez la ligne (y) entre %d et %d : ", 0, grid->size-1);
        scanf("%d", &inputY);
        printf("\n");
        placer_point(grid, inputX, inputY, COLOR_A);
        print_grid(grid);
        printf("---\n");
        if (isGameEnded(grid) || getWinner(grid) != R_NULL) break;
        playCounter(grid, LINE | COL);
        print_grid(grid);
        printf("---\n");
    }
    if (getWinner(grid) == ATTAQUANT)
        printf("L'attaquant a gagne !\n");
    else if(getWinner(grid) == BRISEUR)
        printf("La defense a gagne !\n");
}
/**
 * Joue une partie d'IA (attaquant) contre joueur (défense)
 * @param grid : grille à jouer
 */
void IAvsP(const Grid* grid) {
    printf("---\nGrille de depart\nTaille : %dx%d\n", grid->size, grid->size);
    print_grid(grid);
    printf("---\n");
    while (!isGameEnded(grid) && getWinner(grid) == R_NULL) {
        playAttack(grid, LINE | COL);
        print_grid(grid);
        printf("---\n");
        if (isGameEnded(grid) || getWinner(grid) != R_NULL) break;
        printf("Au tour de la defense\n");
        int inputX = 0, inputY = 0;
        printf("Entrez la colonne (x) entre %d et %d : ", 0, grid->size-1);
        scanf("%d", &inputX);
        printf("\nEntrez la ligne (y) entre %d et %d : ", 0, grid->size-1);
        scanf("%d", &inputY);
        printf("\n");
        placer_point(grid, inputX, inputY, COLOR_B);
        print_grid(grid);
        printf("---\n");
    }
    if (getWinner(grid) == ATTAQUANT)
        printf("L'attaquant a gagne !\n");
    else if(getWinner(grid) == BRISEUR)
        printf("La defense a gagne !\n");
}
/**
 * Joue une partie de joueur (attaquant) contre joueur (défense)
 * @param grid : grille à jouer
 */
void PvsP(const Grid* grid) {
    printf("---\nGrille de depart\nTaille : %dx%d\n", grid->size, grid->size);
    print_grid(grid);
    printf("---\n");
    while (!isGameEnded(grid) && getWinner(grid) == R_NULL) {
        printf("Au tour de l'attaque\n");
        int inputX = 0, inputY = 0;
        printf("Entrez la colonne (x) entre %d et %d : ", 0, grid->size-1);
        scanf("%d", &inputX);
        printf("\nEntrez la ligne (y) entre %d et %d : ", 0, grid->size-1);
        scanf("%d", &inputY);
        printf("\n");
        placer_point(grid, inputX, inputY, COLOR_A);
        print_grid(grid);
        printf("---\n");
        if (isGameEnded(grid) || getWinner(grid) != R_NULL) break;
        printf("Au tour de la defense\n");
        printf("Entrez la colonne (x) entre %d et %d : ", 0, grid->size-1);
        scanf("%d", &inputX);
        printf("\nEntrez la ligne (y) entre %d et %d : ", 0, grid->size-1);
        scanf("%d", &inputY);
        printf("\n");
        placer_point(grid, inputX, inputY, COLOR_B);
        print_grid(grid);
        printf("---\n");
    }
    if (getWinner(grid) == ATTAQUANT)
        printf("L'attaquant a gagne !\n");
    else if(getWinner(grid) == BRISEUR)
        printf("La defense a gagne !\n");
}

/**
 * Fait jouer les IA en commançant par l'attaque, en testant tous les premiers placement possible
 * @param size : taille de la grille
 */
void testAll(int size) {
    int posX = 0, posY = 0, i = 0;
    for (i = 0; i < (size*size); ++i) {
        printf("==========[ Nouvelle partie ]==========\n");
        Grid grid = construct_grid(size);
        placer_point(&grid, posX, posY, COLOR_A);
        printf("---\nGrille de depart\nTaille : %dx%d\n", size, size);
        print_grid(&grid);
        printf("---\n");
        while (!isGameEnded(&grid) && getWinner(&grid) == R_NULL) {
            playCounter(&grid, LINE | COL);
            print_grid(&grid);
            printf("---\n");
            if (isGameEnded(&grid) || getWinner(&grid) != R_NULL) break;
            playAttack(&grid, LINE | COL);
            print_grid(&grid);
            printf("---\n");
        }
        if (getWinner(&grid) == ATTAQUANT)
            printf("L'attaquant a gagne !\n");
        else if(getWinner(&grid) == BRISEUR)
            printf("La defense a gagne !\n");
        deconstruct_grid(&grid);
        ++posX;
        if((i+1) % size == 0) {
            posX = 0;
            ++posY;
        }
    }
}

void forceBrut(int size) {

}