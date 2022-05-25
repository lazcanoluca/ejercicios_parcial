int main(int argc, char const *argv[])
{
    struct nodo *cosa;

    char *caracteres = malloc(5*sizeof(char));
    if (!caracteres) return -1;

    for (int i = 0; i < 5; i++) {

    }

    todas_las_cosas[6] = NULL;
    int cosas_creadas = 0;
    int hay_error = 0;

    while (cosas_creadas < 5 && !hay_error) {
        todas_las_cosas[cosas_creadas + 1] = malloc(sizeof(struct nodo));
        if (todas_las_cosas[cosas_creadas + 1] == NULL) hay_error = 1;
        else cosas_creadas++;
    }

    if (cosas_creadas == 5) {
        for (int i = 0; i < cosas_creadas; i++) {
            if ((i - 1) % 2 == 0) {
                todas_las_cosas[i]->punteros[0] = todas_las_cosas[i-1];
                todas_las_cosas[i]->punteros[1] = caracteres+i;
                todas_las_cosas[i]->punteros[2] = todas_las_cosas[i+1];
            } else {
                todas_las_cosas[i]->punteros[0] = todas_las_cosas[i+1];
                todas_las_cosas[i]->punteros[1] = todas_las_cosas[i-1];
                todas_las_cosas[i]->punteros[2] = caracteres+i;

            }
        }
    }

    for (int i = 0; i < cosas_creadas;i++) {
        free(todas_las_cosas[i]);
    }

    free(caracteres);

    return 0;
}
