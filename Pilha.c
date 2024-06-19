#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// aqui definimos o tipo dado contendo os dados que vao ser guardados em nossa lista encadeada

typedef struct tipoDado {
  char nome[30];
  int id;
} tipoDado;

// definicao do tipo que representa cada nó da lista. 

typedef struct tipoNo {
  struct tipoNo *prox;
  tipoDado d;
} tipoNo;

// definicao do tipo lista que será usado para representar nossas listas

typedef struct tipoPilha {
  tipoNo *topo;
} tipoPilha;


// funcao que cria uma lista encadeada vazia

void criaPilha(tipoPilha *l) {
  l->topo = NULL;
}


// funcao que insere elemento na lista

void insereNaPilha(tipoPilha *l, tipoDado d) {
  tipoNo * aux;
  aux = (tipoNo*) malloc (sizeof(tipoNo));
  aux->d = d;
  aux->prox = l->topo;
  l->topo = aux;
}



/* Remove de uma pilha considerando que há elementos */

tipoDado removeDaPilha(tipoPilha *l) {
  tipoDado tmpD;
  tipoNo *aux;

  aux = l->topo;
  tmpD = aux->d;
  l->topo = aux->prox;
  free(aux);
  return tmpD;
}

tipoNo * haElementos(tipoPilha *l) {
  return l->topo;
}

void mostraDado(tipoDado d) {
  printf("------------------\n");
  printf("Nome: %s\n", d.nome);
  printf("ID: %d\n", d.id);
}


void mostraPilha(tipoPilha *l) {
  tipoNo *aux = l->topo;
  while(aux) {
    mostraDado(aux->d);
    aux = aux->prox;
  }
}


void leDados(tipoDado *x) {
  printf("Entre com os dados de uma pessoa:\n");
  printf ("Nome:"); scanf("%[^\n]%*c",x->nome);
  printf("Id:"); scanf("%d%*c",&x->id);
} 


int main() {
  tipoDado x;
  
}