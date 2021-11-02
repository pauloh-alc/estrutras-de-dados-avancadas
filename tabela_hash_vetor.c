#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#define DESOCUPADO -1


/* TABELA HASH COM VETOR: MÉTODO DA DIVISÃO
 *
 * m - tamanho da tabela (m's ruins: m par, m potência de 2) 
 * (m's bons: m impar, m primo e não próximo de uma potência de 2, m não possui divisores primos menores que 20)
 * n - número de chaves
 */ 


void exibir_chaves(int16_t *vetor, int8_t n) {
  
  printf("chaves:[");
  for (int8_t i = 0; i < n; i++) {
    printf("%hd",vetor[i]);
    if (i != n - 1) printf(", ");
  }
  printf("]\n");

}

int8_t localizacao (int16_t chave, int8_t m) {
  return chave % m;  
}


void liberar_memoria (int16_t *x) {
  free(x);
}


void exibir_tabela_hash (int16_t *tabela, int8_t m) {
  printf("Tabela hash: \n");
  for (int8_t i = 0; i < m; i++)
    printf("[%hhd] %hd \n",i,tabela[i]);
}


void copular_tabela (int16_t *tabela, int16_t chave, int8_t local, int8_t m) {
  while (tabela[local] != DESOCUPADO) {
    local = localizacao(local + 1, m);
  }
  tabela[local] = chave;
}

bool buscar_chave (int16_t* tabela, int8_t chave, int8_t m) {
  int8_t local = localizacao(chave, m);
  while (tabela[local] != DESOCUPADO) {
    if (tabela[local] == chave) return true;
    else local = localizacao(local + 1, m);
  }
  return false;
}

bool buscar (int16_t *tabela, int8_t chave, int8_t m) {
  int8_t a = 0, flag = 0;
  
  int8_t local = localizacao(chave, m);
  
  if (local == 0) flag++;

  while (a == 0) {
    if (tabela[local] == chave && tabela[local] != DESOCUPADO) {
      a = 1; // chave encontrada
    }
    else {
      local = localizacao(local + 1, m);
      if (local == 0) flag++;

      if (local == DESOCUPADO || flag > 1)
        a = 2;
    }
  }

  if (a == 1) return true;
  else return false;

}

void tabela_hash (int16_t* chaves, int8_t n, int8_t m) {
  int16_t* tabela = (int16_t*) malloc (sizeof(int16_t) * m);
   
  for (int8_t i = 0; i < m; i++) {
    tabela[i] = -1; 
  }
  
  for (int8_t i = 0; i < n; i++) {
    copular_tabela(tabela, chaves[i], localizacao(chaves[i], m), m); 
  }
  
  liberar_memoria(chaves);
  
  exibir_tabela_hash (tabela, m);

  int16_t chave;
  printf("Entre com a chave que vc deseja buscar: ");
  scanf("%hd",&chave);
  
  if (buscar(tabela, chave, m)) printf("Chave encontrada!\n");
  else printf("Chave não encontrada!\n");

  liberar_memoria(tabela);
}



int8_t divisores_primos_menores_20 (int8_t m) {
  int8_t primos[] = {2, 3, 5, 7, 11, 13, 17, 19};
  for (int8_t i = 0; i < 8; i++) 
    if (m % primos[i] == 0) return 0;
  
  return 1;
}

int8_t primo (int16_t numero) {
  for (int16_t i = 2; i <= sqrt(numero); i++) {
    if (numero % i == 0) return 0;
  }
  return 1;
}

int8_t paridade (int16_t numero) {
  if (numero % 2 == 0) return 0; 
  return 1; 
}

float funcao_de_carga (int8_t n, int8_t m) {
  return (float) n / m;
}

int gerar_m (int8_t n) {
  int8_t m = n;
  while (true) { 
    if (paridade(m) && primo(m)) { // poderia colocar a funcao: divisores_primos_menores_20()
      printf("O número de chaves (n): %hhd \n",n);
      printf("O tamanho da tabela (m): %hhd \n",m);
      return m;
    } 
    m = m + 1;
  }
}


int main (void) {

  int8_t n;
  printf("Entre com o tamanho 'n' do seu vetor (número de chaves): ");
  scanf("%hhd",&n);
  
  int16_t* vetor = (int16_t*) malloc (sizeof(int16_t) * n);
  
  printf("Insira suas %hhd chaves: \n",n);
  for (int8_t i = 0; i < n; i++)
    scanf("%hd",&vetor[i]);   
  

  exibir_chaves(vetor,n);
  int8_t m = gerar_m(n);
  tabela_hash(vetor, n, m);
  printf("Função de carga: %.3f %% \n",funcao_de_carga(n,m) * 100.0);
  
  return 0;
}
