#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 100000000


void ordenaInsercao(int  v[], int tamanho) {
    int i, j;
    int pivot;
    
    for(j = 1; j < tamanho; j++ ) {
      i = j -1;
      pivot = v[j];
      while((i>=0) && (v[i]>pivot)) {
	  v[i+1] = v[i];
	i--;
      }
      v[i+1] = pivot;
    }
  }




void qSortInterno(int v[], int inicio, int fim);

/* Funcao qickSort a ser chamada em outros pontos do programa. Serve apenas para disparar a chamada revursiva */


void quickSort(int v[], int n) {

  qSortInterno(v, 0, n-1);
  ordenaInsercao(v,n);
}

/* Implementacao do quicksort em si. */

void qSortInterno(int v[], int inicio, int fim) {
  int pivot;
  int temp;
  int i,j;
  int meio;

  while (fim - inicio > 50) { /* tem mais de 1 elemento */
    i = inicio;
    j = fim;
    meio = (i+j)/2;
    pivot = v[meio];
    
    do {
      while(v[i] < pivot) i++; /* procura por algum item do lado errado  >= pivot */
      while(v[j] > pivot) j--; /* procura por algum item do lado errado <= pivot */
      if(i<= j) { /* deixa o igual para garantir que ao final i<j */
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	i++; j--;
      }
    } while (i<=j);
    if(i < meio) {
      qSortInterno(v,inicio, j);
      inicio = i;
    }
    else {
      qSortInterno(v, i,fim);
      fim = j;
    }
  }
}


int main() {
  int *v;
  int i;
  srand(0);
  
  v = (int*) malloc (sizeof(int)*N);
  for(i = 0; i< N; i++) {
    v[i]= rand();
  }
  
  printf("iniciando ordenacao...\n");
  quickSort(v, N);
  // quickSort1Chamada(v, N);
  printf("ordenacao concluida.\n");
  for(i = 0; i < 10; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  
}

