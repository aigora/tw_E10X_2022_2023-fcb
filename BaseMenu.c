#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define FILAS 17
#define COLUMNAS 24
#define TIPO_ENERGIA 100

typedef struct {
    char titulo[TIPO_ENERGIA];
    double datos[COLUMNAS];
} Energias;

void mostrar_introduccion(void);

int main ()
{

    Energias registros[FILAS];
    FILE *archivo;
    char buffer[1000],op1,op2;
    int i = 0, j;


    mostrar_introduccion();//introduccion


    do
    {
        printf("\n\n MENU PRINCIPAL\n\n 1. Instrucciones\n\n 2. Base de Datos \n\n 3. Salir\n\n Opcion: ");
        scanf(" %c",&op1);

        switch(op1)
        {
            case '1':
                  printf("\n Instrucciones:\n");
                  printf("En esta aplicacion encontrara una base de datos sobre la generacion de electricidad en el 2021 y 2022\n ");
                  printf("Podremos ver que tipos de generacion han habido si ha sido por medios renovables o no y obtener distintos datos estadisticos \n ");

             break;

             case '2':
                     printf("\n Base de Datos");//aqui se abre la base de datos.
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

                        char aux;

                        printf("presione 1 para ver datos: ");
                        scanf("  %c",&aux);
                        if(aux=='1'){
                             for (i = 0; i < FILAS; i++) {
        printf("Título: %s\n", registros[i].titulo);
        for (j = 0; j < COLUMNAS; j++) {
            printf("mes %d: %f GW\n", j+1, registros[i].datos[j]);
        }
        printf("\n");
    }
                        }

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

    }
    while(1);
    return 0;

}


void mostrar_introduccion(void){

    FILE *intro;
    char c;

  intro = fopen("descripcion.red.electrica.txt","r");
  if(intro==NULL){
    printf("Error en la introduccion");
  }
   while(fscanf(intro,"%c",&c)!=EOF){
    printf("%c",c);
   }

}









