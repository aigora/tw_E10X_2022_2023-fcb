#include<stdio.h>


int main ()
{


    char op1,op2;




    printf("¡¡¡¡¡¡¡¡RED ELECTRICA!!!!!!!!!! ");//titulo 
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
