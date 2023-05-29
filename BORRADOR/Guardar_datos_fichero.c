#include <stdio.h>
#include <stdlib.h>

#define FILAS 17
#define COLUMNAS 24
#define TIPO_ENERGIA 100

typedef struct {
    char titulo[TIPO_ENERGIA];
    double datos[COLUMNAS];
} Energias;

int main() {
    Energias registros[FILAS];
    FILE *archivo;
    char buffer[1000];
    int i = 0, j;

    archivo = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    for (j = 0; j < 5; j++) {
            fgets(buffer, sizeof(buffer), archivo);
        }


    // Leer y almacenar los datos en el vector de estructuras
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

    // Imprimir los datos almacenados en el vector de estructuras
    for (i = 0; i < FILAS; i++) {
        printf("Título: %s\n", registros[i].titulo);
        for (j = 0; j < COLUMNAS; j++) {
            printf("Dato %d: %f\n", j, registros[i].datos[j]);
        }
        printf("\n");
    }

    return 0;
}
