double mediaSal( exportacion paises[FILAS2])
{
    double auxsal1=0;
float auxsal=0,sal=0;
for (int i = 0; i <FILAS2 ; i++)
    {
        printf("Pais: %s\n", paises[i].pais);
for (int j = 0; j < COLUMNAS2; j++)
    {
if ((j - 1) % 3 == 0)
{
}
else if ((j - 2) % 3 == 0)
{
}
else
{
    auxsal=paises[i].numeros[j];
    auxsal1=auxsal+auxsal1;
    sal++;
}
}
}
auxsal1=auxsal1/sal;


return auxsal1;
}
