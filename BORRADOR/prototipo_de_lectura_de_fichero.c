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
         while(i<25){

fscanf(fic,"%[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",datos[i].tipogen, &datos[i].num[0], &datos[i].num[1],  &datos[i].num[2],
                                                                                                 &datos[i].num[3],  &datos[i].num[4], &datos[i].num[5], &datos[i].num[6],
                                                                                                 &datos[i].num[7],  &datos[i].num[8], &datos[i].num[9], &datos[i].num[10],
                                                                                                 &datos[i].num[11], &datos[i].num[12],&datos[i].num[13],&datos[i].num[14],
                                                                                                  &datos[i].num[15], &datos[i].num[16],&datos[i].num[17], &datos[i].num[18],
                                                                                                 &datos[i].num[19], &datos[i].num[20], &datos[i].num[21],  &datos[i].num[22],
                                                                                                  &datos[i].num[23],  &datos[i].num[24]);

printf("%s  caracter\n\n\n, %f , %f ,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\nnuevlalinea\n",datos[i].tipogen,datos[i].num[0],datos[i].num[1],datos[i].num[2],
                                                                                                datos[i].num[3],datos[i].num[4],datos[i].num[5],datos[i].num[6],
                                                                                                datos[i].num[7],datos[i].num[8],datos[i].num[9],datos[i].num[10],
                                                                                                datos[i].num[11],datos[i].num[12],datos[i].num[13],datos[i].num[14],
                                                                                                datos[i].num[15],datos[i].num[16],datos[i].num[17],datos[i].num[18],
                                                                                                datos[i].num[19],datos[i].num[20],datos[i].num[21],datos[i].num[22],
                                                                                                datos[i].num[23],datos[i].num[24]);
     i++;
}

fclose(fic);




return 0;
}
}


