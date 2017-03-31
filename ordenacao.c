#include <stdio.h>
#include <stdlib.h>
#define max 350
int cont=0,i=0,min,j,aux,n,x=0;
long int vetor[max],c1[max],c2[max];

void selecao (long int vetor[], int n);
void insercao (long int c1[], int n);
void bolha (long int c2[], int n);

int main()
{
    int num;
    FILE *arq;
    FILE *saida;
    arq=fopen("entrada_proj4.txt","r"); /*abrindo o arquivo para leitura*/
    printf("O arquivo de entrada deve ter o nome 'entrada_proj4' e ser um arquivo txt\n");
    printf("*************************************************************************\n");
    if (!arq) /*se o arquivo não for encontrado será enviado uma mensagem de erro*/
    {
        printf ("\nErro, arquivo nao encontrado");
        exit (1);
    }

    while (fscanf(arq,"%li",&vetor[i])!= EOF) /*lendo os números do vetor*/
    {
        ++i;
    }
    n=i;

    fclose(arq); /*fechando o arquivo*/

    for(j=0;j<n;j++)
    {
        c1[j]=vetor[x]; /*copiando o vetor 'vetor' para o vetor 'c1'*/
        x++;
    }

    x=0;

    for(j=0;j<n;j++)
    {
        c2[j]=vetor[x]; /*copiando o vetor 'vetor' para o vetor 'c2'*/
        x++;
    }

    selecao(vetor,n); /*chamando função*/
    insercao (c1,n); /*chamando função*/
    bolha (c2,n); /*chamando função*/

    printf("*************************************************************************\n");
    printf("vetor ordenado:\n");

    for(i=0;i<=n;i++)
    {
        printf("%li\n", vetor[i]);
    }

    saida=fopen("saida_proj4.txt","w");
    for(i=0;i<=n;i++)
    {
        fprintf(saida,"%li  ", vetor[i]);
    }
    fclose(saida);

    return 0;
}

void selecao (long int vetor[],int n)
{
    for (i=0;i<n;i++)
    {
        min=i; /*assumindo hipotese de que a posição 'i' é a que contém o menor valor restante do vetor*/
        for (j=i+1;j<=n;j++) /*'j' vai procurar em todo vetor restante um valor menor que o da posição 'i'*/
        {
            cont++; /*para cada comparação feita, soma-se +1 no 'cont'*/
            if(vetor[j]<vetor[min]) /*se houver valor na posição 'j' menor que o valor da posição 'min', 'min' será igual a ela*/
            {
                min=j;
            }
        }
        if (min != i) /*se 'min' tiver sido alterado, faremos a troca de posições*/
        {
            aux=vetor[i]; /*trocando as posições*/
            vetor[i]=vetor[min];/*trocando as posições*/
            vetor[min]=aux; /*trocando as posições*/
            cont++;  /*para cada troca feita, soma-se +1 no 'cont'*/
        }
    }

    printf("\npassos em selecao=%d\n", cont);

    cont=0;
}

void insercao(long int c1[], int n)
{
    x=0;
    for (i=1;i<=n;i++) /*'i' começará na 2 posição do vetor, para sempre compararmos com o anterior a 'i'*/
    {
        x=c1[i]; /*'x' armazenará o valor de v[i]*/
        j=i-1; /*'j' estará sempre uma posição antes de 'i' para fazer a comparação*/
        if(c1[j]<x) /*Se 'x' for maior que o v[j], não entrará no laço 'for', porém será somado a comparação feita no número de passos*/
        {
            cont++;
        }

        for (j=i-1;j>=0 && c1[j]>x;j--) /*se v[j] for maior que 'x', entrará no laço 'for' e realizará a troca de posições*/
        {
            c1[j+1]=c1[j]; /*trocando as posições*/
            c1[j]=x;      /*trocando as posições*/
            cont+=2;  /*aumenta de 2 em 2 pois é somada a comparação + a troca*/
            if(j-1>=0 && c1[j-1]<c1[j]) /*Se o número anterior for menor que o v[j], será somado a comparação feita no número de passos*/
            {
                cont++;
            }
        }

    }

    printf ("\npassos em insercao=%d\n", cont);
    cont=0;
}

void bolha (long int c2[],int n)
{
    for(i=0;i<n;i++)
    {
        for(j=n;j>i;j--)
        {
            if(c2[j]<c2[i])
            {
                cont+=2; /*se houver troca, será somado ao 'cont' o passo de comparação e troca, logo 2 passos*/
                aux=c2[i]; /*trocando as posições*/
                c2[i]=c2[j];/*trocando as posições*/
                c2[j]=aux; /*trocando as posições*/
            }
            else
            {
                cont++; /*se não houver troca, soma-se o passo de comparação ao 'cont'*/
            }
        }
    }

    printf("\npassos por bolha=%d\n\n",cont);

}
