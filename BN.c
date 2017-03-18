#include <stdio.h>
#include <stdlib.h>

int ncb=0,i,j;
int main()
{
    printf("\t***************************************************************************************************\n");
    printf("\t********************************* B A T A L H A   N A V A L ***************************************\n");
    printf("\t***************************************************************************************************");

    printf("\n\n\n\t\t\t\t\t       :::::REGRAS:::::\n");
    printf("\t\t\t* CADA JOGADOR SO PODE REALIZAR UM ATAQUE POR TURNO\n"
           "\t\t\t* SE ACERTAR UM HOLANDES VOADOR, GANHA 50 PONTOS\n"
           "\t\t\t* SE ACERTAR UM PEROLA NEGRA, PERDE 50 PONTOS\n"
           "\t\t\t* SE ACERTAR UM SUBMARINO, GANHA 30 PONTOS\n"
           "\t\t\t* SE ACERTAR UMA PARTE DO ENCOURACADO, GANHA 5 PONTOS\n"
           "\t\t\t* GANHA O JOGADOR QUE ATINGIR 150 PONTOS PRIMEIRO, NO CAMPO 1\n"
           "\t\t\t* GANHA O JOGADOR QUE ATINGIR MAIS PONTOS EM 10 JOGADAS, NO CAMPO 2\n"
           "\t\t\t* GANHA O JOGADOR QUE ATINGIR 350 PONTOS PRIMEIRO, NO CAMPO 3\n"
           "\t\t\t* SE O JOGADOR ATINGIR OS 2 PEROLAS NEGRAS NO CAMPO 3, PERDE !!!");


    printf("\n\n\t\t\t\t\tOs campos de batalha disponiveis sao:\n\n");
    printf("\n\tCampo 1 = BAU DA MORTE\n\t6 linhas por 6 colunas, 6 submarinos, 1 encouracado e 1 perola negra\n\n"
             "\tCampo 2 = NO FIM DO MUNDO\n\t7 linhas por 8 colunas, 8 submarinos, 7 encouracados e 2 holandeses voadores\n\n"
             "\tCampo 3 = A MALDICAO DO PEROLA NEGRA\n\t10 linhas por 9 colunas, 15 submarinos, 10 encouracados, 3 holandeses voadores e 2 perolas negras\n");

    while (ncb<1 || ncb>3)
    {
      printf("\nDigite um numero valido de campo de batalha desejado : ");
      scanf("%d", &ncb);
    }

    switch (ncb)
    {
        case 1:
          printf("\n\tBAU DA MORTE ESCOLHIDO, CUIDADO, UM ERRO PODE SER FATAL\n");
        break;

        case 2:
          printf("\n\tFIM DO MUNDO ESCOLHIDO, QUE SOBREVIVA O MELHOR\n");
        break;

        case 3:
          printf("\n\tMALDICAO DO PEROLA NEGRA ESCOLHIDA, FACA O POSSIVEL PARA FUJIR DA MALDICAO\n");
          printf("\tOBS: ATINGIR 2 PEROLAS NEGRAS RESULTA EM DERROTA AUTOMATICA!\n");
        break;

    }

    return 0;
}
