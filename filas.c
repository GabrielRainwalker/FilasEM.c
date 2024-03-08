#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int valor;
	struct No *prox; 
}No, TipoNo;

typedef struct {
	TipoNo *ini, *fim; 
	int tamanho; 
}Fila, TipoFila;

void IniciaFila(TipoFila *fila) {
	fila->ini = NULL;
	fila->fim = NULL;
	fila->tamanho = 0;
}

int Vazia(TipoFila *fila)
{
	return (fila->ini == NULL); 
}

void Enfileira(int x, TipoFila *fila) {
	TipoNo *aux;
  	aux = (TipoNo *) malloc(sizeof(TipoNo));
  	aux->valor=x;
  	aux->prox=NULL;
  if (Vazia(fila)){
    fila->ini=aux;
    fila->fim=aux;
  }
  else {
  	fila->fim->prox = aux;
  	fila->fim = aux;
  }
  	fila->tamanho++;
}

int Desenfileira(TipoFila *fila) {
  	TipoNo *q; int v;
  if (Vazia(fila))
  { 
    	printf("Fila vazia\n");
    return 0;
  }
  	q = fila->ini;
  	v = fila->ini->valor;
  	fila->ini = fila->ini->prox;
  	free(q);
  	fila->tamanho--;
  return v;
}  

int Tamanho(TipoFila *fila)
{
  return (fila->tamanho);
} 

void Imprime(TipoFila *fila)
{
  TipoNo *aux;
  aux = fila->ini->prox;
  while (aux != NULL)
    { 
      printf("%i\n", aux->valor);
      aux = aux->prox;
    }
}

int main() {
int i, numero, max=5;
TipoFila *fila;

fila = (TipoFila *) malloc (sizeof(TipoFila));
IniciaFila(fila);

for (i=0;i<max;i++) {
	printf("Leitura do valor (%d) :",i); scanf("%d",&numero);
	Enfileira(numero, fila);
	printf("Enfileirou: %d \n", numero);
}
for(i=0;i<max;i++) {
	numero = Desenfileira (fila);
	printf ("Desenfilerou: %d \n", numero);
}}
