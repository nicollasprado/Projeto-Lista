# Projeto Lista ![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg) [![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](https://lbesson.mit-license.org/)
Nesse projeto criei minha própria implementação de um **Array List com alocação dinâmica** e uma **Lista Duplamente Ligada** que simulam estruturas de dados como a lista do python e arraylist do java.

## Objetivo
Projeto criado com objetivo de desenvolver minhas habilidades com estruturas de dados mais complexas, interação com a memória do computador e análise de algoritmos.

## Pré requisitos
- [Compilador G++](https://sourceforge.net/projects/mingw-w64/)

<br>

## Array List
Estrutura de dado feita com alocação dinâmica, nela temos que liberar manualmente a memória alocada e é menos eficiente que a **Linked List** nas operações de inserção e remoção em índices específicos pois temos que percorrer toda a lista para trocar as posições dos elementos.

```
void increase_capacity(){
  capacity_ = capacity_ * 2;

  // Criação do novo espaço de memória com mais capacidade
  int* new_mem_loc = new int[capacity_];

  // Loop para adicionar os itens já presentes na lista para o novo espaço de memória
  for(unsigned int i = 0; i < size_; i++){
      new_mem_loc[i] = data[i];
  }

  // Mudança do ponteiro data para o novo espaço de memória com mais capacidade
  // e libera a memória do espaço antigo
  int* old_data = data;
  data = new_mem_loc;
  delete [] old_data;
}
```

## Linked List
Estrutura de dado feita com lista duplamente ligada.

- Em desenvolvimento

## Testes

- Seção em desenvolvimento
