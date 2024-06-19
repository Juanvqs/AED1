#include <stdio.h>


int main() {
  int numero, maior;

  printf("entre com um número: ");
  scanf("%d",&numero);
  if(numero != 0) {
    maior = numero;
    while(numero != 0) {
      if(numero> maior) {
	maior = numero;
      }
      printf("entre com um número: ");
      scanf("%d",&numero);
    }
    printf("maior número diferente de zero digitado foi: %d \n",maior);
  }
  else {
    printf("Nenhum número válido foi digitado\n");
  }
  

}