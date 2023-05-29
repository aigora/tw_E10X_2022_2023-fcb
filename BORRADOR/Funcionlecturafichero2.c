void exportaciones(exportacion paises[FILAS2]){
    char aux,aux1;

        while(aux!='q'){//bucle submenu base de datos.
printf("\n.......HAS ENTRADO EN EXPORTACIONES.......\n");
            printf("seleccione la opcion que desea realizar\n");
            printf(" \t 1.Mostrar datos \n\t 2.\n\t 3. \n\t 4.salir de exportaciones \n");
            scanf("  %c",&aux);



                        switch(aux){


                        case '1':
                             system("cls");
                              for (int i = 0; i <FILAS2 ; i++) {
                             printf("Pais: %s\n", paises[i].pais);
                              for (int j = 0; j < COLUMNAS2; j++) {
                                    if ((j - 1) % 3 == 0)
                                    {
                                       printf("Exportacion: %f GW \n", paises[i].numeros[j]);
                                    }
                                    else if ((j - 2) % 3 == 0)
                                    {
                                       printf("Importacion: %f GW \n", paises[i].numeros[j]);
                                    }
                                    else
                                    {
                                        printf("Saldo: %f GW \n", j+1, paises[i].numeros[j]);
                                    }

                                                          }
                                            printf("\n\n\n");
                                           }

                            break;







                        case '2'://datos estadísticos.



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


                            break;

                            default :
                                printf("\ncaracter no valido\n");
                                break;


                        }
                        }



}
