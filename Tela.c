#include <stdio.h>

#define N 20

int main() {
  int l,c;


  for(l = 0; l < N; l++) {
    for(c = 0; c < N; c++) {
      if((l == c) || (l+c == (N-1)) || (l ==0)) {
	printf("**");
      }
      else {
	printf("  ");
      }
    }
    printf("\n");
  }
}