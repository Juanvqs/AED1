#include <stdio.h>
#include <string.h>


/* Funcao para ler valores para um vetor
   recebe como parametros um vetor v e seu tamanho (tam)
 */

void lerVetor(int v[], int tam) {
  int x;
  static int k=0;
  k++;

  for(x = 0; x < tam ; x++) {
    printf("Entre com o valor da posicao [%d] : ",x);
    scanf("%d%*c",&v[x]);
  }
}

/* Calcula o produto interno entre dois vetores, retornando o 
   resultado */

int produtoInterno(int v1[], int v2[], int tam) {
  int x;
  int resultado=0;

  for(x = 0; x < tam ; x++) {
    resultado = resultado+ (v1[x]*v2[x]);
  }
  return resultado;
}



/* busca binaria
 */



int buscaBin(int v[], int n, int chave) {
  int inicio,fim,meio;

  inicio = 0;
  fim = n-1;

  while(inicio<=fim) {
    meio = (inicio+fim)/2;
    if( chave > v[meio]) {
      inicio = meio+1;
    }
    else {
      if(chave < v[meio]) {
	fim  = meio -1;
      }
      else { return 1; }
    }
  }
  return 0;
  }


/* ordenacao por selecao 

*/

void selecao( int v[], int n) {
  int i,j;
  int posMenor;
  int tmp;
  int tamMenos1 = n -1;

  for(i = 0; i < tamMenos1 ; i++) {
    posMenor= i;
     for(j = i+1; j < n ; j++) {
       if(v[j] < v[posMenor]) {
	 posMenor = j;
       }
     }
     tmp = v[i];
     v[i] = v[posMenor];
     v[posMenor] = tmp;
  }
}


void somarVetores(int res[], int v1[], int v2[], int tam) {
 int x;

  for(x = 0; x < tam ; x++) {
    res[x] = v1[x]+v2[x];
  }
}



void mostrarVetor(int v[], int tam) {
  int x;

  printf("(");
  for(x = 0; x < tam ; x++) {
    printf("%d,",v[x]);
  }
  printf(")\n");
}

#define N 8

int main() {
  int vet1[N], vet2[N];
  int vet3[N];
  int pi;
  int elem;


  printf("Entre com os dados do vetor 1: \n");
  lerVetor(vet1,N);
  printf("Os valores do vetor 1:\n");
  mostrarVetor(vet1,N);

  selecao(vet1,N);
 printf("Os valores do vetor 1 agora ordenado:\n");
  mostrarVetor(vet1,N);

 if(buscaBin(vet1,N,5)) {
   printf("O 5 está no vetor!!!!\n");
 }




 /* Novo tipo de comando de repeticão ( do { ...} while (condicao);
    diferenca pro while é que sempre executa a 1a vez
  */
 
 do {
   printf("Entre com um elemento a ser buscado (0 para sair):"); 
   scanf("%d%*c",&elem);
 if(buscaBin(vet1,N,elem)) {
   printf("O valor digitado está no vetor!!!!\n");
 }
 else {
   printf("chave não encontrada\n");
 }
 /* enquanto elem != 0 volta pra linha do do */
 } while (elem != 0);
}