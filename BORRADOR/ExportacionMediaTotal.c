double mediaExportaciones( exportacion paises[FILAS2])
{
    double auxex1=0;
    float auxex=0,exporta=0;
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
else
{

}
}
}
auxex1=auxex1/exporta;
return auxex1;
}
