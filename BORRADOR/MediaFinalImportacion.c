double mediaImportacion( exportacion paises[FILAS2])
{
    double auxim1=0;
float auxim=0,importa=0;
for (int i = 0; i <FILAS2 ; i++)
    {
        printf("Pais: %s\n", paises[i].pais);
for (int j = 0; j < COLUMNAS2; j++)
    {
if ((j - 2) % 3 == 0)
{
    auxim=paises[i].numeros[j];
    auxim1=auxim+auxim1;
    importa++;
}
else
{
}
}
}
auxim1=auxim1/importa;


return auxim1;
}
