#include <stdio.h>
#include <stdlib.h>
#include "brick.h"

/* Programa principal: muestra el menú y actúa según la opción.
   Se deja un menú mínimo; los alumnos pueden implantar un loop
   de lectura de opción e invocar iniciarJuego()/runGameLoop(). */

int main(void) {
    mostrarMenu();
    /* Para que el test de menú detecte salida, dejamos aquí la llamada.
       Los alumnos deberán implementar la lectura/acción de opciones. */
    return 0;
}
