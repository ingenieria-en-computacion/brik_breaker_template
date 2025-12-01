#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "brick.h"

int bricks[BRICK_ROWS][BRICK_COLS]; /* 1 = vivo, 0 = destruido */

/* Variables globales de estado */
Ball ball;
Paddle paddle;
int score = 0;
int lives = 3;

/* ----------------------------------------------------------------------
   Plantillas de funciones: estas implementaciones son intencionalmente
   mínimas (stubs). Los estudiantes deben completarlas siguiendo los
   comentarios en brick.h y las indicaciones del enunciado.
   ---------------------------------------------------------------------- */

void mostrarMenu(void) {
    /* Muestra el menú y lee la opción.
       NOTA: se deja simple para que los tests detecten el texto del menú. */
    printf("===== BRICK BREAKER =====\n");
    printf("1) Iniciar juego\n");
    printf("2) Instrucciones\n");
    printf("3) Salir\n");
}

void iniciarJuego(void) {
    /* Inicializa el estado del juego (bricks, paleta, pelota, score, lives)
       Los alumnos deben:
         - Llenar bricks[][] con 1
         - Posicionar paddle.x = (WIDTH - PADDLE_W)/2, paddle.y = HEIGHT - 2
         - Asignar paddle.width = PADDLE_W
         - Inicializar ball con posición y velocidad iniciales
         - score = 0, lives = 3
    */
    int r, c;
    for (r = 0; r < BRICK_ROWS; ++r)
        for (c = 0; c < BRICK_COLS; ++c)
            bricks[r][c] = 1;

    paddle.x = (WIDTH - PADDLE_W)/2;
    paddle.y = HEIGHT - 2;
    paddle.width = PADDLE_W;

    /* posición y velocidad de ejemplo (los alumnos pueden ajustar) */
    ball.x = WIDTH / 2.0;
    ball.y = HEIGHT - 5;
    ball.vx = 0.6;
    ball.vy = -0.7;

    score = 0;
    lives = 3;
}

void runGameLoop(void) {
    /* Bucle principal del juego (stub)
       Debe:
         - Mientras vidas > 0 y queden bricks:
             * leer entrada no bloqueante
             * mover paleta según entrada
             * actualizarPelota()
             * checkColisiones()
             * dibujarPantalla()
             * controlar framerate (usleep / Sleep)
         - Mostrar pantalla final (ganaste / perdiste)
    */
    printf("runGameLoop: Implementa el bucle principal del juego aquí.\n");
}

void dibujarPantalla(void) {
    /* Dibuja el tablero usando printf y ANSI escapes.
       Ejemplo mínimo: imprimir bordes y HUD para que tests visuales lo detecten.
       (Los estudiantes deben implementar el render completo).
    */
    printf("Score: %d  Lives: %d\n", score, lives);
    printf("(render pendiente de implementar)\n");
}

void actualizarPelota(void) {
    /* Actualiza únicamente la posición teórica de la pelota
       (ball.x += ball.vx; ball.y += ball.vy) y gestiona rebotes
       básicos contra paredes y techo. Las colisiones con paleta y
       ladrillos se gestionan en checkColisiones().
    */
    double next_x = ball.x + ball.vx;
    double next_y = ball.y + ball.vy;

    if (next_x < 0) {
        ball.x = 0;
        ball.vx = -ball.vx;
        return;
    } else if (next_x > WIDTH - 1) {
        ball.x = WIDTH - 1;
        ball.vx = -ball.vx;
        return;
    }

    if (next_y < 0) {
        ball.y = 0;
        ball.vy = -ball.vy;
        return;
    }

    /* Movimiento por defecto */
    ball.x += ball.vx;
    ball.y += ball.vy;
}

void checkColisiones(void) {
    /* Debe detectar:
       - Colisión con paleta: invertir ball.vy y ajustar ball.vx según
         la zona de impacto.
       - Colisión con ladrillos: detectar fila/columna, marcar bricks[r][c]=0,
         incrementar score, invertir vy.
       - Si ball.y >= HEIGHT: decrementar lives y reiniciarPelota() o terminar.
    */
    /* Stub informativo */
    /* Los estudiantes deben implementar la detección precisa */
}

void moverPaleta(int dir) {
    /* dir: -1 izquierda, +1 derecha, 0 nada */
    if (dir == 0) return;
    paddle.x += dir * 2; /* movimiento por paso */
    if (paddle.x < 0) paddle.x = 0;
    if (paddle.x + paddle.width > WIDTH) paddle.x = WIDTH - paddle.width;
}

void reiniciarPelota(void) {
    /* Posiciona la pelota sobre la paleta y da velocidad inicial.
       Se puede usar para restablecer después de perder una vida.
    */
    ball.x = paddle.x + paddle.width / 2.0;
    ball.y = paddle.y - 1;
    ball.vx = (rand() % 2 == 0) ? 0.6 : -0.6;
    ball.vy = -0.7;
}
