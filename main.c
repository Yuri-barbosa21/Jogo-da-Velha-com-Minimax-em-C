#include <stdio.h>

char matriz[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char matriz_copia[3][3];

//------------------------ MIN -------------------------
int min(int valor1, int valor2){
    if(valor1 < valor2){
        return valor1;
    }
    return valor2;
}
//______________________________________________________

//------------------------ MAX -------------------------
int max(int valor1, int valor2){
    if(valor1 > valor2){
        return valor1;
    }
    return valor2;
}
//______________________________________________________

//------------------- IMPRIMIR MATRIZ ------------------
void imprimir_matriz(char matriz[3][3]){
    printf("\n    0   1   2\n"); 
    printf("  -------------\n");
    for(int i = 0; i < 3; i++){
        printf("%d ", i); 
        for(int j = 0; j < 3; j++){
            if(matriz[i][j] == ' '){
                printf("|   ");
            } else {
                printf("| %c ", matriz[i][j]);
            }
        }
        printf("|\n");
        printf("  -------------\n"); 
    }
    printf("\n");
}
//_____________________________________________________

//------------------- VERIRICAR JOGADA ------------------
int verificar_jogada(int linha, int coluna, char matriz[3][3]){
    if(matriz[linha][coluna] == 'X' || matriz[linha][coluna] == 'O'){
        return 0;
    }

    if(matriz[linha][coluna] == ' '){
        return 1;
    }
    return 0;
}
//______________________________________________________

//------------------- VERIRICAR EMPATE ------------------
int verificar_empate(char matriz[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(matriz[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}
//______________________________________________________

//------------------- VERIRICAR SE GANHOU ------------------
int verificar_se_ganhou(char jogador, char estado[3][3]){
    // Linhas
    if(estado[0][0] == jogador && estado[0][1] == jogador && estado[0][2] == jogador){
        return 1;
    }
    if(estado[1][0] == jogador && estado[1][1] == jogador && estado[1][2] == jogador){
        return 1;
    }
    if(estado[2][0] == jogador && estado[2][1] == jogador && estado[2][2] == jogador){
        return 1;
    }

    // Colunas
    if(estado[0][0] == jogador && estado[1][0] == jogador && estado[2][0] == jogador){
        return 1;
    }
    if(estado[0][1] == jogador && estado[1][1] == jogador && estado[2][1] == jogador){
        return 1;
    }
    if(estado[0][2] == jogador && estado[1][2] == jogador && estado[2][2] == jogador){
        return 1;
    }

    // Diagonal Principal
    if(estado[0][0] == jogador && estado[1][1] == jogador && estado[2][2] == jogador){
        return 1;
    }
    // Diagonal Secundaria
    if(estado[0][2] == jogador && estado[1][1] == jogador && estado[2][0] == jogador){
        return 1;
    }
    return 0;
}
//______________________________________________________

//------------------------- JOGAR -----------------------
int jogar(int linha, int coluna, char jogador_atual, char matriz[3][3]){
    if(verificar_jogada(linha, coluna, matriz)){
        matriz[linha][coluna] = jogador_atual;
        return 1;
    }else{
        return 0;
    }
}
//______________________________________________________

//----------------- FUNÇÃO UTILIDADE -----------------
int utilidade(char matriz[3][3]){
    if(verificar_se_ganhou('X', matriz)){
        return 1;
    }
    if(verificar_se_ganhou('O', matriz)){
        return -1;
    }
    if(verificar_empate(matriz)){
        return 0;
    }
    return -2;
}
//________________________________________________________

//--------------------- COPIAR MATRIZ --------------------
void copiar_matriz(char matriz[3][3], char matriz_copia[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matriz_copia[i][j] = matriz[i][j];
        }
    }
}
//________________________________________________________

//--------------------- ESTADO TERMINAL ------------------------
int estado_terminal(char matriz[3][3]){
    if(utilidade(matriz) != -2){
        return utilidade(matriz);
    }
    return -2;
}
//________________________________________________________

//--------------------- MINIMAX ------------------------
int minimax(char jogador, char estado[3][3]){
    if(estado_terminal(estado) != -2){
        return estado_terminal(estado);
    }

    if(jogador == 'X'){
        int melhor_pontuacao = 1000;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if (matriz_copia[i][j] == ' '){
                    matriz_copia[i][j] = 'X';
                    int pontuacao = minimax('O', estado);
                    melhor_pontuacao = min(melhor_pontuacao, pontuacao);
                    matriz_copia[i][j] = ' ';
                }
            }
        }
        return melhor_pontuacao;
    }else{
        int melhor_pontuacao = -1000;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if (matriz_copia[i][j] == ' '){
                    matriz_copia[i][j] = 'O';
                    int pontuacao = minimax('X', estado);
                    melhor_pontuacao = max(melhor_pontuacao, pontuacao);
                    matriz_copia[i][j] = ' ';
                }
            }
        }
        return melhor_pontuacao;
    }
}
//________________________________________________________

//----------------- JOGADA MINIMAX -----------------
void jogar_minimax(){
    int melhor_pontuacao = -1000;
    int melhor_jogada[2];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(matriz[i][j] == ' '){
                copiar_matriz(matriz, matriz_copia);
                matriz_copia[i][j] = 'X';
                int pontuacao = minimax('X', matriz_copia);
                if(pontuacao > melhor_pontuacao){
                    melhor_pontuacao = pontuacao;
                    melhor_jogada[0] = i;
                    melhor_jogada[1] = j;
                }
                
            }
        }
    }
    jogar(melhor_jogada[0], melhor_jogada[1], 'X', matriz);
}
//________________________________________________________

int main(void){
    char player = 'O';
    char minimax = 'X';

    int linha = 0;
    int coluna = 0;
    
    char jogador_atual = minimax;

    printf("Bem-vindo ao Jogo da Velha contra o algoritmo de IA Minimax\n\n");
    
    int jogando = 1;
    while(jogando == 1){
        imprimir_matriz(matriz);

        if(jogador_atual == 'X'){
            printf("Minimax: \n");

            jogar_minimax();
            if (verificar_se_ganhou(jogador_atual, matriz)){
                jogando = 0;
            }
            jogador_atual = player;

        }else{
            printf("Player: \n");
            
            printf("Digite a linha: ");
            scanf("%d", &linha);
            printf("Digite a coluna: ");
            scanf("%d", &coluna);    

            if(jogar(linha, coluna, jogador_atual, matriz)){
                if (verificar_se_ganhou(jogador_atual, matriz)){
                    jogando = 0;
                }
                jogador_atual = minimax;
            }            
            
        }

        if(verificar_empate(matriz)){
            jogando = 2;
        }
        
    }


    imprimir_matriz(matriz);
    if(jogador_atual == 'X' && jogando == 0){
        printf("\nPlayer ganhou!");
    }else if (jogador_atual == 'O' && jogando == 0){
        printf("\nMinimax ganhou!");
    }

    if(jogando == 2){
        printf("\nDeu velha!");
    }
    


    return 0;
}