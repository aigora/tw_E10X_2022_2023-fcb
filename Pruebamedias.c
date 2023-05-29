
float auxex=0,auxex1=0,exporta=0,auxim=0,auxim1=0,importa=0,sal=0,auxsal=0,auxsal1=0;
for (int i = 0; i <FILAS2 ; i++)
    {
        printf("Pais: %s\n", paises[i].pais);
for (int j = 0; j < COLUMNAS2; j++)
    {
if ((j - 1) % 3 == 0)
{
auxex=paises[i].numeros[j];
auxex1=auxex+auxex1;
exporta++;
}
else if ((j - 2) % 3 == 0)
{
    auxim=paises[i].numeros[j];
    auxim1=auxim+auxim1;
    importa++;
}
else
{
    auxsal=paises[i].numeros[j];
    auxsal1=auxsal+auxsal1;
    sal++;
}
}
}
auxex1=auxex1/exporta;
auxim1=auxim1/importa;
auxsal1=auxsal1/sal;


