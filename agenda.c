/*Universidade de Brasilia
  Andre Heladio de Carvalho Thomas
  160112036
  Estrutura de Dados*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct Contato
{
	long int num;
	char nome[MAX];
	char email[MAX];
}contato;

typedef struct Lista
{
	contato pessoa;
	struct Lista *prox;
}lista;

lista *inicio;
lista *next;
lista *aux;
lista *begin;
lista *novo;

int i=0;

void insere();
void editar();
void remover(lista *p);
lista* buscar();
void menor();
void ordena(lista *ord);
void limpar();
void txt();
void impressao();

int main ()
{
	int op;
	inicio = NULL;

	do
    {
	   printf("------------------  MENU  ------------------\n\n"
		   "\t< 1 > Inserir novo contato\n"
		   "\t< 2 > Editar contato\n"
		   "\t< 3 > Remover contato\n"
		   "\t< 4 > Localizar contato\n"
		   "\t< 5 > Ordenar lista em ordem alfabetica\n"
		   "\t< 6 > Limpar lista de contatos\n"
		   "\t< 7 > Exibir contatos\n"
		   "\t< 8 > Gerar arquivo .txt dos contatos\n"
		   "\t< 0 > Sair\n\n"
		   "Selecione alguma das opcoes acima: ");
	   scanf("%d", &op);

	   switch (op)
	   {
		   case 0:
		    exit(0);

		   case 1:
            insere();
            break;

           case 2:
            editar();
            break;

           case 3:
            aux=NULL;
            remover(aux);
            break;

           case 4:
            aux=buscar();
            if(aux != NULL)
            {
               printf("\n\tInformacoes do contato:\n");
               printf("\n->nome do contato: %s\n->numero: %li\n->email: %s\n", aux->pessoa.nome, aux->pessoa.num, aux->pessoa.email);
            }
            break;

           case 5:
            if(inicio == NULL)
            {
                printf("\nLista vazia\n");
                break;
            }
            begin=NULL;
            menor();
            inicio=begin;
            break;

           case 6:
            limpar();
            break;

           case 7:
            impressao();
            break;

           case 8:
            txt();
            break;
	   }

	   system("pause");
	   system("cls");
    }while (op != 0);

    limpar();

	return 0;
}

void insere()
{
    char c;
    i=0;

    if (inicio == NULL)
    {
        inicio = (lista*) malloc(sizeof(lista));
        printf("\n->Insira o nome do contato: ");
        getchar();
        do
        {
            c = getchar ( ) ;
            inicio->pessoa.nome[i]=c;
            ++i;
        }while(c != '\n');
        inicio->pessoa.nome[i-1]= '\0';
        i=0;

        printf("\n->Insira o numero: ");
        scanf("%li", &inicio->pessoa.num);

        printf("\n->Insira o email: ");
        getchar();
        do
        {
            c=getchar();
            inicio->pessoa.email[i]=c;
            ++i;
        }while(c != '\n');
        inicio->pessoa.email[i-1]= '\0';
        next = inicio;
        next->prox = NULL;

        return;
    }


    next->prox = (lista*) malloc(sizeof(lista));
    next=next->prox;
    printf("\n->Insira o nome do contato: ");

    getchar();
    do
    {
        c=getchar();
        next->pessoa.nome[i]=c;
        ++i;
    }while(c != '\n');
    next->pessoa.nome[i-1]= '\0';
    i=0;

    printf("\n->Insira o numero: ");
    scanf("%li", &next->pessoa.num);

    printf("\n->Insira o email: ");
    getchar();
    do
    {
        c=getchar();
        next->pessoa.email[i]=c;
        ++i;
    }while(c != '\n');
    next->pessoa.email[i-1]= '\0';
    next->prox = NULL;
}

void remover(lista *p)
{
	lista *anterior;
	lista *aux2;

    if(p == NULL) /*caso NAO seja passado pela funcao de ordenacao. Questao de output*/
    {
       aux2=buscar();
    }

    else /*Caso um ponteiro seja passado. Se for passado pela funcao de ordenacao*/
    {
    	aux2=p;
    }

    aux=inicio;

    if(aux2 == NULL)
    {
    	return;
    }

    if(aux2 == aux) /*Se for o primeiro elemento da lista a ser removido*/
    {
        anterior = inicio;
    	inicio = inicio->prox;
    	free(anterior);
    	return;
    }

    while(aux != aux2)
    {
    	anterior=aux;
    	aux=aux->prox;
    }

    if(aux->prox == NULL) /*Se for o ultimo elemento da lista a ser removido*/
    {
        next=anterior;
        next->prox=NULL;
        free(aux);
        return;
    }

    anterior->prox = aux2->prox;
    free(aux);
}

void editar()
{
	int a=0,opc;
	char c;
	aux= buscar();

	while(a==0)
	{
	   printf("\nQual informacao sera modificada?\n"
		      "< 1 > nome\n"
		      "< 2 > email\n"
		      "< 3 > numero\n"
		      "\nOpcao: ");
	   scanf("%d", &opc);

	   switch (opc)
	   {
	   	    case 1:
	   	       i=0;
	   	       printf("\nInsira o novo nome do contato: ");
	   	       getchar();
	           do
	           {
	              c=getchar();
                  aux->pessoa.nome[i]=c;
                  i++;
               }while(c != '\n');
               aux->pessoa.nome[i-1]='\0';
               break;

            case 2:
               i=0;
               printf("\nInsira o novo email do contato: ");
               do
	           {
	              c=getchar();
                  aux->pessoa.email[i]=c;
                  i++;
               }while(c != '\n');
               aux->pessoa.email[i-1]='\0';
               break;

            case 3:
               printf("\nInsira o novo numero do contato: ");
               scanf("%li", &aux->pessoa.num);
               break;
	    }

	    printf("\nDeseja modificar alguma outra informacao do contato?\n"
	    	   "< 0 > SIM\n"
	    	   "< OUTRO VALOR > NAO\n");
	    scanf("%d", &a);
    }

}

lista* buscar()
{
	char c;
	int opc,a;
	lista* e;
	e=(lista*) malloc(sizeof(lista));

	aux=inicio;


	printf("\nQual informacao sera dada?\n"
		   "< 1 > nome\n"
		   "< 2 > email\n"
		   "< 3 > numero\n"
		   "\nOpcao: ");

	scanf("%d", &opc);

	switch (opc)
	{
		case 1:
		  i=0;
		  printf("\nInsira o nome do contato : ");
		  getchar();
	      do
	      {
	         c=getchar();
             e->pessoa.nome[i]=c;
             i++;
          }while(c != '\n');
          e->pessoa.nome[i-1]='\0';

          while(aux != NULL)
	      {
	          a=strcmp(aux->pessoa.nome, e->pessoa.nome);
		      if(a == 0) /*se os nomes forem iguais quebra o laco*/
              {
                  break;
              }
              aux=aux->prox;
          }
          break;

        case 2:
          i=0;
          printf("\nInsira o email do contato : ");
		  getchar();
	      do
	      {
	         c=getchar();
             e->pessoa.email[i]=c;
             i++;
          }while(c != '\n');
          e->pessoa.email[i-1]='\0';

          while(aux != NULL)
	      {
	          a=strcmp(aux->pessoa.email, e->pessoa.email);
		      if(a == 0) /*se os emails forem iguais, quebra o laco*/
		      {
		          break;
              }
              aux=aux->prox;
          }
          break;

        case 3:
          printf("\nInsira o numero do contato : ");
          scanf("%li", &e->pessoa.num);

          while(aux != NULL && aux->pessoa.num != e->pessoa.num)
	      {
		     aux=aux->prox;
          }
          break;
	}

	if (aux==NULL)
	{
		printf("\nContato inexistente!\n\n");
		e->prox = NULL;
		free(e);
		return NULL;
	}
	else
	{
	    e->prox = NULL;
	    free(e);
		return aux;
	}

}

void menor()
{
    // essa funcao acha o menor nome restante na lista
    lista *min;
    aux = inicio;
    min=aux;
    char name[MAX];
    int a;

    if(inicio->prox == NULL) /*Caso so exista um elemento na lista o contato é passado para a nova lista e removido da antiga*/
    {
        ordena(min);
        remover(min);
        return;
    }

    while (aux != NULL)
    {
    	a= strcmp(aux->pessoa.nome, min->pessoa.nome);
        if (a<0)
        {
            min = aux;
        }
        aux = aux->prox;
    }

    ordena(min); /*o ponteiro do menor nome sera passado para uma nova lista*/
    remover(min); /*o contato que foi para outra lista, vai ser removido da lista original*/
    menor(); /*Se o teste de so haver 1 elemento na lista nao for concretizado, a funcao sera chamada novamente*/
}

void ordena(lista *ord)
{
    int x,y;

    x=strlen(ord->pessoa.nome);
    y=strlen(ord->pessoa.email);

    if ( begin == NULL)
    {
       begin = (lista*) malloc(sizeof(lista));
       for(i=0;i<x;i++)
       {
           begin->pessoa.nome[i]=ord->pessoa.nome[i];
       }
       begin->pessoa.nome[i]='\0';

       for(i=0;i<y;i++)
       {
           begin->pessoa.email[i]=ord->pessoa.email[i];
       }
       begin->pessoa.email[i]='\0';

       begin->pessoa.num = ord->pessoa.num;
       begin->prox = NULL;
       novo = begin;
       return;
    }

    novo->prox = (lista*) malloc(sizeof(lista));
    novo = novo->prox;
    for(i=0;i<x;i++)
    {
        novo->pessoa.nome[i] = ord->pessoa.nome[i];
    }
    novo->pessoa.nome[i]='\0';

    for(i=0;i<y;i++)
    {
        novo->pessoa.email[i] = ord->pessoa.email[i];
    }
    novo->pessoa.email[i]='\0';

    novo->pessoa.num = ord->pessoa.num;
    novo->prox = NULL;
    next=novo;

}

void limpar()
{
    while(inicio != NULL)
    {
        aux = inicio;
        inicio=inicio->prox;
        free(aux);
    }
}

void txt()
{
    // essa funcao cria um arquivo .txt de saida, em ordem alfabetica
    FILE *arq= fopen("CONTATOS.txt", "w");

    if(inicio == NULL)
    {
        printf("\nLista vazia\n");
        return;
    }

    begin=NULL;
    menor();
    inicio=begin;
    aux=inicio;

    while (aux != NULL)
    {
        fprintf(arq,"\n------------------------------------------\n");
        fprintf(arq,"->nome do contato: %s\n->numero: %li\n->email: %s\n", aux->pessoa.nome, aux->pessoa.num, aux->pessoa.email);
        aux=aux->prox;
    }

}

void impressao()
{
    aux=inicio;

    printf("\n");

    if(aux == NULL)
    {
        printf("*** Sua lista esta vazia ! ***\n\n");
    }

    while (aux != NULL)
    {
        printf("\n------------------------------------------\n");
        printf("->nome do contato: %s\n->numero: %li\n->email: %s\n", aux->pessoa.nome, aux->pessoa.num, aux->pessoa.email);
        aux=aux->prox;
    }
}
