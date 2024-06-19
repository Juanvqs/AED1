#include <stdio.h>



/* Funcao para ler valores para um vetor
   recebe como parametros um vetor v e seu tamanho (tam)
 */



void lerVetor(int v[], int tam) {
  int x;

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






/* retorna verdadeiro se n é par */

char verificaPar(int n) {

  if(n %2 == 0) {
    return 1;
  }
  return 0;
}


/* soma vetores
   soma vetores v1 e v2, colocando os resultados  em res

 */

void somarVetores(int res[], int v1[], int v2[], int tam) {
 int x;

  for(x = 0; x < tam ; x++) {
    res[x] = v1[x]+v2[x];
  }
}



void mostrarVetor(int v[], int tam) {
  int x;

  for(x = 0; x < tam ; x++) {
    printf("Posicao [%d] : %d\n ",x, v[x]);
  }
}

#define N 5

int main() {
  int vet1[N], vet2[N];
  int vet3[N];
  int pi;

  printf("Entre com os dados do vetor 1: \n");
  lerVetor(vet1,N);
  printf("Entre com os dados do vetor 2: \n");
  lerVetor(vet2,N);
  
  printf("Os valores do vetor 1:\n");
  mostrarVetor(vet1,N);

  printf("Os valores do vetor 2:\n");
  mostrarVetor(vet2,N);
  pi = produtoInterno(vet1, vet2, N);

  printf("O produto interno entre os dois vetores é %d\n", pi);
  
  printf("A soma dos dois vetores: \n");
  somarVetores(vet3,vet1,vet2,N);
  mostrarVetor(vet3,N);

}