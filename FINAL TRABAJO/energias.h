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


void mesmaximo2021(Energias tipo){
     float maxima = tipo.datos[0];
     int x=0,aux=0;
     int cont;
while(x<(COLUMNAS/2))
{


        if(tipo.datos[x]>maxima)
    {
    maxima=tipo.datos[x];
    aux=x+1;
    }
    x++;
}
switch(aux)
    {
    case 1:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue enero\n");
        break;
    case 2:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue febrero\n");
        break;
    case 3:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue marzo\n");
        break;
    case 4:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue abril\n");
        break;
    case 5:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue mayo\n");
        break;
    case 6:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue junio\n");
        break;
    case 7:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue julio\n");
        break;
    case 8:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue agosto\n");
        break;
    case 9:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue septiembre\n");
        break;
    case 10:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue octubre\n");
        break;
    case 11:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue noviembre\n");
        break;
    case 12:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2021 fue diciembre\n");
        break;
    default:
        printf("\tError");
        break;
    }
}

void mesmaximo2022(Energias tipo)
{
     float maxima = tipo.datos[0];
     int x=12,aux=0;
     int cont;
while(x<(COLUMNAS))
{


        if(tipo.datos[x]>maxima)
    {
    maxima=tipo.datos[x];
    aux=x+1;
    }
    x++;
}
switch(aux)
    {
    case 13:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue enero\n");
        break;
    case 14:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue febrero\n");
        break;
    case 15:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue marzo\n");
        break;
    case 16:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue abril\n");
        break;
    case 17:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue mayo\n");
        break;
    case 18:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue junio\n");
        break;
    case 19:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue julio\n");
        break;
    case 20:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue agosto\n");
        break;
    case 21:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue septiembre\n");
        break;
    case 22:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue octubre\n");
        break;
    case 23:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue noviembre\n");
        break;
    case 24:
        printf("\tEl mes en el que mas potencia se obtuvo de esta energia en 2022 fue diciembre\n");
        break;
    default:
        printf("\tError");
        break;
    }
}

void mostrar_introduccion(void){
    FILE *intro;
    char c;
    intro = fopen("descripcion.red.electrica.txt","r");
    if(intro == NULL){
        printf("Error en la introduccion");
        return;
    }
    while(fscanf(intro,"%c",&c) != EOF){
        printf("%c",c);
    }
    fclose(intro);
}

double emax2021(Energias tipo){
    double maxima = tipo.datos[0];
    int x;
    for(x = 0; x <= (COLUMNAS/2); x++){
        if(tipo.datos[x] > maxima)
            maxima = tipo.datos[x];
    }
    return maxima;
}

double emax2022(Energias tipo){
    double maxima = tipo.datos[COLUMNAS/2];
    int x;
    for(x = COLUMNAS/2; x < COLUMNAS; x++){
        if(tipo.datos[x] > maxima)
            maxima = tipo.datos[x];
    }
    return maxima;
}

double minimo2021(Energias tipo){
    double res = tipo.datos[0];
    int i = 0;
    while(i < (COLUMNAS/2)){
        if(tipo.datos[i] < res)
            res = tipo.datos[i];
        i++;
    }
    return res;
}

double minimo2022(Energias tipo){
    double res = tipo.datos[COLUMNAS/2];
    int i = COLUMNAS/2;
    while(i < COLUMNAS){
        if(tipo.datos[i] < res)
            res = tipo.datos[i];
        i++;
    }
    return res;
}

double mediaprimerano(Energias tipo){
    double med = 0;
    int x = 0;
    for(x = 0; x < (COLUMNAS/2); x++){
        med = med + tipo.datos[x];
    }
    med = med / (COLUMNAS/2);
    return med;
}

double mediasegundoano(Energias tipo){
    double med = 0;
    int x = COLUMNAS/2;
    for(x = COLUMNAS/2; x < COLUMNAS; x++){
        med = med + tipo.datos[x];
    }
    med = med / (COLUMNAS/2);
    return med;
}

void programaEnUnaFuncion(Energias registros[FILAS]) {
    FILE *archivo;
    char buffer[1000];//vecttor para meter temporalmente una linea
    int i = 0, j;

    archivo = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }//abre fichero y comprueba que todo okey.
    for (j = 0; j < 5; j++) {
        fgets(buffer, sizeof(buffer), archivo);
    }//coge las 5 primeras filas y las mete en el temporal.

    while (fgets(buffer, sizeof(buffer), archivo) != NULL && i < FILAS) {//mientras que lo que lea del archivo y almacenando en temporal no se nulo y i<filas
        char *token = strtok(buffer, ",");//se declara el token que que será la partición de la linea separado por una coma
        if (token != NULL) {
            strncpy(registros[i].titulo, token, TIPO_ENERGIA - 1);
        }//almacena el título de la generación.

        j = 0;
        while (token != NULL) {
            token = strtok(NULL, ",");
            if (token != NULL) {
                registros[i].datos[j] = atof(token);
                j++;
            }
        }

        i++;
    }//almacena cada mes en el vector de estructuras

    fclose(archivo);
}

void lectura_fichero_expor(exportacion paises[FILAS2]){

    FILE *archivo;
    char buffer[10000];//vecttor para meter temporalmente una linea
    int i = 0, j;

    archivo = fopen("todas-fronteras-fisicos_01-2021_12-2022.csv", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de exportacion.\n");
        return;
    }//abre fichero y comprueba que todo okey.
    for (j = 0; j < 7; j++) {
        fgets(buffer, sizeof(buffer), archivo);
    }//coge las 5 primeras filas y las mete en el temporal.

    while (fgets(buffer, sizeof(buffer), archivo) != NULL && i < FILAS2) {//mientras que lo que lea del archivo y almacenando en temporal no se nulo y i<filas
        char *token = strtok(buffer, ",");//se declara el token que que será la partición de la linea separado por una coma
        if (token != NULL) {
            strncpy(paises[i].pais, token, TIPO_ENERGIA - 1);
        }//almacena el título de la generación.

        j = 0;
        while (token != NULL) {
            token = strtok(NULL, ",");
            if (token != NULL) {
                paises[i].numeros[j] = atof(token);
                j++;
            }
        }

        i++;
    }//almacena cada mes en el vector de estructuras

    fclose(archivo);

}

void base_de_datos(Energias registros[FILAS],exportacion paises[FILAS2]){

 char aux,aux1;
 char aux_mostrar_datos;
        system("cls");

        while(aux!='q'){//bucle submenu base de datos.
printf(".........BIENVENIDO A LA BASE DE DATOS............\n\n");
            printf("seleccione la opcion que desea realizar\n");
            printf(" \t 1.Mostrar datos \n\t 2.Datos estadísticos\n\t 3.Mercados \n\t 4.salir de base de datos \n");
            scanf("  %c",&aux);



                        switch(aux){


                        case '1':
                             system("cls");
                            printf("Que datos quuieres ver?\n");
                            printf("\t a.Todo 2021\n\t b.Todo 2022\n");
                            scanf("  %c",&aux_mostrar_datos);

                            if(aux_mostrar_datos=='A'||aux_mostrar_datos=='z')aux_mostrar_datos+=32;//para que si se mete en mayuscula aún asi la coja

                            switch(aux_mostrar_datos){
                          case 'a':
                              system("cls");
                            printf("   TODO 2021\n");
                            for (int i = 0; i <FILAS ; i++) {
                             printf("Titulo: %s\n", registros[i].titulo);
                              for (int j = 0; j <= 11; j++) {
                             printf("%d/2021: %f GW \n", j+1, registros[i].datos[j]);
                                                          }
                                            printf("\n\n\n");
                                           }//bucle que recorre cada año y lo imprime por pantalla
                            break;

                            case 'b':
                              system("cls");
                            printf("   TODO 2022\n");
                            for (int i = 0; i <FILAS ; i++) {
                             printf("Titulo: %s\n", registros[i].titulo);
                              for (int j = 12; j < COLUMNAS; j++) {

                             printf("%d/2022: %f GW \n",j-11, registros[i].datos[j]);

                                                          }
                                            printf("\n\n\n");
                                           }
                            break;

                            }//bucle que recorre cada año y lo imprime por pantalla


                            break;

                        case '2'://datos estadísticos.

                            datos_estadisticos(registros);//función que ejecuta los datos estadisticos.

                            break;
                        case '4':


                            printf("Seguro que quieres salir? (S N) :");//salida del submenu de la base de datos.
                            scanf("  %c",&aux1);
                            if(aux1=='s'||aux1=='S'){
                                aux='q';
                                system("cls");
                                }


                            break;

                            case '3'://mercados.
                             system("cls");
                            mercados(registros,paises);


                            break;

                            default :
                                printf("\ncaracter no valido\n");
                                break;


                        }
                        }

}


void datos_estadisticos(Energias registros[FILAS]){

                char aux1;
                  system("cls");
                printf("¿De que tipo de generacion deseas obtener datos estadisticos?\n");
                printf("\ta. Hidraulica\n\tb. Turbinacion bombeo \n\tc. Nuclear\n\td. Carbon\n\te. Motores diesel\n\tf. Turbina de gas\n\tg. Turbina de vapor\n\th. Ciclo combinado\n\ti. Hidroeolica\n\tj. Eolica\n\tk. Solar fotovoltaica\n\tl. Solar termica\n\tm. Otras renovables\n\tn. Cogeneracion\n\to. Residuos no renovables\n\tp. Residuos renovables\n\tq. Generacion total\n\t");
                scanf(" %c", &aux1);
                if(aux1=='A'||aux1=='z')aux1+=32;//para que si se mete en mayuscula aún asi la coja

                switch (aux1) {
                    case 'a':
                        system("cls");
                        printf("Estadisticas para Hidraulica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[0]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[0]));
                        mesmaximo2021(registros[0]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[0]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[0]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[0]));
                        mesmaximo2022(registros[0]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[0]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[0]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[0]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [0]));
                        if (diferencia_2021_2022(registros [0])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [0])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [0])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    case 'b':
                        system("cls");
                        printf("Estadisticas para Turbinacion bombeo:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[1]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[1]));
                        mesmaximo2021(registros[1]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[1]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[1]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[1]));
                        mesmaximo2022(registros[1]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[1]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[1]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[1]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [1]));
                        if (diferencia_2021_2022(registros [1])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [1])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [1])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    case 'c':
                        system("cls");
                        printf("Estadisticas para Nuclear:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[2]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[2]));
                        mesmaximo2021(registros[2]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[2]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[2]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[2]));
                        mesmaximo2022(registros[2]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[2]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[2]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[2]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [2]));
                        if (diferencia_2021_2022(registros [2])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [2])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [2])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }

                        printf("\n\n");
                        break;

                    case 'd':
                        system("cls");
                        printf("Estadisticas para Carbon:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[3]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[3]));
                        mesmaximo2021(registros[3]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[3]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[3]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[3]));
                        mesmaximo2022(registros[3]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[3]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[3]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[3]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [3]));
                        if (diferencia_2021_2022(registros [3])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [3])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [3])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }

                        printf("\n\n");
                        break;

                    case 'e':
                        system("cls");
                        printf("Estadisticas para Motores diesel:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[4]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[4]));
                        mesmaximo2021(registros[4]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[4]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[4]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[4]));
                        mesmaximo2022(registros[4]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[4]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[4]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[4]));
                          printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [4]));
                        if (diferencia_2021_2022(registros [4])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [4])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [4])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }

                        printf("\n\n");
                        break;

                    case 'f':
                        system("cls");
                        printf("Estadisticas para Turbina de gas:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[5]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[5]));
                        mesmaximo2021(registros[5]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[5]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[5]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[5]));
                        mesmaximo2022(registros[5]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[5]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[5]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[5]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [5]));
                        if (diferencia_2021_2022(registros [5])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [5])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [5])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }

                        printf("\n\n");
                        break;

                    case 'g':
                        system("cls");
                        printf("Estadisticas para Turbina de vapor:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[6]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[6]));
                        mesmaximo2021(registros[6]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[6]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[6]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[6]));
                        mesmaximo2022(registros[6]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[6]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[6]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[6]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [6]));
                        if (diferencia_2021_2022(registros [6])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [6])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [6])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    case 'h':
                        system("cls");
                        printf("Estadisticas para Ciclo combinado:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[7]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[7]));
                        mesmaximo2021(registros[7]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[7]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[7]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[7]));
                        mesmaximo2022(registros[7]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[7]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[7]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[7]));
                          printf("\tDiferencia de energia generada entre 2021 y 2022: %.2f GW\n", diferencia_2021_2022(registros [7]));
                        if (diferencia_2021_2022(registros [7])<0)
                        {
                            printf("Se ha generado mas energia en 2021") ;
                        }
                        if(diferencia_2021_2022(registros [7])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if (diferencia_2021_2022(registros [7])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }

                        printf("\n\n");
                        break;

                    case 'i':
                        system("cls");
                        printf("Estadisticas para Hidroeolica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[8]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[8]));
                        mesmaximo2021(registros[8]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[8]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[8]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[8]));
                        mesmaximo2022(registros[8]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[8]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[8]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[8]));
                         printf("\tDiferencia de energia generada entre 2021 y 2022: %.2f GW\n", diferencia_2021_2022(registros [8]));
                        if (diferencia_2021_2022(registros [8])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [8])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [8])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    case 'j':
                        system("cls");
                        printf("Estadisticas para Eolica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[9]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[9]));
                        mesmaximo2021(registros[9]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[9]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[9]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[9]));
                        mesmaximo2022(registros[9]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[9]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[9]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[9]));
                         printf("\tDiferencia de energia generada entre 2021 y 2022: %.2f GW\n", diferencia_2021_2022(registros [9]));
                        if (diferencia_2021_2022(registros [9])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [9])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [9])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }

                        printf("\n\n");
                        break;

                    case 'k':
                        system("cls");
                        printf("Estadisticas para Solar fotovoltaica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[10]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[10]));
                        mesmaximo2021(registros[10]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[10]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[10]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[10]));
                        mesmaximo2022(registros[10]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[10]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[10]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[10]));
                         printf("\tDiferencia de energia generada entre 2021 y 2022: %.2f GW\n", diferencia_2021_2022(registros [10]));
                        if (diferencia_2021_2022(registros [10])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [10])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [10])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    case 'l':
                        system("cls");
                        printf("Estadisticas para Solar termica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[11]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[11]));
                        mesmaximo2021(registros[11]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[11]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[11]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[11]));
                        mesmaximo2022(registros[11]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[11]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[11]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[11]));
                         printf("\tDiferencia de energia generada entre 2021 y 2022: %.2f GW\n", diferencia_2021_2022(registros [11]));
                        if (diferencia_2021_2022(registros [11])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [11])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [11])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    case 'm':
                        system("cls");
                        printf("Estadisticas para Otras renovables:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[12]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[12]));
                        mesmaximo2021(registros[12]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[12]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[12]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[12]));
                        mesmaximo2022(registros[12]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[12]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[12]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[12]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [12]));
                        if (diferencia_2021_2022(registros [912])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [12])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [12])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }

                        printf("\n\n");
                        break;

                    case 'n':
                        system("cls");
                        printf("Estadisticas para Coogeneracion:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[13]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[13]));
                        mesmaximo2021(registros[13]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[13]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[13]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[13]));
                        mesmaximo2022(registros[13]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[13]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[13]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[13]));
                         printf("\tGenracion total en 2022: %.2f GW\n", sumaenergia2022(registros [13]));
                        if (diferencia_2021_2022(registros [13])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [13])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [13])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    case 'o':
                        system("cls");
                        printf("Estadisticas para Residuos no renovables:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[14]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[14]));
                        mesmaximo2021(registros[14]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[14]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[14]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[14]));
                        mesmaximo2022(registros[14]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[14]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[14]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[14]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [14]));
                        if (diferencia_2021_2022(registros [14])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [14])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [14])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    case 'p':
                        system("cls");
                        printf("Estadisticas para Residuos renovables:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[15]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[15]));
                        mesmaximo2021(registros[15]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[15]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[15]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[15]));
                        mesmaximo2022(registros[15]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[15]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[15]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[15]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [15]));
                        if (diferencia_2021_2022(registros [15])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [15])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [15])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    case 'q':
                        system("cls");
                        printf("Estadisticas para Generacion total:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[16]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[16]));
                        mesmaximo2021(registros[16]);
                        printf("\tGeneracion total en 2021: %.2f GW\n", sumaenergia2021(registros[16]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[16]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[16]));
                        mesmaximo2022(registros[16]);
                        printf("\tGeneracion total en 2022: %.2f GW\n", sumaenergia2022(registros[16]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[16]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[16]));
                         printf("\tMejora respecto de 2021 a 2022: %.2f GW\n", diferencia_2021_2022(registros [16]));
                        if (diferencia_2021_2022(registros [16])<0){
                            printf("Se ha generado mas energia en 2021 ");
                        }
                        if(diferencia_2021_2022(registros [16])>0){
                            printf("Se ha generado mas energia en 2022 ");

                        }
                        if(diferencia_2021_2022(registros [16])==0){
                            printf("Se ha generado la misma energia tanto en 2021 como en 2022 ");
                        }
                        printf("\n\n");
                        break;

                    default:
                        printf("\n    Opcion no valida");
                        break;
                }



}


void mercados(Energias registros[FILAS],exportacion paises[FILAS2]){


       char aux,aux2,aux3;

       system("cls");



       while(aux!='q'){
printf("...........HAS ENTRADO EN LA OPCION MERCADOS.............\n");
        printf("\t 1. Consultar precio de la luz\n\t 2. Comercio\n\t 3. salir\n");
         scanf(" %c",&aux);

           switch(aux){

           case '1':

             printf("\n1. Nivel comercial\n2. Nivel industrial.\n");
             scanf("  %c",&aux2);

                 switch(aux2){
                case '1':
                    printf("\nEl precio de la luz para el consumidor es de 0,1658 €/kWh\n");

                    break;

                case '2':
                    printf("\nEl precio de la luz para el uso industrial es de  60,4587 €/MWh\n");
                    break;

                default:
                    printf("\n estamos trabajando en ello \n");
                    break;
                 }

             break;

                case '2':

                    system("cls");
                    lectura_fichero_expor(paises);
                    exportaciones(paises);

                    break;

                    case '3':
                        printf("\n\n Seguro que quieres salir? ( S o N):");
                        scanf("    %c",&aux3);

                 if(aux3=='s'||aux3=='S'){
                                aux='q';
                                system("cls");
                 }

                    break;




           }

       }



}


void registro() {
    typedef struct{
    char nombre[30];
    char apellidos[30];
    int edad;
    }persona;
    char c,aux2;
    int aux12;
   FILE *archivo ;
persona personas;

    while(aux12!=1)
        {
            printf("\t1. Registrarse\n\t2. Ver registrados\n\t3. Salir\n ");
            scanf("  %c", &aux12);
            switch(aux12){

            case '1':
                archivo = fopen("registro.txt", "a");
                if(archivo==NULL){
                    printf("\n\terror al abrir el fichero registros\n");
                }
                system("cls");
                printf(".....HA COMENZADO EL REGISTRO.......\n ");
                printf("Ingrese su nombre: ");
                scanf(" %30s", personas.nombre);
                printf("Ingrese sus apellidos: ");
                scanf("  %30s", personas.apellidos);
                 printf("Ingrese su edad: ");
                 scanf(" %d", &personas.edad);
                 fprintf(archivo, "Nombre: %s\tApellidos: %s \tedad: %i \n\n\n", personas.nombre, personas.apellidos,personas.edad);
                 fclose(archivo);
                break;
                case '2':
                archivo = fopen("registro.txt", "r");
                 if(archivo==NULL){
                    printf("\n\terror al abrir el fichero registros\n");
                }
                system("cls");
                printf(".....VER REGISTRADOS.......\n ");
                while(fscanf(archivo,"%c",&c)!=EOF){
                    printf("%c",c);
                }

                 fclose(archivo);
                break;

                case '3':
                printf("\n\tSeguro que quieres salir?(S o N):");
                scanf("        %c",    &aux2);
                if(aux2=='s'||aux2=='S'){
                    aux12=1;
                    system("cls");
                }


                break;

                default:
                printf("\tERROR\n");
                break;
            }


    }





}
double diferencia_2021_2022(Energias tipo)
{
    int suma1 = 0;
    int suma2=0;
    for (int i = 0; i < (COLUMNAS/2); i++) {
        suma1 += tipo.datos[i];
    }
    for (int i = (COLUMNAS/2) ; i <=COLUMNAS; i++) {
        suma2 += tipo.datos[i];
    }


    return suma2-suma1;
}
double sumaenergia2021(Energias tipo)
{
    int suma = 0;

    for (int i = 0; i < (COLUMNAS/2); i++) {
        suma += tipo.datos[i];
    }

    return suma;
}

double sumaenergia2022(Energias tipo)
{
    int suma = 0;

    for (int i = (COLUMNAS/2) ; i <=COLUMNAS; i++) {
        suma += tipo.datos[i];
    }

    return suma;
}

void exportaciones(exportacion paises[FILAS2]){
    char aux,aux1;

        while(aux!='q'){//bucle submenu base de datos.
printf("\n.......HAS ENTRADO EN COMERCIO.......\n");
            printf("seleccione la opcion que desea realizar\n");
            printf(" \t 1.Mostrar datos \n\t 2.datos estadisticos\n\t 3.salir de comercio \n");
            scanf("  %c",&aux);



                        switch(aux){


                        case '1':
                             system("cls");
                              for (int i = 0; i <FILAS2 ; i++) {
                             printf("Pais: %s\n", paises[i].pais);
                              for (int j = 0; j < COLUMNAS2; j++) {
                                    if ((j - 1) % 3 == 0)
                                    {
                                       printf("Importacion: %f GW \n", paises[i].numeros[j]);
                                    }
                                    else if ((j - 2) % 3 == 0)
                                    {
                                       printf("Saldo: %f GW \n", paises[i].numeros[j]);
                                    }
                                    else
                                    {
                                        printf("Exportacion: %f GW \n", paises[i].numeros[j]);
                                    }

                                                          }
                                            printf("\n\n\n");
                                           }

                            break;







                        case '2'://datos estadísticos.



                            break;
                        case '3':


                            printf("Seguro que quieres salir? (S N) :");//salida del submenu de la base de datos.
                            scanf("  %c",&aux1);
                            if(aux1=='s'||aux1=='S'){
                                aux='q';
                                system("cls");
                                }


                            break;



                            default :
                                printf("\ncaracter no valido\n");
                                break;


                        }
                        }



}
