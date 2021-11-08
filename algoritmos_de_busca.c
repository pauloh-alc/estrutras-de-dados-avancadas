#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define size(array) (sizeof(array)/sizeof(array[0]))
#define TAM_ARRAY 15


/*
 * Busca sequencial
 * O(n)
 */

int8_t busca_sequencial (int* array, int chave) {
  
  for (uint8_t i = 0; i < TAM_ARRAY; i++)
    if (chave == array[i]) return i;
  
  return -1;
}


/*
 * Busca Binaria - Binary search
 *  
 * Recursiva
 * O(log n)
 *
 */

int8_t busca_binaria_recursiva_ (int* array, int chave, uint8_t inicio, uint8_t fim) {
  
  int meio;

  if (inicio <= fim) {
    meio = (inicio + fim) / 2;

    if (chave == array[meio])
      return meio;
    else if (chave < array[meio])
      return busca_binaria_recursiva_ (array, chave, inicio, meio-1);
    else
      return busca_binaria_recursiva_ (array, chave, meio+1, fim);
  }
  return -1;
}

int8_t busca_binaria_recursiva (int* array, int chave) {
  return busca_binaria_recursiva_ (array, chave, 0, TAM_ARRAY - 1);
}


/*
 * Busca binaria - Binary search
 *
 * Iterativa
 * O(log n)
 */

int8_t busca_binaria_iterativa_ (int* array, int chave, uint8_t inicio, uint8_t fim) {
  int meio;  
  
  while (inicio <= fim) {
    meio = (inicio + fim) / 2;
      
    if (chave == array[meio])
      return meio;
    else if (chave < array[meio])
      fim = meio - 1;
    else 
      inicio = meio + 1;
  }
  return -1;
}

int8_t busca_binaria_iterativa (int* array, int chave) {
  return busca_binaria_iterativa_ (array, chave, 0, TAM_ARRAY - 1);
}

int main () {
  int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  
  int chave;
  for (uint8_t i = 0; i < TAM_ARRAY; i++) {
    chave = array[i];
    printf("chave -> %d, indice: %hhd \n",chave, busca_sequencial(array, chave));
    printf("chave -> %d, indice: %hhd \n",chave, busca_binaria_recursiva(array, chave));
    printf("chave -> %d, indice: %hhd \n",chave, busca_binaria_iterativa(array, chave));
    printf("\n");
  }
  return EXIT_SUCCESS;
}

