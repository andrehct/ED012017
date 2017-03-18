#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j, vetor[10], vetorm[3][4];

    for (i=0;i<10;i++)
    {
       printf("insira o %d valor: ", i+1);
       scanf ("%d", &vetor[i]);
    }

     for (i=0;i<10;i++)
    {
        printf("o %d valor do vetor e: %d\n", i+1,vetor[i]);
    }


    printf("\n\n\n\n\ninsira os 12 valores da matriz: ");

    for (i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
          scanf ("%d", &vetorm[i][j]);
        }
    }


    for (i=0;i<3;i++)
    {
        printf("\n");
        for(j=0;j<4;j++)
        {
            printf("\t%d", vetorm[i][j]);
        }
    }
    return 0;
}
