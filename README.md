# 🧬 Ligacao De Nucleotideos 

# 📌 Sobre o Projeto 

Este projeto foi desenvolvido em Julho de 2023, como parte de uma Atividade Acadêmica sobre Estrutura de Dados em Linguagem C. O objetivo desse projeto é simular a conversão de sequências de DNA utilizando estruturas de dados dinâmicas, como filas e pilhas. O programa lê uma sequência de nucleotídeos (A, C, T, G), a armazena em uma fila dinâmica e, em seguida, converte essa sequência para uma segunda fita de DNA, armazenando-a em uma pilha dinâmica.

É a Perfeita União da Biologia com a Programação 🍃

# 🎬 Demonstração 

<p align="center">
  <img width="600" height="450" src="assets/ligação-de-nucleotideos (GIF).gif">
</p>

# ⚙️ Funcionalidades

O Projeto Apresenta as Seguintes Funcionalidades:

1. Inserção de Sequência: O usuário pode inserir uma sequência de nucleotídeos (A, C, T, G).

2. Conversão para Dupla Fita: A sequência inserida é convertida para sua respectiva dupla fita de DNA, utilizando as regras de pareamento de nucleotídeos (A ↔ T, C ↔ G).
   
3. Impressão das Estruturas: O programa imprime a sequência original (armazenada na fila) e a sequência convertida (armazenada na pilha).

4. Operações Dinâmicas: Uso de estruturas dinâmicas para manipulação de filas e pilhas, com funções para inserir, excluir e imprimir os dados.

# 🔗 Principais Estruturas 

Fila Dinâmica (FIFO - First In, First Out)

A fila armazena a sequência de nucleotídeos digitada pelo usuário. Nessa estrutura, o primeiro elemento inserido é o primeiro a ser removido.

Funções Implementadas:

- inserirFila(): Insere um nucleotídeo na fila.
- excluirFila(): Remove um nucleotídeo da fila.
- imprimirFila(): Exibe todos os nucleotídeos na fila.
  
Pilha Dinâmica (LIFO - Last In, First Out)

A pilha armazena a sequência convertida, correspondente à segunda fita de DNA. Nessa estrutura, o último elemento inserido é o primeiro a ser removido.

Funções Implementadas:

- inserirPilha(): Insere um nucleotídeo na pilha.
- excluirPilha(): Remove um nucleotídeo da pilha.
- imprimirPilha(): Exibe todos os nucleotídeos na pilha.

