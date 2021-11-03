#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define M 4 // tamanho da tabela


typedef struct no {
  int valor;
  struct no* prox;
} No;


enum opcoes {
  INSERIR = 1,
  BUSCAR = 2,
  EXIBIR_TABELA = 3,
  SAIR = 4
};

void exibir_menu () {
  puts("[1] - Inserir chave");
  puts("[2] - Buscar  chave");
  puts("[3] - Exibir tabela hash");
  puts("[4] - SAIR");
}

void erro (char *msg) {
  fprintf(stdout, "Erro: %s \n",msg);
}

void liberar_memoria_lista (No** tabela) {
  No* aux, *lixo;
  for (uint8_t i = 0; i < M; i++) {
    aux = tabela[i];
    while (aux != NULL) {
      lixo = aux;
      aux = aux -> prox;
      free(lixo);
    }
  }
}

void liberar_memoria_tabela (No** tabela) {
   free(tabela);
}

void adicionar (No** tabela, int local, int chave) {
  No* NO = (No*) malloc (sizeof(No));
  NO -> valor = chave;
  NO -> prox = NULL;
  
  if (NO == NULL) {
    erro("Falha na alocacao de memoria!");
    return;
  }
  
  if (tabela[local] == NULL) {
    tabela[local] = NO;
  }
  else {                     
    No* aux = tabela[local];               
    while (aux -> prox != NULL) { 
      aux = aux -> prox; 
    }                 
    aux -> prox = NO;  
  }
}

int localizacao (int chave) {
  return chave % M;
}

bool buscar (No** tabela, int chave) {
  int local = localizacao(chave);
  No* aux = tabela[local];

  while (aux != NULL) {
    if (aux -> valor == chave) return true;
    aux = aux -> prox;
  }

  return false;
}

void copular_tabela (No** tabela, int chave) {
  bool sinalizadora = buscar(tabela, chave);
  
  if (sinalizadora == false) { 
    int local = localizacao(chave);
    adicionar (tabela, local, chave);
  }
  else {
    erro("Chave ja esta na tabela!");
  }
}

void percorrer_lista_encadeada (No* inicio) {
  while (inicio != NULL) {
    printf("%d ",inicio -> valor);
    inicio = inicio -> prox;
  }
  printf("\n");
}

void exibir_tabela (No** tabela) {
  for (uint8_t local = 0; local < M; local++) {
    printf("[%hhd] --> ",local);
    percorrer_lista_encadeada (tabela[local]);
  }
}

int main (void) {
  No** tabela;
  
  tabela = (No**) malloc (sizeof(No*) * M);

  for (uint8_t i = 0; i < M; i++)
    tabela[i] = NULL;  
      
  
  /*  0  [*] -->  NULL 
   *  1  [*] -->  NULL
   *  2  [*] -->  NULL
   *  3  [*] -->  NULL
   *  4  [*] -->  NULL
   *  5  [*] -->  NULL
   *  6  [*] -->  NULL
   */
  
  /*  0  [*] --> (chave) --> (chave) --> NULL 
   *  1  [*] --> (chave) --> NULL
   *  2  [*] --> NULL
   *  3  [*] --> (chave) --> (chave) --> NULL
   *  4  [*] --> NULL
   *  5  [*] --> (chave) --> NULL
   *  6  [*] --> (chave) --> NULL
   */
  uint8_t op;

  while (true) {
    exibir_menu();
    printf("Escolha uma opcao: ");
    scanf("%hhd",&op);
    
    if (op == SAIR) {
      liberar_memoria_lista(tabela);
      liberar_memoria_tabela(tabela);
      break;
    }

    switch (op) {
      int chave;
      
      case INSERIR:
        printf("Entre com sua chave: ");
        scanf("%d",&chave);
        copular_tabela(tabela, chave);
        break;
      
      case BUSCAR:
        printf("Chave que deseja buscar: ");
        scanf("%d",&chave);
        int sinalizador = buscar(tabela, chave);

        if (sinalizador) printf("Chave encontrada! \n");
        else             printf("Chave nao encontrada! \n");
        break;
      
      case EXIBIR_TABELA:
        exibir_tabela(tabela);
        break;
    }
  }   
  return 0;
}
