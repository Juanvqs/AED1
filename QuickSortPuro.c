#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 100000000

/* Implementacao do quicksort em si. */

void qSortInterno(int v[], int inicio, int fim) {
  int pivot;
  int temp;
  int i,j;

  if(fim - inicio > 0) { /* tem mais de 1 elemento */
    i = inicio;
    j = fim;
    pivot = v[(i+j)/2];
    
    do {
      while(v[i] < pivot) i++; /* procura por algum item do lado errado  >= pivot */
      while(v[j] > pivot) j--; /* procura por algum item do lado errado <= pivot */
      if(i<= j) { /* deixa o igual para garantir que ao final i<j (esqueci desse                      if na aula, ele trata o caso em que i passa do j nos loops
                       acima */
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	i++; j--;
      }
    } while (i<=j);
    qSortInterno(v,inicio, j);
    qSortInterno(v, i,fim);
  }
}


/* Funcao qickSort a ser chamada em outros pontos do programa. Serve apenas para disparar a chamada revursiva 

*/

void quickSort(int v[], int n) {
  qSortInterno(v, 0, n-1);
}

/* agora uma funcao main pra testar */

int main() {
  int *v;
  int i;
  srand(0);
  
  v = (int*) malloc (sizeof(int)*N); /* aloca vetor dinamicamente como 
                                     vimos na aula de quarta */
  for(i = 0; i< N; i++) {
    v[i]= rand();   // aqui para preencher com valores aleatorios 
  }
  
  printf("iniciando ordenacao...\n");
  quickSort(v, N);
  printf("ordenacao concluida.\n");
  
  for(i = 0; i < 10; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
  
}

