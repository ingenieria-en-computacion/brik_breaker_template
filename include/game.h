#ifndef GAME_H
#define GAME_H

// Inicializa todos los elementos del juego
void game_init();

// Lógica del juego
void game_update();

// Dibuja todo en pantalla
void game_render();

// Indica si el juego terminó
int game_is_over();

#endif
