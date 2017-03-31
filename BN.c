/*Universidade de Brasília
  Estrutura de Dados
  Nome: André Heládio de Carvalho Thomas
  Matrícula: 160112036
  Data: 07/04/2017*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX 20

int ncb=0,i=0,j=0,lin=0,col=0,c=0,p1=0,p2=0, a=0,b=0,aux=0, pnj1=0, pnj2=0, ch=0, vp[4], k=0, l=0;
char name[MAX],name2[MAX],d,D, **cb, **cb2;

void MAPA ();
void criabarcos(char **cb, char **cb2);
void jogadas (char **cb, char **cb2, int *vp);
void final (char **cb, char **cb2, int *vp, char *name, char *name2);

typedef struct Repete
{
	int x;
	int y;
} repete;

int main()
{

    cb=(char **) malloc(10*sizeof(char *));
    cb2=(char **) malloc(10*sizeof(char *));

    printf("\t***************************************************************************************************\n");
    printf("\t********************************* B A T A L H A   N A V A L ***************************************\n");
    printf("\t***************************************************************************************************");

    printf("\n\n\n\t\t\t\t\t       :::::REGRAS:::::\n"
           "\t\t\t* CADA JOGADOR SO PODE REALIZAR UM ATAQUE POR TURNO\n"
           "\t\t\t* VENCE O JOGADOR QUE ATINGIR 400 PONTOS PRIMEIRO\n"
           "\t\t\t* O ENCOURACADO E FORMADO POR 4 PARTES\n"
           "\t\t\t* O HOLANDES VOADOR E FORMADO POR 2 PARTES\n"
           "\t\t\t* SUBMARINOS E PEROLAS NEGRAS TEM APENAS 1 PARTE\n"
           "\t\t\t* SE ACERTAR UMA PARTE DO HOLANDES VOADOR (H), GANHA 50 PONTOS\n"
           "\t\t\t* SE ACERTAR UM PEROLA NEGRA (P), PERDE 50 PONTOS\n"
           "\t\t\t  OBS: ACERTAR 2 PEROLAS NEGRAS RESULTA EM DERROTA AUTOMATICA!\n"
           "\t\t\t* SE ACERTAR UM SUBMARINO (S), GANHA 30 PONTOS\n"
           "\t\t\t* SE ACERTAR UMA PARTE DO ENCOURACADO (E), GANHA 5 PONTOS\n"
           "\t\t\t* SE ACERTAR UM BAU DA GANANCIA (B) PODERA OPTAR POR ABRI-LO OU NAO\n"
           "\t\t\t* CASO ABRA, HA CHANCE DE 3 EVENTOS ACONTECEREM:\n"
           "\t\t\t* EVENTO 1= O JOGADOR ROUBA 50 PONTOS DO ADVERSARIO\n"
           "\t\t\t* EVENTO 2= O JOGADOR PERDE 100 PONTOS PARA O ADVERSARIO\n"
           "\t\t\t* EVENTO 3= O JOGADOR TERA 1/3 DE SEUS PONTOS ADICIONADOS A PONTUACAO\n");


    printf("\n\t\tINSIRA O NOME DO JOGADOR 1: ");
    do
    {
        d= getchar();
        D=toupper(d);
        name[i]=D;
        ++i;
    }while (d != '\n');
    name[i-1]='\0';

    i=0;
    printf("\n\t\tINSIRA O NOME DO JOGADOR 2: ");
    do
    {
        d= getchar();
        D=toupper(d);
        name2[i]=D;
        ++i;
    }while (d != '\n');
    name2[i-1]='\0';

    srand(time(NULL));

    MAPA();
    criabarcos(cb, cb2);
    jogadas(cb,cb2, vp);
    final (cb, cb2, vp, name, name2);

    return 0;
}

void MAPA ()
{
    /*CRIANDO O CAMPO DO P1*/

    for(i=0;i<10;i++)
    {
        cb[i]=(char *) malloc(10*sizeof(char));
    }

    for(i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            cb[i][j]= 'X';
        }
    }

    /*CRIANDO O CAMPO DO P2*/

    for(i=0;i<10;i++)
    {
        cb2[i]=(char *) malloc(10*sizeof(char));
    }

    for(i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            cb2[i][j]= 'X';
        }
    }
}

void criabarcos(char **cb, char **cb2)
{
    /*CRIANDO OS ENCOURACADOS P1*/

    for(aux=0;aux<5;aux++) /*Laço vai rodar 5x, em cada vez, cria um encouracado*/
    {
        c= rand()%10; /*gera um numero entre 0 e 9, para decidir se o encouracado vai ficar na horizontal(c<5) ou vertical (c>4)*/
        if (c>4) /*Encouracado fica todo em uma coluna*/
        {
           do
           {
              lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
              if(lin>6) /*Controle para o encouracado ser sorteado em uma coluna que o caiba*/
              {
                  lin= rand()%7;
              }
              col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
           }while(cb[lin][col] != 'X' || cb[lin+1][col] != 'X' || cb[lin+2][col] != 'X' || cb[lin+3][col] != 'X'); /*varrendo as outras posições necessárias para confirmar que o encouracado pode ser criado*/

            j=lin+4;
            for(i=lin;i<j;i++)
            {
                cb[i][col] = 'E';
            }
        }

        if (c<5) /*Encouracado fica todo em uma linha*/
        {
           do
           {
              lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
              col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
              if(col>6) /*Controle para o encouracado ser sorteado em uma linha que o caiba*/
              {
                  col= rand()%7;
              }
           }while(cb[lin][col] != 'X' || cb[lin][col+1] != 'X' || cb[lin][col+2] != 'X' || cb[lin][col+3] != 'X'); /*varrendo as outras posições necessárias para confirmar que o encouracado pode ser criado*/

            i=col+4;
            for(j=col;j<i;j++)
            {
                cb[lin][j] = 'E';
            }
        }
    }

    /*CRIANDO OS HOLANDESES VOADOR P1*/

    for(aux=0;aux<3;aux++) /*Laço vai rodar 3x, em cada vez, cria um holandes voador*/
    {
        c= rand()%10; /*gera um numero entre 0 e 9, para decidir se o holandes voador vai ficar na horizontal(c<5) ou vertical (c>4)*/
        if (c>4) /*Holandes voador fica todo em uma coluna*/
        {
           do
           {
              lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
              if(lin>8) /*Controle para o holandes voador ser sorteado em uma coluna que o caiba*/
              {
                  lin= rand()%9;
              }
              col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
           }while(cb[lin][col] != 'X' || cb[lin+1][col] != 'X'); /*varrendo as outras posições necessárias para confirmar que o holandes voador pode ser criado*/

            j=lin+1;
            for(i=lin;i<j;i++)
            {
                cb[i][col] = 'H';
            }
        }

        if (c<5) /*Holandes voador fica todo em uma linha*/
        {
           do
           {
              lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
              col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
              if(col>8) /*Controle para o holandes voador ser sorteado em uma linha que o caiba*/
              {
                  col= rand()%9;
              }
           }while(cb[lin][col] != 'X' || cb[lin][col+1] != 'X'); /*varrendo as outras posições necessárias para confirmar que o holandes voador pode ser criado*/

            i=col+1;
            for(j=col;j<i;j++)
            {
                cb[lin][j] = 'H';
            }
        }
    }

    /*CRIANDO OS SUBMARINOS P1*/

        for(aux=0;aux<5;aux++) /*Laço vai rodar 5x, em cada vez, cria um submarino*/
        {
            do
            {
                lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
                col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
            }while(cb[lin][col]!= 'X'); /*Controle para gerar uma posição válida no mapa*/

           cb[lin][col]= 'S';
        }

    /*CRIANDO OS PEROLAS NEGRAS P1*/

    for(aux=0;aux<2;aux++) /*Laço vai rodar 2x, em cada vez, cria um perola negra*/
    {
       do
       {
          lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
          col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
       }while(cb[lin][col]!= 'X'); /*Controle para gerar uma posição válida no mapa*/

        cb[lin][col]= 'P';
    }

    /*CRIANDO OS BAUS DA GANANCIA P1*/

    for(aux=0;aux<2;aux++)
    {
        do
        {
           lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
           col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
        }while(cb[lin][col]!= 'X'); /*Controle para gerar uma posição válida no mapa*/

        cb[lin][col]= 'B';
    }

    /*CRIANDO OS ENCOURACADOS P2*/

    for(aux=0;aux<5;aux++) /*Laço vai rodar 5x, em cada vez, cria um encouracado*/
    {
        c= rand()%10; /*gera um numero entre 0 e 9, para decidir se o encouracado vai ficar na horizontal(c<5) ou vertical (c>4)*/
        if (c>4) /*Encouracado fica todo em uma coluna*/
        {
           do
           {
              lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
              if(lin>6) /*Controle para o encouracado ser sorteado em uma coluna que o caiba*/
              {
                  lin= rand()%7;
              }
              col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
           }while(cb2[lin][col] != 'X' || cb2[lin+1][col] != 'X' || cb2[lin+2][col] != 'X' || cb2[lin+3][col] != 'X'); /*varrendo as outras posições necessárias para confirmar que o encouracado pode ser criado*/

            j=lin+4;
            for(i=lin;i<j;i++)
            {
                cb2[i][col] = 'E';
            }
        }

        if (c<5) /*Encouracado fica todo em uma linha*/
        {
           do
           {
              lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
              col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
              if(col>6) /*Controle para o encouracado ser sorteado em uma linha que o caiba*/
              {
                  col= rand()%7;
              }
           }while(cb2[lin][col] != 'X' || cb2[lin][col+1] != 'X' || cb2[lin][col+2] != 'X' || cb2[lin][col+3] != 'X'); /*varrendo as outras posições necessárias para confirmar que o encouracado pode ser criado*/

            i=col+4;
            for(j=col;j<i;j++)
            {
                cb2[lin][j] = 'E';
            }
        }
    }

    /*CRIANDO OS HOLANDESES VOADOR P2*/

    for(aux=0;aux<3;aux++) /*Laço vai rodar 3x, em cada vez, cria um holandes voador*/
    {
        c= rand()%10; /*gera um numero entre 0 e 9, para decidir se o holandes voador vai ficar na horizontal(c<5) ou vertical (c>4)*/
        if (c>4) /*Holandes voador fica todo em uma coluna*/
        {
           do
           {
              lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
              if(lin>8) /*Controle para o holandes voador ser sorteado em uma coluna que o caiba*/
              {
                  lin= rand()%9;
              }
              col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
           }while(cb2[lin][col] != 'X' || cb2[lin+1][col] != 'X'); /*varrendo as outras posições necessárias para confirmar que o holandes voador pode ser criado*/

            j=lin+1;
            for(i=lin;i<j;i++)
            {
                cb2[i][col] = 'H';
            }
        }

        if (c<5) /*Holandes voador fica todo em uma linha*/
        {
           do
           {
              lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
              col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
              if(col>8) /*Controle para o holandes voador ser sorteado em uma linha que o caiba*/
              {
                  col= rand()%9;
              }
           }while(cb2[lin][col] != 'X' || cb2[lin][col+1] != 'X'); /*varrendo as outras posições necessárias para confirmar que o holandes voador pode ser criado*/

            i=col+1;
            for(j=col;j<i;j++)
            {
                cb2[lin][j] = 'H';
            }
        }
    }

    /*CRIANDO OS SUBMARINOS P2*/

        for(aux=0;aux<5;aux++) /*Laço vai rodar 5x, em cada vez, cria um submarino*/
        {
            do
            {
                lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
                col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
            }while(cb2[lin][col]!= 'X'); /*Controle para gerar uma posição válida no mapa*/

           cb2[lin][col]= 'S';
        }

    /*CRIANDO OS PEROLAS NEGRAS P2*/

    for(aux=0;aux<2;aux++) /*Laço vai rodar 2x, em cada vez, cria um perola negra*/
    {
       do
       {
          lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
          col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
       }while(cb2[lin][col]!= 'X'); /*Controle para gerar uma posição válida no mapa*/

        cb2[lin][col]= 'P';
    }

    /*CRIANDO OS BAUS DA GANANCIA P2*/

    for(aux=0;aux<2;aux++)
    {
        do
        {
           lin= rand()%10; /*gera um numero entre 0 e 9 para decidir uma linha*/
           col= rand()%10; /*gera um numero entre 0 e 9 para decidir uma coluna*/
        }while(cb2[lin][col]!= 'X'); /*Controle para gerar uma posição válida no mapa*/

        cb2[lin][col]= 'B';
    }
}

void jogadas (char **cb, char **cb2, int *vp)
{
    /*LEITURA DAS JOGADAS, ATE QUE A PONTUAÇÃO ESTABELECIDA SEJA ATINGIDA OU ALGUM JOGADOR ACERTE OS 2 PEROLAS NEGRAS*/

    repete joga1[100]={0}, joga2[100]={0}; /*Struct que vai armazenar as jogadas ja realizadas, para nao haver repeticoes*/
    i=0;
    j=0;

    while(p1<400 && p2<400 && pnj1<2 && pnj2<2)
    {
       /*VEZ DO JOGADOR 1*/
       a=0;
       b=0;
       while(a<1 || a>10 || b<1 || b>10)
       {
          printf("\n\n\tVEZ DE %s, DIGITE UMA LINHA (1-10) E UMA COLUNA (1-10): ", name);
          scanf("%d %d", &a, &b);
       }
       joga1[i].x=a; /*Armazenando as coordenadas ja jogadas pelo jogador em um vetor de struct*/
       joga1[i].y=b; /*Armazenando as coordenadas ja jogadas pelo jogador em um vetor de struct*/
       if(i != 0) /*a primeira jogada não será examinada*/
       {
          for(k=0;k<i;k++) /*Laco para varrer todo o vetor de struct, até a última jogada realizada*/
           {
       	       if (joga1[k].x== a && joga1[k].y== b) /*Teste para saber se a jogada é repetida*/
       	       {
       		       printf("\n\t\t**********JOGADA JA REALIZADA**********\n");
       		       a=0;
       		       b=0;
       		       while(a<1 || a>10 || b<1 || b>10)
                   {
                      printf("\n\n\tVEZ DE %s, DIGITE UMA LINHA (1-10) E UMA COLUNA (1-10): ", name);
                      scanf("%d %d", &a, &b);
                   }
                   k=-1; /*Variavel 'k' será incrementada quando passar pelo 'for' novamente, tendo o valor inicial de 0. Isso acontecerá toda vez que o usuário tiver que digtar as coordenadas do ataque*/
       	       } 
           }
       }

       lin=a-1;
       col=b-1;

       if (cb2[lin][col]!= 'X')
       {
           if(cb2[lin][col]== 'E')
           {
               p1+=5;
               printf("\n\tPARTE DE ENCOURACADO ATINGIDA, %s GANHA 5 PONTOS!!\n", name);
               printf("\tPONTUACAO DE %s= %d\n", name, p1);
               printf("\t------------------------------------------------------\n");
           }
           if(cb2[lin][col]== 'S')
           {
               p1+=30;
               printf("\n\tSUBMARINO ATINGIDO, %s GANHA 30 PONTOS!!\n", name);
               printf("\tPONTUACAO DE %s= %d\n", name, p1);
               printf("\t------------------------------------------------------\n");
           }
           if(cb2[lin][col]== 'H')
           {
               p1+=50;
               printf("\n\tPARTE DE HOLANDES VOADOR ATINGIDO, %s GANHA 50 PONTOS!!\n", name);
               printf("\tPONTUACAO DE %s= %d\n", name, p1);
               printf("\t------------------------------------------------------\n");
           }
           if(cb2[lin][col]== 'P')
           {
               p1-=50;
               pnj1+=1;
               printf("\n\tPEROLA NEGRA ATINGIGO, %s PERDE 50 PONTOS!!\n", name);
               printf("\tPONTUACAO DE %s= %d\n", name, p1);
               printf("\t------------------------------------------------------\n");
           }
           if(cb2[lin][col]=='B')
           {
               ch=0;
               while (ch != 1 && ch != 2)
               {
                  printf("\n\tBAU DA MORTE ATINGIDO, DESEJA ABRI-LO? SE SIM, DIGITE 1, CASO CONTRARIO, DIGITE 2 : ");
                  scanf("%d", &ch);
               }

               if(ch==1)
               {
                  aux= rand()%3; /*Sorteia um valor entre 0 e 2*/
                  aux=aux+1; /*Agora, 'aux' terá um numero entre 1 e 3, correspondente ao evento do bau citado nas regras*/
                  switch(aux)
                  {
                     case 1:
                       p1+=50;
                       p2-=50;
                       printf("\n\tEVENTO 1 SORTEADO! %s ROUBA 50 PONTOS DE %s !! \n", name, name2);
                       printf("\tPONTUACAO DE %s= %d\n", name, p1);
                       printf("\t------------------------------------------------------\n");
                       break;
                     case 2:
                       p1-=100;
                       p2+=100;
                       printf("\n\tEVENTO 2 SORTEADO! %s PERDE 100 PONTOS PARA  %s !! \n", name, name2);
                       printf("\tPONTUACAO DE %s= %d\n", name, p1);
                       printf("\t------------------------------------------------------\n");
                       break;
                     case 3:
                       p1+=(p1/3);
                       printf("\n\tEVENTO 3 SORTEADO! %s TERA 1/3 DE SEUS PONTOS SOMADOS A PONTUACAO !! \n",name);
                       printf("\tPONTUACAO DE %s= %d\n", name, p1);
                       printf("\t------------------------------------------------------\n");
                       break;
                   }
               }
               if(ch==2)
               {
                   printf("\n\tBAU DA MORTE NAO SERA ABERTO\n");
                   printf("\tPONTUACAO DE %s= %d\n", name, p1);
                   printf("\t------------------------------------------------------\n");
               }

            }
       }
       else
       {
           printf("\n\tNENHUM ALVO ATINGIDO!! BOA SORTE NA PROXIMA JOGADA!!\n");
           printf("\tPONTUACAO DE %s= %d\n", name, p1);
           printf("\t------------------------------------------------------\n");
       }

       /*VEZ DO JOGADOR 2*/
       a=0;
       b=0;
       while(a<1 || a>10 || b<1 || b>10)
       {
          printf("\n\n\tVEZ DE %s, DIGITE UMA LINHA (1-10) E UMA COLUNA (1-10): ",name2);
          scanf("%d %d", &a, &b);
       }

       joga2[j].x=a; /*Armazenando as coordenadas ja jogadas pelo jogador em um vetor de struct*/
       joga2[j].y=b; /*Armazenando as coordenadas ja jogadas pelo jogador em um vetor de struct*/
       if(j != 0) /*a primeira jogada não será examinada*/
       {
          for(k=0;k<j;k++) /*Laco para varrer todo o vetor de struct, até a última jogada realizada*/
           {
       	       if (joga2[k].x== a && joga2[k].y== b) /*Teste para saber se a jogada é repetida*/
       	       {
       		       printf("\n\t\t**********JOGADA JA REALIZADA**********\n");
       		       a=0;
       		       b=0;
       		       while(a<1 || a>10 || b<1 || b>10)
                   {
                      printf("\n\n\tVEZ DE %s, DIGITE UMA LINHA (1-10) E UMA COLUNA (1-10): ", name2);
                      scanf("%d %d", &a, &b);
                   }
                   k=-1;  /*Variavel 'k' será incrementada quando passar pelo 'for' novamente, tendo o valor inicial de 0. Isso acontecerá toda vez que o usuário tiver que digtar as coordenadas do ataque*/
       	       } 
           }
       }
       lin=a-1;
       col=b-1;

       if (cb[lin][col]!= 'X')
       {
           if(cb[lin][col]== 'E')
           {
               p2+=5;
               printf("\n\tPARTE DE ENCOURACADO ATINGIDA, %s GANHA 5 PONTOS!!\n",name2);
               printf("\tPONTUACAO DE %s= %d\n", name2,p2);
               printf("\t------------------------------------------------------\n");
           }
           if(cb[lin][col]== 'S')
           {
               p2+=30;
               printf("\n\tSUBMARINO ATINGIDO, %s GANHA 30 PONTOS!!\n",name2);
               printf("\tPONTUACAO DE %s= %d\n", name2,p2);
               printf("\t------------------------------------------------------\n");
           }
           if(cb[lin][col]== 'H')
           {
               p2+=50;
               printf("\n\tPARTE DE HOLANDES VOADOR ATINGIDO, %s GANHA 50 PONTOS!!\n",name2);
               printf("\tPONTUACAO DE %s= %d\n", name2,p2);
               printf("\t------------------------------------------------------\n");
           }
           if(cb[lin][col]== 'P')
           {
               p2-=50;
               pnj2+=1;
               printf("\n\tPEROLA NEGRA ATINGIGO, %s PERDE 50 PONTOS!!\n",name2);
               printf("\tPONTUACAO DE %s= %d\n", name2,p2);
               printf("\t------------------------------------------------------\n");
           }
           if(cb[lin][col]=='B')
           {
               ch=0;
               while (ch != 1 && ch != 2)
               {
                  printf("\n\tBAU DA MORTE ATINGIDO, DESEJA ABRI-LO? SE SIM, DIGITE 1, CASO CONTRARIO, DIGITE 2 : ");
                  scanf("%d", &ch);
               }

               if(ch==1)
               {
                  aux= rand()%3; /*Sorteia um valor entre 0 e 2*/
                  aux=aux+1; /*Agora, 'aux' terá um numero entre 1 e 3, correspondente ao evento do bau citado nas regras*/
                  switch(aux)
                  {
                     case 1:
                       p2+=50;
                       p1-=50;
                       printf("\n\tEVENTO 1 SORTEADO! %s ROUBA 50 PONTOS DO %s !! \n",name2, name);
                       printf("\tPONTUACAO DE %s= %d\n", name2,p2);
                       printf("\t------------------------------------------------------\n");
                       break;
                     case 2:
                       p2-=100;
                       p1+=100;
                       printf("\n\tEVENTO 2 SORTEADO! %s PERDE 100 PONTOS PARA O %s !! \n",name2, name);
                       printf("\tPONTUACAO DE %s= %d\n", name2,p2);
                       printf("\t------------------------------------------------------\n");
                       break;
                     case 3:
                       p2+=(p2/3);
                       printf("\n\tEVENTO 3 SORTEADO! %s TERA 1/3 DE SEUS PONTOS SOMADOS A PONTUACAO !! \n",name2);
                       printf("\tPONTUACAO DE %s= %d\n", name2,p2);
                       printf("\t------------------------------------------------------\n");
                       break;
                   }
               }
               if(ch==2)
               {
                   printf("\n\tBAU DA MORTE NAO SERA ABERTO\n");
                   printf("\tPONTUACAO DE %s= %d\n", name2,p2);
                   printf("\t------------------------------------------------------\n");
               }
           }
       }
       else
       {
           printf("\n\tNENHUM ALVO ATINGIDO!! BOA SORTE NA PROXIMA JOGADA!!\n");
           printf("\tPONTUACAO DE %s= %d\n", name2,p2);
           printf("\t------------------------------------------------------\n");
       }
       
       ++i;
       ++j;
    }

    vp[0]=p1;
    vp[1]=p2;
    vp[2]=pnj1;
    vp[3]=pnj2;
}

void final (char **cb, char **cb2, int *vp, char *name, char *name2)
{
    if(vp[2]>1)
    {
        printf("\n\n\t\t\t%s ATINGIU 2 PEROLAS NEGRAS, PORTANTO, %s FOI O VENCEDOR!!!!\n",name,name2);
    }

    if(vp[3]>1)
    {
        printf("\n\n\t\t\t%s ATINGIU 2 PEROLAS NEGRAS, PORTANTO, %s FOI O VENCEDOR!!!!\n",name2,name);
    }

    if(vp[0]>=400)
    {
       printf("\n\n\t\t\t%s FOI O VENCEDOR, PARABENS!!!!\n",name);
    }
    if(vp[1]>=400)
    {
       printf("\n\n\t\t\t%s FOI O VENCEDOR, PARABENS!!!!\n",name2);
    }

    printf("\n\n\t\tCAMPO DO JOGADOR 1 (%s): \n\t\tPONTUACAO: %d", name, vp[0]);
       for(i=0;i<10;i++)
       {
           printf("\n");
           printf("\t\t");
           for (j=0;j<10;j++)
           {
               printf("%c   ", cb[i][j]);
           }
       }

       printf("\n\n\t\tCAMPO DO JOGADOR 2 (%s): \n\t\tPONTUACAO: %d", name2, vp[1]);
       for(i=0;i<10;i++)
       {
           printf("\n");
           printf("\t\t");
           for (j=0;j<10;j++)
           {
               printf("%c   ", cb2[i][j]);
           }
       }

       /*LIBERANDO O CAMPO DO P1*/
       for(i=0;i<10;i++)
       {
           free(cb[i]);
       }

       free(cb);

       /*LIBERANDO O CAMPO DO P2*/
       for(i=0;i<10;i++)
       {
           free(cb2[i]);
       }

       free(cb2);
}

