#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 17
#define COLUMNAS 24
#define TIPO_ENERGIA 100

typedef struct {
    char titulo[TIPO_ENERGIA];
    double datos[COLUMNAS];
} Energias;

void mostrar_introduccion(void);
void programaEnUnaFuncion(Energias registros[FILAS]);
void base_de_datos(Energias registros[FILAS]);
double minimo(Energias tipo, char titulo[TIPO_ENERGIA]);
double emax(Energias tipo);
double mediaprimerano(Energias tipo);
double mediasegundoano(Energias tipo);

int main() {
    Energias registros[FILAS];
    FILE *archivo;
    char buffer[1000], op1, op2;
    int i = 0, j;

    do {
        mostrar_introduccion();
        printf("\n\n MENU PRINCIPAL\n\n 1. Instrucciones\n\n 2. Base de Datos \n\n 3. Salir\n\n Opcion: ");
        scanf(" %c", &op1);

        switch (op1) {
            case '1':
                system("cls");
                printf("\n Instrucciones:\n");
                printf("En esta aplicacion encontrara una base de datos sobre la generacion de electricidad en el 2021 y 2022\n");
                printf("Podremos ver que tipos de generacion han habido si ha sido por medios renovables o no y obtener distintos datos estadisticos \n");

                printf("\n\n\n");
                system("pause");
                break;

            case '2':
                printf("\n Base de Datos");
                programaEnUnaFuncion(registros);
                base_de_datos(registros);
                break;

            case '3':
                printf("\n    Estas seguro de que quieres salir (S o N)?: ");
                scanf(" %c", &op2);
                if (op2 == 'S' || op2 == 's') {
                    return 0;
                }
                break;

            default:
                printf("\n    Opcion no valida");
                break;
        }

        system("cls");
    } while (1);

    return 0;
}

void mostrar_introduccion(void) {
    FILE *intro;
    char c;

    intro = fopen("descripcion.red.electrica.txt", "r");
    if (intro == NULL) {
        printf("Error en la introduccion");
    }

    while (fscanf(intro, "%c", &c) != EOF) {
        printf("%c", c);
    }

    fclose(intro);
}

double emax(Energias tipo) {
    double maxima = tipo.datos[0];
    int x = 0;
    for (x = 0; x < COLUMNAS; x++) {
        if (tipo.datos[x] > maxima)
            maxima = tipo.datos[x];
    }

    return maxima;
}

double minimo(Energias tipo, char titulo[TIPO_ENERGIA]) {
    double res = tipo.datos[0];
    int i = 0;
    while (i < COLUMNAS) {
        if (strcmp(tipo.titulo, titulo) == 0 && tipo.datos[i] < res)
            res = tipo.datos[i];
        i++;
    }

    return res;
}

double mediaprimerano(Energias tipo) {
    double med = 0;
    int x = 0;
    for (x = 0; x < (COLUMNAS / 2); x++) {
        med = med + tipo.datos[x];
    }
    med = med / (COLUMNAS / 2);
    return med;
}

double mediasegundoano(Energias tipo) {
    double med = 0;
    int x = 0;
    for (x = 12; x < COLUMNAS; x++) {
        med = med + tipo.datos[x];
    }
    med = med / (COLUMNAS / 2);
    return med;
}

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

void base_de_datos(Energias registros[FILAS]) {
    char aux;
    char aux1, aux_mostrar_datos;
    system("cls");
    printf(".........BIENVENIDO A LA BASE DE DATOS............\n\n");
    while (aux != 'q') {
        printf("Seleccione la opcion que desea realizar:\n");
        printf("\t1. Mostrar datos\n\t2. Datos estadísticos\n\t3. Salir de base de datos\n");
        scanf(" %c", &aux);

        switch (aux) {
            case '1':
                printf("¿Qué datos quieres ver?\n");
                printf("\ta. Todo 2021\n\tb. Todo 2022\n");
                scanf(" %c", &aux_mostrar_datos);
                switch (aux_mostrar_datos) {
                    case 'a':
                        system("cls");
                        printf("TODO 2021\n");
                        for (int i = 0; i < FILAS; i++) {
                            printf("Titulo: %s\n", registros[i].titulo);
                            for (int j = 0; j <= 11; j++) {
                                printf("%d/2021: %f GW  ;", j + 1, registros[i].datos[j]);
                            }
                            printf("\n\n\n");
                        }
                        break;

                    case 'b':
                        system("cls");
                        printf("TODO 2022\n");
                        for (int i = 0; i < FILAS; i++) {
                            printf("Titulo: %s\n", registros[i].titulo);
                            for (int j = 12; j < COLUMNAS; j++) {
                                printf("%d/2022: %f GW  ;", j - 11, registros[i].datos[j]);
                            }
                            printf("\n\n\n");
                        }
                        break;
                }
                break;

            case '2':
                printf("¿De qué tipo de generación deseas obtener datos estadísticos?\n");
                printf("\ta. Solar Fotovoltaica\n\tb. Solar Termoeléctrica\n\tc. Eólica\n\td. Hidráulica\n");
                scanf(" %c", &aux1);

                switch (aux1) {
                    case 'a':
                        system("cls");
                        printf("Estadísticas para Solar Fotovoltaica:\n");
                        printf("\tValor mínimo en 2021: %.2f GW\n", minimo(registros[0], "Solar Fotovoltaica"));
                        printf("\tValor máximo en 2021: %.2f GW\n", emax(registros[0]));
                        printf("\tMedia primer semestre 2022: %.2f GW\n", mediaprimerano(registros[0]));
                        printf("\tMedia segundo semestre 2022: %.2f GW\n", mediasegundoano(registros[0]));
                        printf("\n\n");
                        break;

                    case 'b':
                        system("cls");
                        printf("Estadísticas para Solar Termoeléctrica:\n");
                        printf("\tValor mínimo en 2021: %.2f GW\n", minimo(registros[1], "Solar Termoeléctrica"));
                        printf("\tValor máximo en 2021: %.2f GW\n", emax(registros[1]));
                        printf("\tMedia primer semestre 2022: %.2f GW\n", mediaprimerano(registros[1]));
                        printf("\tMedia segundo semestre 2022: %.2f GW\n", mediasegundoano(registros[1]));
                        printf("\n\n");
                        break;

                    case 'c':
                        system("cls");
                        printf("Estadísticas para Eólica:\n");
                        printf("\tValor mínimo en 2021: %.2f GW\n", minimo(registros[2], "Eólica"));
                        printf("\tValor máximo en 2021: %.2f GW\n", emax(registros[2]));
                        printf("\tMedia primer semestre 2022: %.2f GW\n", mediaprimerano(registros[2]));
                        printf("\tMedia segundo semestre 2022: %.2f GW\n", mediasegundoano(registros[2]));
                        printf("\n\n");
                        break;

                    case 'd':
                        system("cls");
                        printf("Estadísticas para Hidráulica:\n");
                        printf("\tValor mínimo en 2021: %.2f GW\n", minimo(registros[3], "Hidráulica"));
                        printf("\tValor máximo en 2021: %.2f GW\n", emax(registros[3]));
                        printf("\tMedia primer semestre 2022: %.2f GW\n", mediaprimerano(registros[3]));
                        printf("\tMedia segundo semestre 2022: %.2f GW\n", mediasegundoano(registros[3]));
                        printf("\n\n");
                        break;

                    default:
                        printf("\n    Opcion no valida");
                        break;
                }
                break;

            case '3':
                aux = 'q';
                break;

            default:
                printf("\n    Opcion no valida");
                break;
        }
    }
}
