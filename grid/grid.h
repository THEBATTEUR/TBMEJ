//
// Created by nicom on 18/11/2021.
//nhj

#ifndef RM_GRID_H
#define RM_GRID_H

/**
 * structure de la grille avec une taille (size*size) et un pointeur
 * vers un tableau
 *
 * à initialiser avec la fonction construct_grid()
 */

typedef struct Grid Grid;
struct Grid {
    int size;
    int* list;
};

/**
 * énumération des différents types de points sur la grille
 */
typedef enum PointStatus PointStatus;
enum PointStatus {
    P_NULL = -1, EMPTY = 0, COLOR_A = 1, COLOR_B = 2, NON_EXISTING = 3
};

/**
 * Docu des fonctions dans grid.c
 */
Grid construct_grid(int size);
void deconstruct_grid(const Grid* grid);

void print_grid(const Grid* grid);
void placer_point(const Grid* grid, int x, int y, PointStatus status);
int isPointAttacked(const Grid* grid, int x, int y);
int isPointCountered(const Grid* grid, int x, int y);
int isPointPlayed(const Grid* grid, int x, int y);
PointStatus getStatus(const Grid* grid, int x, int y);

//Interface Ouput - Interface graphique visuelle

void display_grid(Grid* grid);

#endif //RM_GRID_H
