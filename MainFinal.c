#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "energias.h"
#define FILAS 17
#define COLUMNAS 24
#define TIPO_ENERGIA 100

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
        printf("\n\n MENU PRINCIPAL\n\n 1. Instrucciones\n\n 2. Base de Datos \n\n 3. Registro\n\n 4. Salir\n\n Opcion: ");
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

              case '4':
                printf("\n    Estas seguro de que quieres salir (S o N)?: ");//se ejecuta para salir.
                scanf(" %c",&op2);
                if(op2=='S' || op2=='s')
                {
                    return 0;
                }
              break;

              case '3':
                    system("cls");
                    printf("...........BIENVENIDO AL REGISTRO............\n");//aqui se mete la funciion de registro.
                    registro();

              default:
                printf("\n    Opcion no valida");
              break;
        }

          system("cls");
    }
    while(1);
    return 0;

}


