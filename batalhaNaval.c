#include <stdio.h>

int main() {
    int tabuleiro[10][10];   // tabuleiro 10x10
    int linha, coluna, i;    // declaradas fora dos laços

    // ===== 1) Inicializar o tabuleiro com 0 (água) =====
    for (linha = 0; linha < 10; linha++) {          // percorre linhas
        for (coluna = 0; coluna < 10; coluna++) {   // percorre colunas
            tabuleiro[linha][coluna] = 0;           // zera tudo (água)
        }
    }

    // ===== 2) Configuração dos navios =====
    int navioHorizontal = 3;   // tamanho 3
    int navioVertical   = 3;   // tamanho 3

    // coordenadas iniciais (0-based)
    int linhaInicialH = 2 - 1;     // navio horizontal na linha 2
    int colunaInicialH = 3 - 1;    // começa na coluna 3
    int linhaInicialV = 5 - 1;     // navio vertical começa na linha 5
    int colunaInicialV = 7 - 1;    // na coluna 7
    // o -1 e pra arrumar a numeraçao com a real posiçao ja que vetor começa em 0

    // ===== 3) Posicionar navio horizontal (substitui 0 -> 3) =====
    for (i = 0; i < navioHorizontal; i++) {
        tabuleiro[linhaInicialH][colunaInicialH + i] = 3;
        // ocupa: [linhaInicialH][colunaInicialH], [..+1], [..+2]
    }

    // ===== 4) Posicionar navio vertical (substitui 0 -> 3) =====
    for (i = 0; i < navioVertical; i++) {
        tabuleiro[linhaInicialV + i][colunaInicialV] = 3;
        // ocupa: [linhaInicialV][colunaInicialV], [..+1], [..+2]
    }

    // ===== 5) Imprimir o tabuleiro =====
    printf("\nBATALHA NAVAL\n");

    // letras no topo (colunas A..J)
    printf("   ");
    for (coluna = 0; coluna < 10; coluna++) {
        printf("%c ", 'A' + coluna);
    }
    printf("\n");

    // números do lado (linhas 1..10) + conteúdo (0 = água, 3 = navio)
    for (linha = 0; linha < 10; linha++) {
        printf("%2d ", linha + 1);
        for (coluna = 0; coluna < 10; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
