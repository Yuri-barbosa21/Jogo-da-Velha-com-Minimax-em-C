# Jogo da Velha com Minimax em C
Este projeto é um exemplo de implementação do jogo da velha com a utilização do algoritmo minimax em C. O minimax é um algoritmo de busca utilizado em jogos de dois jogadores com informação perfeita. Ele é utilizado para encontrar o melhor movimento para um jogador em um determinado estado do jogo.

O jogo da velha é um jogo simples em que dois jogadores se alternam em marcar um X ou um O em um tabuleiro 3x3. O objetivo do jogo é conseguir formar uma linha, coluna ou diagonal com os mesmos símbolos.

O código aqui apresentado implementa o algoritmo minimax em C para jogar o jogo da velha. O algoritmo é responsável por encontrar o melhor movimento para o jogador em um determinado estado do jogo. O algoritmo é baseado em uma função de utilidade que avalia o valor de um determinado estado do jogo e em uma árvore de jogadas possíveis. A função de utilidade é utilizada para avaliar o valor de um estado do jogo, enquanto a árvore de jogadas é utilizada para determinar qual é o melhor movimento para o jogador.

## Funções
**min(int valor1, int valor2)**<br>
Função auxiliar que retorna o menor valor entre dois valores.

**max(int valor1, int valor2)**<br>
Função auxiliar que retorna o maior valor entre dois valores.

**imprimir_matriz(char matriz[3][3])**<br>
Função responsável por imprimir o tabuleiro do jogo.

**verificar_jogada(int linha, int coluna, char matriz[3][3])**<br>
Função responsável por verificar se uma jogada é válida.

**verificar_empate(char matriz[3][3])**<br>
Função responsável por verificar se o jogo terminou em empate.

**verificar_se_ganhou(char jogador, char estado[3][3])**<br>
Função responsável por verificar se um jogador ganhou o jogo.

**jogar(int linha, int coluna, char jogador_atual, char matriz[3][3])**<br>
Função responsável por realizar uma jogada.

**utilidade(char matriz[3][3])**<br>
Função responsável por avaliar o valor de um estado do jogo.

**copiar_matriz(char matriz[3][3], char matriz_copia[3][3])**<br>
Função auxiliar responsável por copiar uma matriz.

**estado_terminal(char matriz[3][3])**<br>
Função responsável por verificar se um estado do jogo é terminal.

**minimax(char jogador, char matriz[3][3], int profundidade)**<br>
Função principal responsável por implementar o algoritmo minimax.

## Como jogar
Para jogar o jogo da velha, basta executar o arquivo main.c. O jogador será representado pelo símbolo X e o computador pelo símbolo O. O jogador deve escolher uma posição no tabuleiro para realizar uma jogada. O computador realizará a sua jogada em seguida. O jogo terminará quando um dos jogadores conseguir formar uma linha, coluna ou diagonal com os mesmos símbolos ou quando o jogo terminar empatado.
