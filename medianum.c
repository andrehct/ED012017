
#include <stdio.h>
#include <stdlib.h>

float media (int *valores, int n);
float res=0;
int i,n;

int main()
{
    printf("Insira quantos valores serao utilizados para a media: ");
    scanf("%d", &n);

    int *valores = (int*) malloc(n*sizeof(int));

    for(i=0;i<n;i++)
    {
       printf("Insira o %d valor: ", i+1);
       scanf("%d", &valores[i]);
    }

    media (valores, n);

    printf("\n A media dos valores e: %.2f", res);
    
    free(valores);
    
    return 0;
}

float media (int *valores, int n)
{
    for(i=0;i<n;i++)
    {
        res+=valores[i];
    }

    res=res/n;

    return res;
}
