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
  // e liberação da memória do espaço antigo
  int* old_data = data;
  data = new_mem_loc;
  delete [] old_data;
}
```

## Linked List
Estrutura de dado feita com lista duplamente ligada, nela alocamos um **novo espaço de memória para cada nó dinamicamente** e cada nó aponta para o próximo e o anterior. Sendo assim, esta estrutura de dado é mais eficiente para operações de inserção e remoção, entretanto, quando temos que achar um valor específico temos que percorrer a lista, sendo menos eficiente que o **ArrayList**.

```
void push_back(int value){
    if(size_ == 0){
        // Criação do novo nó
        int_node* new_val = new int_node;
        new_val->value = value;

        // Como neste caso a lista está vazia, o próximo nó e o anterior seráo NULL
        new_val->next = nullptr;
        new_val->prev = nullptr;

        // Como neste caso a lista está vazia, o HEAD e o TAIL apontarão para o novo nó
        head = new_val;
        tail = new_val;
    }else{
        // Criação do novo nó
        int_node* new_val = new int_node;
        new_val->value = value;

        // Como o nó está sendo adicionado no fim, o próximo nó será NULL e o anterior será o nó apontado por TAIL
        new_val->next = nullptr;
        new_val->prev = tail;

        // Muda o ponteiro de próximo nó do ANTIGO TAIL para o novo nó
        tail->next = new_val;

        // Muda o ponteiro TAIL para o novo nó
        tail = new_val;
    }

    size_++;
}
```

## Testes

- Seção em desenvolvimento
