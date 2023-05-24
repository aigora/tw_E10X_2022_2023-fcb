#include<stdio.h>

typedef struct{
    int mes;
    int an;
}fecha;



typedef struct{
    fecha f[24];
    char tipogen[15];
    float num[24];
}tipo_energia;


int main(){

    FILE *fic;
    tipo_energia datos[30];
    char c,aux;
    int i=0;


    fic = fopen("generacion_por_tecnologias_21_22_puntos.csv","r");

    if (fic==NULL){
        printf("Error al abrir el fichero");
        return -1;
    }
    else{
         fseek(fic, 408, SEEK_SET);//punto óptimo
         for(i=0; i<25; i++)
         {
             for (int j=0; j<25; j++)
             {
                 fscanf(fic,"%[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",datos[i].tipogen, &datos[i].num[j]);

                 printf("%s  caracter\n\n\n, %f , %f ,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\nnuevlalinea\n",datos[i].tipogen,datos[i].num[j]);
             }
         }

fclose(fic);




return 0;
}
}
