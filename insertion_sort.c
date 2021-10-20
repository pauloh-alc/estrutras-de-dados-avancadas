#include <stdio.h>
#include <stdint.h>

void mostrar_array(int8_t array[], int8_t n) {
  printf("[");
  for (uint8_t i = 0; i < n; i++) {
    printf("%d",array[i]);
    if (i < n - 1) printf(", ");
  }
  printf("]\n");
}

int main (void) {
  
  //uint8_t A[] = {[0] = 4, 0b1, 0b1000, 9, 7, 3, 0, [7] = 6};
  int8_t n = 8, chave, i;
 
  uint8_t A[] = {9,8,7,6,5,4,3,2,1};
  n = 9;
  mostrar_array(A,n);

  for (uint8_t j = 1; j < n; j++) {
    chave = A[j];

    i = j - 1;
    while (A[i] > chave && i >= 0) {
      A[i+1] = A[i];
      i = i - 1;
    }
    A[i+1] = chave;
  }
  
  mostrar_array(A,n);

  return 0;
}
