#include <stdio.h>

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[3][3]) {
    printf("\nTabuleiro Atual:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

// Função para verificar se um jogador venceu
int verificarVencedor(char tabuleiro[3][3], char jogador) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)) {
            return 1; // Jogador venceu
        }
    }

    // Verificar diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)) {
        return 1; // Jogador venceu
    }

    return 0; // Ninguém venceu ainda
}

// Função principal
int main() {
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int linha, coluna;
    char jogadorAtual = 'X';
    int jogadas = 0;

    do {
        imprimirTabuleiro(tabuleiro);

        // Obter a jogada do jogador atual
        printf("Jogador %c, insira a linha (0-2) e a coluna (0-2) separadas por espaco: ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);

        // Verificar se a posição escolhida é válida
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }

        // Realizar a jogada
        tabuleiro[linha][coluna] = jogadorAtual;
        jogadas++;

        // Verificar se o jogador atual venceu
        if (verificarVencedor(tabuleiro, jogadorAtual)) {
            imprimirTabuleiro(tabuleiro);
            printf("Parabéns, Jogador %c! Você venceu!\n", jogadorAtual);
            break;
        }

        // Verificar empate
        if (jogadas == 9) {
            imprimirTabuleiro(tabuleiro);
            printf("O jogo terminou em empate!\n");
            break;
        }

        // Alternar para o próximo jogador
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';

    } while (1); // Loop infinito, termina quando alguém vencer ou o jogo empatar

    return 0;
}
