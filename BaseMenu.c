#include<stdio.h>

int main ()
{
    char op1,op2;
    printf(" FCB ");
    do
    {
        printf("\n\n MENU PRINCIPAL\n\n 1. Instrucciones\n\n 2. Base de Datos \n\n 3. Salir\n\n Opcion: ");
        scanf(" %c",&op1);

        switch(op1)
        {
            case '1':
                  printf("\n Instrucciones:");

             break;

             case '2':
                     printf("\n Base de Datos");

              break;

              case '3':
                printf("\n    Estas seguro de que quieres salir (S o N)?: ");
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
