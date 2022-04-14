#include <stdio.h>
#include "game.h"

int main() {
    printf("Bienvenue dans le jeu du traceur-briseur !\nVous souhaitez jouer en tant que : \n1 - Traceur\n2 - Briseur\n\n> ");
    int input1 = 0, input2 = 0, input3 = 0;
    scanf("%d", &input1);
    printf("Contre qui souhaitez-vous jouer : \n1 - Un autre joueur\n2 - Un robot\n\n> ");
    scanf("%d", &input2);
    printf("Entrez la taille de la grille sur laquelle vous souhaitez jouer\n\n> ");
    scanf("%d", &input3);
    Grid grid = construct_grid(input3);
    if ((input1 == 1 && input2 == 1) || (input1 == 2 && input2 == 1))
        PvsP(&grid);
    else if(input1 == 1 && input2 == 2)
        PvsIA(&grid);
    else if (input1 == 2 && input2 == 2)
        IAvsP(&grid);
    deconstruct_grid(&grid);
    return 0;
}
