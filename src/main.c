#include <stdio.h>
#include "menu.h"
#include "game.h"

// ---------------------------------------------
// Programa principal
// Los estudiantes deben implementar:
//  - El menú en menu.c
//  - La lógica del juego en game.c
// ---------------------------------------------
int main() {
    menu_show();
    int option = menu_get_option();

    // Opción 1: Iniciar el juego
    if (option == 1) {
        game_init();

        // Ciclo principal del juego
        while (!game_is_over()) {
            game_update();
            game_render();
        }
    }

    // Opción 2: Salir
    printf("Gracias por jugar.\n");

    return 0;
}
