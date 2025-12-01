#ifndef SCORE_H
#define SCORE_H

// =======================
//   SISTEMA DE PUNTUACIONES
// =======================
//
// En este módulo el estudiante debe:
//
// 1) Definir cómo guardar y manejar puntajes
// 2) Implementar archivo de texto para records
// 3) Agregar la lógica de insertar nuevo score en TOP 10
// 4) Mostrar el historial de puntuaciones ordenado
//
// NOTA: Este archivo SOLO contiene los prototipos.
// 

// Estructura sugerida (el estudiante puede modificarla)
typedef struct {
    char name[4];   // Iniciales, ej. "RAC"
    int score;      // Puntaje
} Record;

// Carga las puntuaciones desde archivo
void score_load(const char *filename);

// Guarda las puntuaciones en archivo
void score_save(const char *filename);

// Reinicia el puntaje actual
void score_reset();

// Incrementa el puntaje actual
void score_add(int amount);

// Devuelve el puntaje actual
int score_get();

// Muestra los mejores puntajes
void score_print();

#endif
