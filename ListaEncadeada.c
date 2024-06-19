#include <stdio.h>
#include <stdlib.h>

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

typedef struct tipoLista {
  tipoNo *prim;
} tipoLista;


// funcao que cria uma lista encadeada vazia

void criaLista(tipoLista *l) {
  l->prim = NULL;
}

// funcao que insere elemento na lista

void insereNaLista(tipoLista *l, tipoDado d) {
  tipoNo * aux;
  aux = (tipoNo*) malloc (sizeof(tipoNo));
  aux->d = d;
  aux->prox = l->prim;
  l->prim = aux;
}



void mostraDado(tipoDado d) {
  printf("------------------\n");
  printf("Nome: %s\n", d.nome);
  printf("ID: %d\n", d.id);
}

// uma das muitas versoes para mostrar os dados armazenados em uma lista

void mostraLista(tipoLista l) {
  while(l.prim) {
    mostraDado(l.prim->d);
    l.prim = l.prim->prox;
  }
}

// mais uma das muitas versoes para mostrar os dados armazenados em uma lista

void mostraListaVersao2(tipoLista *l) {
  tipoNo *aux = l->prim;
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
  tipoLista l1;
  tipoLista l2;
  tipoDado x;

  criaLista(&l1);
  criaLista(&l2);
  leDados(&x);
  insereNaLista(&l1,x);
  leDados(&x);
  insereNaLista(&l1,x);
  leDados(&x);
  insereNaLista(&l2,x);
  printf("conteudo da lista 1:\n");
  mostraLista(l1);
  printf("\n**************\n conteudo da lista 2:\n");
  mostraLista(l2);

}