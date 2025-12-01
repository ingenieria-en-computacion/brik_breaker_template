#include "score.h"
#include <stdio.h>

// =======================
//   PLANTILLA DEL MÓDULO DE SCORES
// =======================
//
// IMPORTANTE: 
// Este archivo NO incluye ninguna implementación real.
// El estudiante DEBE escribir todo el código.
//
// Se dejan líneas y comentarios guía.
// =======================

// Variables sugeridas (el estudiante puede modificarlas)
static Record records[10];   // Lista de récords
static int num_records = 0;  // Número de récords cargados
static int current_score = 0; // Puntaje actual

// Reinicia el puntaje actual
void score_reset() {
    // TODO: Reiniciar puntaje a 0
}

// Incrementa el puntaje actual
void score_add(int amount) {
    // TODO: Sumar 'amount' al puntaje
}

// Devuelve el puntaje actual
int score_get() {
    // TODO: Regresar el puntaje actual
    return 0;
}

// Carga las puntuaciones desde un archivo
void score_load(const char *filename) {
    // TODO:
    // 1) Abrir archivo
    // 2) Leer records línea por línea
    // 3) Guardarlos en el arreglo 'records'
    // 4) Actualizar 'num_records'
}

// Guarda los puntajes en un archivo
void score_save(const char *filename) {
    // TODO:
    // 1) Abrir archivo en modo escritura
    // 2) Escribir records ordenados
    // 3) Incluir el nuevo puntaje
    // 4) Cerrar archivo
}

// Mostrar puntajes
void score_print() {
    // TODO:
    // Imprimir los records cargados en pantalla
}

