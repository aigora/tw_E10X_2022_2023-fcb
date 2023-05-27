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


double emax2021(Energias tipo)
{
    double maxima = tipo.datos[0];
    int x;
    for(x=0;x<=(COLUMNAS/2);x++)
    {
        if(tipo.datos[x]>maxima) maxima=tipo.datos[x];
    }

return maxima;
}

double emax2022(Energias tipo)
{
    double maxima = tipo.datos[0];
    int x;
    for(x=(COLUMNAS/2);x<=(COLUMNAS);x++)
    {
        if(tipo.datos[x]>maxima) maxima=tipo.datos[x];
    }

return maxima;
}
//HAY QUE REVISAR ESTA FUNCION DE emax2022 PORQ NO DA EL RESULTADO CORRECTO!!!!
double minimo2021(Energias tipo){
  double res=tipo.datos[0];
  int i=0;
  while(i<(COLUMNAS/2)){
    if(tipo.datos[i]< res)res=tipo.datos[i];
    i++;
  }

return res;
}

double minimo2022(Energias tipo){
  double res=tipo.datos[0];
  int i=12;
  while(i<(COLUMNAS)){
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
                            mercados(registros);


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
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[0]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[0]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[0]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[0]));
                        printf("\n\n");
                        break;

                    case 'b':
                        system("cls");
                        printf("Estadisticas para Turbinacion bombeo:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[1]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[1]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[1]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[1]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[1]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[1]));
                        printf("\n\n");
                        break;

                    case 'c':
                        system("cls");
                        printf("Estadisticas para Nuclear:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[2]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[2]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[2]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[2]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[2]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[2]));
                        printf("\n\n");
                        break;

                    case 'd':
                        system("cls");
                        printf("Estadisticas para Carbon:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[3]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[3]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[3]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[3]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[3]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[3]));
                        printf("\n\n");
                        break;

                    case 'e':
                        system("cls");
                        printf("Estadisticas para Motores diesel:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[4]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[4]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[4]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[4]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[4]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[4]));
                        printf("\n\n");
                        break;

                    case 'f':
                        system("cls");
                        printf("Estadisticas para Turbina de gas:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[5]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[5]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[5]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[5]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[5]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[5]));
                        printf("\n\n");
                        break;

                    case 'g':
                        system("cls");
                        printf("Estadisticas para Turbina de vapor:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[6]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[6]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[6]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[6]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[6]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[6]));
                        printf("\n\n");
                        break;

                    case 'h':
                        system("cls");
                        printf("Estadisticas para Ciclo combinado:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[7]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[7]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[7]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[7]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[7]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[7]));
                        printf("\n\n");
                        break;

                    case 'i':
                        system("cls");
                        printf("Estadisticas para Hidroeolica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[8]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[8]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[8]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[8]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[8]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[8]));
                        printf("\n\n");
                        break;

                    case 'j':
                        system("cls");
                        printf("Estadisticas para Eolica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[9]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[9]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[9]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[9]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[9]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[9]));
                        printf("\n\n");
                        break;

                    case 'k':
                        system("cls");
                        printf("Estadisticas para Solar fotovoltaica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[10]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[10]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[10]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[10]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[10]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[10]));
                        printf("\n\n");
                        break;

                    case 'l':
                        system("cls");
                        printf("Estadisticas para Solar termica:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[11]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[11]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[11]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[11]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[11]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[11]));
                        printf("\n\n");
                        break;

                    case 'm':
                        system("cls");
                        printf("Estadisticas para Otras renovables:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[12]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[12]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[12]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[12]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[12]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[12]));
                        printf("\n\n");
                        break;

                    case 'n':
                        system("cls");
                        printf("Estadisticas para Coogeneracion:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[13]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[13]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[13]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[13]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[13]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[13]));
                        printf("\n\n");
                        break;

                    case 'o':
                        system("cls");
                        printf("Estadisticas para Residuos no renovables:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[14]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[14]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[14]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[14]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[14]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[14]));
                        printf("\n\n");
                        break;

                    case 'p':
                        system("cls");
                        printf("Estadisticas para Residuos renovables:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[15]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[15]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[15]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[15]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[15]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[15]));
                        printf("\n\n");
                        break;

                    case 'q':
                        system("cls");
                        printf("Estadisticas para Generacion total:\n");
                        printf("\tValor minimo en 2021: %.2f GW\n", minimo2021(registros[16]));
                        printf("\tValor maximo en 2021: %.2f GW\n", emax2021(registros[16]));
                        printf("\tValor minimo en 2022: %.2f GW\n", minimo2022(registros[16]));
                        printf("\tValor maximo en 2022: %.2f GW\n", emax2022(registros[16]));
                        printf("\tGeneracion media 2021: %.2f GW\n", mediaprimerano(registros[16]));
                        printf("\tGeneracion media 2022: %.2f GW\n", mediasegundoano(registros[16]));
                        printf("\n\n");
                        break;

                    default:
                        printf("\n    Opcion no valida");
                        break;
                }



}


void mercados(Energias registros[FILAS]){


       char aux,aux2,aux3;

       system("cls");

       printf("...........HAS ENTRADO EN LA OPCION MERCADOS.............\n");

       while(aux!='q'){

        printf("\t 1. Consultar precio de la luz\n\t 2. Comercio\n\t 3. salir\n");
         scanf(" %c",&aux);

           switch(aux){

           case '1':

             printf("\n1. Nivel comercial\n2. Nivel industrial.\n");
             scanf("  %c",&aux2);

                 switch(aux2){
                case '1':
                    printf("\nEl precio de la luz para el consumidor es de ...\n");
                    break;

                case '2':
                    printf("\nEl precio de la luz para el uso industrial es de  ...\n");
                    break;

                default:
                    printf("\n estamos trabajando en ello \n");
                    break;
                 }

             break;

                case '2':

                    printf("\nEspaña exportta....\n");

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








