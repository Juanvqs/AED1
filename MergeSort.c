#include <stdio.h>
#include <stdlib.h>
 #include <time.h>

#define N 100000000

void intercala(int v[], int vaux[], int inicio, int fim, int meio) {
  int i, j,k;

  k = inicio;
  i = inicio;
  j = meio+1;

  while((i <= meio) && (j <= fim)) {

    if(v[i] < v[j]) {
      vaux[k] = v[i];
      i++;
    }
    else {
      vaux[k]= v[j];
      j++;
    }
    k++;
  }

  while(i<=meio) {
    vaux[k] = v[i];
    i++; 
    k++;
  }

  while(j <= fim) {
    vaux[k]= v[j];
    j++;
    k++;
  }
  // COPIA DADOS DE VOLTA PRO VETOR ORIGINAL

  for(k = inicio; k <=fim; k++) {
    v[k]=vaux[k];
  }
}
 
void mergeSortInterno(int v[], int vaux[], int inicio, int fim) {
  int meio;

  if(inicio < fim) {
    meio = (inicio+fim)/2;
    mergeSortInterno(v,vaux,inicio, meio);
    mergeSortInterno(v,vaux, meio+1,fim);
    intercala(v,vaux,inicio,fim,meio);
  }
}


void mergeSort(int v[], int n) {
  int *vaux;

  // A FORMA ABAIXO É A MAIS USADA PARA CRIAR VETORES GRANDES 
  // OU VETORES DE TAMANHO DEFINIDOS EM TEMPO DE EXECUCAO
  // USAR MALLOC E UM PONTEIRO AO INVES DE FAZER
  // evite fazer int vaux[n];
  // SENDO n grande ou uma variavel

  vaux = (int*) malloc(sizeof(int)*n);
  mergeSortInterno(v,vaux,0,n-1);

  // free libera a memória alocada para o vaux (como se destruisse o vetor, liberando memória)
  free(vaux);

}


int main() {
  int *v;
  int i;

  // srand será usada para gerar números aleatoriamente.
  // srand me dá uma semente, passando 0, as chamadas de abaixo vão
  // sempre gerar os mesmos números entre execuções
  // usando srand(time(NULL)), os números gerados vão variar
  // a cada execução

  srand(0);

// A FORMA ABAIXO É A MAIS USADA PARA CRIAR VETORES GRANDES 
  // OU VETORES DE TAMANHO DEFINIDOS EM TEMPO DE EXECUCAO
  // USAR MALLOC E UM PONTEIRO AO INVES DE FAZER
  // evite fazer int vaux[n];
  // SENDO n grande ou uma variavel
  
  v = (int*) malloc (sizeof(int)*N);
  for(i = 0; i< N; i++) {
    // A função rand() abaixo gera um número aleatório!
    v[i]= rand();
  }
  
   printf("iniciando ordenacao...\n");
    mergeSort(v, N);
  printf("ordenacao concluida. Mostrando os 10 primeiros apenas para conferencia \n");
  for(i = 0; i < 10; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");

  // libera a memória alocada para o vetor v;
  free(v);
}


