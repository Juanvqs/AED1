#include <stdio.h>

#define N 21

int main() {
  int l,c;


  for(l = 0; l < N; l++) {
    for(c = 0; c < N; c++) {
      if(
	 ((l < N/2) && ( (c == (N/2)+l) ||  (c == (N/2)-l) )) ||
	 ((l >= N/2) && ( (c == l-(N/2))||  (c == (N-1) - (l-(N/2))) ))
	   ) {
	printf("**");
      }
      else {
	printf("  ");
      }
    }
      printf("\n");
  }
}