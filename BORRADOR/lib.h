#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define FILAS 17
#define COLUMNAS 24
#define TIPO_ENERGIA 100
typedef struct {
    char titulo[TIPO_ENERGIA];
    double datos[COLUMNAS];
} Energias;//se define la estructura para almacenar los datos de las energías.

void mostrar_introduccion(void);//con esta función se muestra el texto de la introducción.

void programaEnUnaFuncion(Energias registros[FILAS]);//esta función sirve para almacenar los datos del fichero en un vector de estructuras.

void base_de_datos(Energias registros[FILAS]);//esta función ejecuta la base de datos.

void datos_estadisticos(Energias registros[FILAS]);//esta funcion ejecuta los datos estadísticos.

void mercados(Energias registros[FILAS]);

double minimo2021(Energias tipo);

double minimo2022(Energias tipo);

double emax2021(Energias tipo);

double emax2022(Energias tipo);

double mediaprimerano(Energias tipo);

double mediasegundoano(Energias tipo);

void registro();
//se declaran todas las funciones que se usarán a lo largo del programa.
