include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 17
#define COLUMNAS 24
#define TIPO_ENERGIA 100

typedef struct {
    char titulo[TIPO_ENERGIA];
    double datos[COLUMNAS];
} Energias;

void programaEnUnaFuncion(Energias registros[FILAS]) {
    FILE *archivo;
    char buffer[1000];
    int i = 0, j;

    archivo = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    for (j = 0; j < 5; j++) {
        fgets(buffer, sizeof(buffer), archivo);
    }

    while (fgets(buffer, sizeof(buffer), archivo) != NULL && i < FILAS) {
        char *token = strtok(buffer, ",");
        if (token != NULL) {
            strncpy(registros[i].titulo, token, TIPO_ENERGIA - 1);
        }

        j = 0;
        while (token != NULL) {
            token = strtok(NULL, ",");
            if (token != NULL) {
                registros[i].datos[j] = atof(token);
                j++;
            }
        }

        i++;
    }

    fclose(archivo);
}

int main() {
    Energias registros[FILAS];
    programaEnUnaFuncion(registros);

    int i, j;
    for (i = 0; i < FILAS; i++) {
        printf("Título: %s\n", registros[i].titulo);
        for (j = 0; j < COLUMNAS; j++) {
            printf("Dato %d: %f\n", j, registros[i].datos[j]);
        }
        printf("\n");
    }
    return 0;
}
