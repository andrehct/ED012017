#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int head,tail,i,x,aux;
int pilha[MAX];

void push(int x);
int pop();

int pv();
int pc();

int main ()
{ 
   head=0;
   tail=0;

   for(i=0;i<MAX;i++)
   {
      printf("\nInsira o valor: ");
      scanf("%d", &x);
      push(x);
   }
   
   for(i=0;i<MAX;i++)
   {
   	  printf("\n%d valor desempilhado: %d",i+1,pop());
   }
   return 0;
}

int pc()
{
	return(tail==MAX);
}

int pv()
{
	return (head==tail);
}

push(int x)
{
	if(!pc())
	{
       pilha[tail++]=x;
    }
    else
    {
    	printf("\nPILHA CHEIA");
    }
}

int pop()
{
	if(!pv())
	{
	   aux=pilha[tail-1];
	   tail--;
	   return aux;
	}
	else
	{
		printf("\nPILHA VAZIA");
	}
}