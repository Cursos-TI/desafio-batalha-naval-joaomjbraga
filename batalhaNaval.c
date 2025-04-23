#include <stdio.h>

#define TAMANHO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Coordenadas dos navios
    int linha_horizontal = 1; // Segunda linha (índice 1)
    int coluna_horizontal = 1; // Coluna B (índice 1)

    int linha_vertical = 5; // Sexta linha (índice 5)
    int coluna_vertical = 0; // Coluna A (índice 0)

    int linha_diagonal1 = 0; // Início da diagonal ↘
    int coluna_diagonal1 = 7;

    int linha_diagonal2 = 2; // Início da diagonal ↙
    int coluna_diagonal2 = 7;

    // Validação de limites
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO ||
        linha_vertical + TAMANHO_NAVIO > TAMANHO ||
        linha_diagonal1 + TAMANHO_NAVIO > TAMANHO || coluna_diagonal1 + TAMANHO_NAVIO > TAMANHO ||
        linha_diagonal2 + TAMANHO_NAVIO > TAMANHO || coluna_diagonal2 - (TAMANHO_NAVIO - 1) < 0) {
        printf("Erro: navios fora dos limites.\n");
        return 1;
    }

    // Verifica sobreposição
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] == 3 ||
            tabuleiro[linha_vertical + i][coluna_vertical] == 3 ||
            tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] == 3 ||
            tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] == 3) {
            printf("Erro: Sobreposição de navios.\n");
            return 1;
        }
    }

    // Posiciona navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = 3;
    }

    // Posiciona navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = 3;
    }

    // Posiciona navio diagonal ↘
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = 3;
    }

    // Posiciona navio diagonal ↙
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = 3;
    }

    // Cabeçalho com letras
    printf("    TABULEIRO  BATALHA  NAVAL\n");
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO; letra++) {
        printf(" %c", letra);
    }
    printf("\n");

    // Impressão da matriz com números nas linhas
    for (int i = 0; i < TAMANHO; i++) {
        printf("%2d ", i + 1); // Números de 1 a 10
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
