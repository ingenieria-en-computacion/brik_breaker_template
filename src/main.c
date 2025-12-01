#include <stdio.h>
#include "menu.h"
#include "game.h"
#include "score.h"

int main() {
    int option;

    score_load("scores.txt");

    do {
        menu_show();
        option = menu_get_option();

        switch(option) {
            case 1:
                game_init();
                while(!game_is_over()) {
                    game_update();
                    game_render();
                }
                score_save("scores.txt");
                break;

            case 2:
                score_print();
                break;

            case 3:
                printf("Saliendo del juego...\n");
                break;

            default:
                printf("Opción inválida\n");
        }

    } while(option != 3);

    return 0;
}
