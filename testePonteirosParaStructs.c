#include <stdio.h>
#include <stdlib.h>

// Mais exemplos com ponteiros e structs

typedef struct tipoCoisa {
  struct tipoCoisa *prox; // Uma struct que tem um campo que aponta pra outras variaveis do mesmo tipo!
  char a;      // notem que aqui exemplo de ordenacao ruim de campos da struct
  unsigned long d;
  char c;
  unsigned long b;
} tipoCoisa;

int main() {
  tipoCoisa *v, **p;

  // Cria um vetor com 1000 coisas. Mais um exemplo de alocacao dinamica de vetores
  v = (tipoCoisa*) malloc(sizeof(tipoCoisa)*1000);

  // As diversas formas de ter acesso ao primeiro elemento do vetor
  v[0].d =5;
  //  Notem que *v é a variavel apontada por v no momento, que corresponde a v[0]. (*v) é portanto uma struct e tem campos, como o campo d ( (*v).d ). 
  (*v).d = 5;

  //  Quando ponteiros apontam para struct, pode-se usar o ponteiro para se ter acesso a campos na forma (*v).nomeDoCampo ( como em (*v).d acima) ou ainda usar  a sintaze v->d. v->d lê-se da mesma maneira que (*v).d: A variavel apontada por v em seu campo d. 

  // Notem que *v é a variavel apontada por v no momento, que corresponde a v[0]. (*v) é portanto uma struct e tem campos, como o campo d ( (*v).d ). 

  v->d =5;
  p= &v;
  // Notem que p é ponteiro para ponteiro para uma struct. Nao faria sentido valar em p-> porque ele é ponteiro para ponteiro e nao ponteiro para struct. Já o *p é a variavel apontada por p. A variavel apontada por p é um ponteiro para struct, logo posso colocar a -> ao lado dela para ter acesso a um campo da struct apontada pela variavel apontada por p (*p)->d

  (*p)->d = 5;

}