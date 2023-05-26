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

void datos_estadisticos(Energias registros[FILAS]);

double minimo(Energias tipo);

double emax(Energias tipo);

double mediaprimerano(Energias tipo);

double mediasegundoano(Energias tipo);
//se declaran todas las funciones que se usarán a lo largo del programa.

int main ()
{

    Energias registros[FILAS];//se define el vector de estructuras en el main
    FILE *archivo;// se define el fichero en el main.
    char buffer[1000],op1,op2;
    int i = 0, j;


    //mostrar_introduccion();//se ejecuta la función de introduccion


    do//se ejecuta el bucle del menú principal.
    {
        mostrar_introduccion();//se ejecuta la función de introduccion
        printf("\n\n MENU PRINCIPAL\n\n 1. Instrucciones\n\n 2. Base de Datos \n\n 3. Salir\n\n Opcion: ");
        scanf(" %c",&op1);

        switch(op1)
        {
            case '1':
                system("cls");
                  printf("\n Instrucciones:\n");
                  printf("En esta aplicacion encontrara una base de datos sobre la generacion de electricidad en el 2021 y 2022\n ");
                  printf("Podremos ver que tipos de generacion han habido si ha sido por medios renovables o no y obtener distintos datos estadisticos \n ");

           printf("\n\n\n");

            system("pause");
             break;

             case '2':
                     printf("\n Base de Datos");//aqui se abre la base de datos.

                         programaEnUnaFuncion(registros);//Se ejecuta la función de leer el fichero y almacenar los datos en el vector de estructuras.
                         base_de_datos(registros);//Se ejecuta la función que de base de datos y empiza el submenú de la base de datos.

                       break;

              case '3':
                printf("\n    Estas seguro de que quieres salir (S o N)?: ");//se ejecuta para salir.
                scanf(" %c",&op2);
                if(op2=='S' || op2=='s')
                {
                    return 0;
                }
              break;

              default:
                printf("\n    Opcion no valida");
              break;
        }

          system("cls");
    }
    while(1);
    return 0;

}


void mostrar_introduccion(void){

    FILE *intro;//Se declara el fichero de introducción.
    char c;

  intro = fopen("descripcion.red.electrica.txt","r");
  if(intro==NULL){
    printf("Error en la introduccion");//abre fichero comprueba que todo bien.
  }
   while(fscanf(intro,"%c",&c)!=EOF){
    printf("%c",c);
   }//imprime todo el fichero de introducción.

}


//en las funciones el imput es el vector de estructuras, así dentro de la función tienes todos los datos del fichero


double emax(Energias tipo)
{
    double maxima = tipo.datos[0];
    int x=0;
    for(x=0;x<COLUMNAS;x++)
    {
        if(tipo.datos[x]>maxima) maxima=tipo.datos[x];
    }

return maxima;
}

double minimo(Energias tipo){
  double res=tipo.datos[0];
  int i=0;
  while(i<COLUMNAS){
    if(tipo.datos[i]< res)res=tipo.datos[i];
    i++;
  }

return res;
}

double mediaprimerano(Energias tipo)
{
    double med=0;
    int x=0;
    for(x=0;x<(COLUMNAS/2);x++)
    {
        med = med + tipo.datos[x];
    }
med = med/(COLUMNAS/2);
return med;
}

double mediasegundoano(Energias tipo)
{
    double med=0;
    int x=0;
    for(x=12;x<COLUMNAS;x++)
    {
        med = med + tipo.datos[x];
    }
med = med/(COLUMNAS/2);
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


void base_de_datos(Energias registros[FILAS]){

 char aux,aux1;
 char aux_mostrar_datos;
        system("cls");
printf(".........BIENVENIDO A LA BASE DE DATOS............\n\n");
        while(aux!='q'){//bucle submenu base de datos.

            printf("seleccione la opcion que desea realizar\n");
            printf(" \t 1.Mostrar datos \n\t 2.Datos estadísticos \n\t 3.salir de base de datos \n");
            scanf("  %c",&aux);



                        switch(aux){


                        case '1':
                            printf("Que datos quuieres ver?\n");
                            printf("\t a.Todo 2021\n\t b.Todo 2022\n");
                            scanf("  %c",&aux_mostrar_datos);
                            switch(aux_mostrar_datos){
                          case 'a':
                              system("cls");
                            printf("   TODO 2021\n");
                            for (int i = 0; i <FILAS ; i++) {
                             printf("Titulo: %s\n", registros[i].titulo);
                              for (int j = 0; j <= 11; j++) {
                             printf("%d/2021: %f GW  ;", j+1, registros[i].datos[j]);
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

                             printf("%d/2022: %f GW  ;",j-11, registros[i].datos[j]);

                                                          }
                                            printf("\n\n\n");
                                           }
                            break;

                            }//bucle que recorre cada año y lo imprime por pantalla


                            break;

                        case '2'://datos estadísticos.

                            datos_estadisticos(registros);//función que ejecuta los datos estadisticos.

                            break;
                        case '3':


                            printf("Seguro que quieres salir? (S N) :");//salida del submenu de la base de datos.
                            scanf("  %c",&aux1);
                            if(aux1=='s'||aux1=='s'){
                                aux='q';
                                system("cls");
                                }


                            break;


                        }
                        }

}


void datos_estadisticos(Energias registros[FILAS]){

                char aux1;

                printf("¿De que tipo de generacion deseas obtener datos estadisticos?\n");
                printf("\ta. Hidraulica\n\tb.c. Turbinacion bombeo \n\tc.d. Nuclear\n\td. Carbon\n");
                scanf(" %c", &aux1);

                switch (aux1) {
                    case 'a':
                        system("cls");
                        printf("Estadisticas para Hidraulica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo(registros[0]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax(registros[0]));
                        printf("\tMedia primer semestre 2022: %.2f GW\n", mediaprimerano(registros[0]));
                        printf("\tMedia segundo semestre 2022: %.2f GW\n", mediasegundoano(registros[0]));
                        printf("\n\n");
                        break;

                    case 'b':
                        system("cls");
                        printf("Estadisticas para Turbinacion bommbeo:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo(registros[1]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax(registros[1]));
                        printf("\tMedia primer semestre 2022: %.2f GW\n", mediaprimerano(registros[1]));
                        printf("\tMedia segundo semestre 2022: %.2f GW\n", mediasegundoano(registros[1]));
                        printf("\n\n");
                        break;

                    case 'c':
                        system("cls");
                        printf("Estadisticas para Nuclear:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo(registros[2]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax(registros[2]));
                        printf("\tMedia primer semestre 2022: %.2f GW\n", mediaprimerano(registros[2]));
                        printf("\tMedia segundo semestre 2022: %.2f GW\n", mediasegundoano(registros[2]));
                        printf("\n\n");
                        break;

                    case 'd':
                        system("cls");
                        printf("Estadisticas para Carbon:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo(registros[3]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax(registros[3]));
                        printf("\tMedia primer semestre 2022: %.2f GW\n", mediaprimerano(registros[3]));
                        printf("\tMedia segundo semestre 2022: %.2f GW\n", mediasegundoano(registros[3]));
                        printf("\n\n");
                        break;

                    default:
                        printf("\n    Opcion no valida");
                        break;
                }



}













