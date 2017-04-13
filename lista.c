#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA
{
    int elemento;
    struct LISTA *next;
}lista;

lista *inicio;
lista *prox;
lista *aux;

void insere (int e);
void remover (int e);
int busca (int e);
void imprime ();

int main()
{
    int opc,be,x;

    inicio= NULL;

    prox=inicio;

    while(1)
    {
        printf("-----------MENU-----------\n"
               "<1>Inserir elemento\n"
               "<2>Buscar elemento\n"
               "<3>Remover elemento\n"
               "<4>Exibir lista\n"
               "<0>Sair\nopcao: ");
        scanf("%d", &opc);
        printf("\n");
        if (opc == 0)
        {
            break;
        }
        else
        {
           switch(opc)
           {
              case 1:
                  printf("Insira um valor: ");
                  scanf("%d", &x);
                  insere(x);
                  printf("\nPressione qualquer tecla para voltar ao menu");
                  getchar();
                  getchar();
                  system("cls");
                  break;

              case 2:
                  printf("\nQual elemento deseja buscar?\n");
                  scanf("%d", &be);
                  x=busca(be);
                  if(x>0)
                  {
                     printf("\nO elemento se encontra na posicao %d.", x);
                  }
                  else
                  {
                      printf("\nElemento nao se encontra na lista!!");
                  }
                  printf("\nPressione qualquer tecla para voltar ao menu");
                  getchar();
                  getchar();
                  system("cls");
                  break;

              case 3:
                  printf("\nQual elemento desseja remover?\n");
                  scanf("%d", &be);
                  remover(be);
                  printf("\nPressione qualquer tecla para voltar ao menu");
                  getchar();
                  getchar();
                  system("cls");
                  break;

              case 4:
                  imprime();
                  printf("\nPressione qualquer tecla para voltar ao menu");
                  getchar();
                  getchar();
                  system("cls");
                 break;
           }
        }
        printf("\n");
    }

    return 0;
}

void insere(int e)
{
    if(inicio == NULL)
    {
        inicio=(lista*) malloc(sizeof(lista));
        inicio->elemento=e;
        inicio->next=NULL;
        prox=inicio;
        return;
    }


    prox->next=(lista*) malloc(sizeof(lista));
    prox=prox->next;
    if(prox==NULL)
    {
        printf("\nIMPOSSIVEL ALOCAR MEMORIA");
    }
    prox->next=NULL;
    prox->elemento=e;
}

void remover(int e)
{
    lista *anterior;
    aux=inicio;

    if(aux == NULL)
    {
        printf("\nLISTA VAZIA");
        return;
    }

    if(inicio == prox && inicio->elemento == e)
    {
        printf("\n\nENTROU\n\n");
        free(aux);
        inicio=NULL;
        return;
    }

    if(aux->elemento == e) /*Teste para saber se o 1 elemento da lista é o que deve ser removido*/
    {
        inicio=inicio->next;
        free(aux);
        return;
    }

    while(aux != NULL && aux->elemento != e)
    {
       anterior=aux;
       aux=aux->next;
    }

    if(aux != NULL)
    {
        if(aux->next==NULL)
        {
            prox=anterior;
        }

        anterior->next=aux->next;
        free(aux);
        return;
    }

    printf("\nElemento nao se encontra na lista");
}

int busca(int e)
{
    int y=0;

    aux=prox;
    aux->next=NULL;
    aux=inicio;

    while(aux != NULL)
    {
        y+=1;
        if(aux->elemento == e)
        {
            return y;
        }

        aux=aux->next;

        if(aux==NULL)
        {
            return -1;
        }
    }
}

void imprime ()
{
    aux=inicio;

    while(aux != NULL)
    {
        printf("\nelemento: %d", aux->elemento);
        aux=aux->next;
    }
}
