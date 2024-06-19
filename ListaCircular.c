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

typedef struct tipoListaCircular {
  tipoNo *atual;
} tipoListaCircular;


// funcao que cria uma lista encadeada vazia

void criaLista(tipoListaCircular *l) {
  l->atual = NULL;
}

// funcao que insere elemento na lista

void insereNaListaCircular(tipoListaCircular *l, tipoDado d) {
  tipoNo * aux;
  aux = (tipoNo*) malloc (sizeof(tipoNo));
  aux->d = d;
  if(l->atual) {
    aux->prox =  l->atual->prox;
  }
  else {
    l->atual = aux;
  }
  l->atual->prox = aux;
}


char removeElementoListaCircular( tipoListaCircular *l,char *chave) {
  tipoNo *aux,*ant;
  if(l->atual) {
    aux = l->atual;
    do {   ant = aux;
      aux = aux->prox;
      if(!strcmp(aux->d.nome,chave)) {
	if(ant == aux) {  l->atual = NULL;	}
	else {
	  ant->prox = aux->prox;
	  if(aux == l->atual) {
	    l->atual = aux->prox;
	  }
	}
	free(aux);
	return 1; // indica que removeu
      }
      
    } while (aux!= l->atual);
    
  }
  return 0;
}

void mostraDado(tipoDado d) {
  printf("------------------\n");
  printf("Nome: %s\n", d.nome);
  printf("ID: %d\n", d.id);
}

// uma das muitas versoes para mostrar os dados armazenados em uma lista


// mais uma das muitas versoes para mostrar os dados armazenados em uma lista

void mostraListaCircular(tipoListaCircular *l) {
  tipoNo *aux;
  if(l->atual) {
    aux = l->atual;
    do {
      mostraDado(aux->d);
      aux = aux->prox;
    } while (aux!= l->atual);
  }
}


void leDados(tipoDado *x) {
  printf("Entre com os dados de uma pessoa:\n");
  printf ("Nome:"); scanf("%[^\n]%*c",x->nome);
  printf("Id:"); scanf("%d%*c",&x->id);
} 


int main() {
  tipoListaCircular l1;
  tipoDado x;
  tipoDado *resultado;
  char nome[30];
  int c;


  criaLista(&l1);
  printf("********* INSERINDO DADOS NA LISTA 1 *************\n");
  for(c = 0; c < 5; c++) {
    leDados(&x);
    insereNaListaCircular(&l1,x);
  }
  printf("conteudo da lista 1:\n");
  mostraListaCircular(&l1);
  do {
    printf("Entre com um nome a ser removido: ");
    scanf("%[^\n]%*c",nome);
    removeElementoListaCircular(&l1,nome);
    printf("Mostrando lista apos remocao:\n");
    mostraListaCircular(&l1);
  } while(strcmp(nome,"fim")!=0);
  
}