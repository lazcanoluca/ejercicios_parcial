/*
    * EJERCICIO 1
    * a.    Escriba un programa (deniendo las variables, estructuras y tipos que crea conveniente)
    * de forma tal que el uso de memoria del mismo sea como el que se muestra a continuación
    * (puede agregar variables o punteros auxiliares si esnecesario).
    * b.    Muestre el código que hace que dicho programa libere correctamente toda la memoria
    * reservada.
*/

/* VARIANTE 1 */

#define MAX_ARRAY 5

typedef struct caja {
    char campo_1;
    int ***campo_2;
} caja_t;


int main(int argc, char const *argv[])
{
    caja_t *v1 = malloc(sizeof(caja_t));
    if (!v1) return -1;

    int *cosa_en_el_heap = malloc(sizeof(char));
    if (!cosa_en_el_heap) {
        free(v1);
        return -1;
    };

    int ***vector = malloc(5 * sizeof(int **));
    if (!vector) {
        free(v1);
        free(cosa_en_el_heap);
        return -1;
    }

    *cosa_en_el_heap = 'A';
    char cosa_en_el_stack = 'L';


    for (int i = 0; i < MAX_ARRAY; i++) {

        vector[i] = malloc((i+1) * sizeof(int *));

        for (int j = 0; j < i; j++) {
            // Si es par apunta a la cosa en el heap, sino, a la cosa en el stack.
            vector[i][j] = (j % 2) == 0 ? &cosa_en_el_stack : cosa_en_el_heap;
        }
    }

    v1->campo_1 = 'C';
    v1->campo_2 = vector;

    // Acá hago cosas.

    // Libero toda la memoria.
    for (int i = 0; i < MAX_ARRAY; i++) {

        for (int j = 0; j < i; j++) {
            free(v1->campo_2[i][j]);
        }

        free(v1->campo_2[i]);
    }

    free(v1->campo_2);
    free(v1);

    destruir_todo(v1);


    free(cosa_en_el_heap);

    return 0;
}
