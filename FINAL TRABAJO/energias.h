#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILAS 17
#define FILAS2 5
#define COLUMNAS 24
#define COLUMNAS2 72
#define TIPO_ENERGIA 100

typedef struct {
    char titulo[TIPO_ENERGIA];
    double datos[COLUMNAS];
} Energias;
typedef struct {
    char pais[TIPO_ENERGIA];
    double numeros[COLUMNAS2];
} exportacion;

void mostrar_introduccion(void);
void programaEnUnaFuncion(Energias registros[FILAS]);
void lectura_fichero_expor(exportacion paises[FILAS2]);
void base_de_datos(Energias registros[FILAS],exportacion paises[FILAS2]);
void datos_estadisticos(Energias registros[FILAS]);
void mercados(Energias registros[FILAS],exportacion paises[FILAS2]);
double minimo2021(Energias tipo);
double minimo2022(Energias tipo);
double emax2021(Energias tipo);
double emax2022(Energias tipo);
double mediaprimerano(Energias tipo);
double mediasegundoano(Energias tipo);
double sumaenergia2021(Energias tipo);
double sumaenergia2022(Energias tipo);
double diferencia_2021_2022(Energias tipo);
void registro();
void mesmaximo2021(Energias tipo);
void mesmaximo2022(Energias tipo);
void exportaciones(exportacion paises[FILAS2]);
double mediaExportaciones( exportacion paises[FILAS2]);
double datos_estadisticos_expor( exportacion paises[FILAS2]);
double mediaSal( exportacion paises[FILAS2]);
double mediaImportacion( exportacion paises[FILAS2]);



