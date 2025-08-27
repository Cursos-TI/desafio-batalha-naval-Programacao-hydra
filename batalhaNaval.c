#include <stdio.h>

#define linhas 10
#define colunas 10
#define naviohorizontal 3
#define naviovertical  3
#define naviodiagonal1  3
#define naviodiagonal2 3

int main(){
    // ===== 1) Inicializar o tabuleiro com 0 (água) =====
    int matriz[linhas][colunas];

    for (int l = 0; l < linhas; l++) //percorre linhas
    {
        for (int c = 0; c < colunas; c++) //percorre colnas
        {
            matriz[l][c] = 0; // zera tudo (0 = agua)
        }
        
    }

    // coordenadas iniciais (0-based)
    int linhaInicialH = 2 - 1;     // navio horizontal começa na linha 2
    int colunaInicialH = 3 - 1;    // começa na coluna 3
    int linhaInicialV = 5 - 1;     // navio vertical começa na linha 5
    int colunaInicialV = 7 - 1;    // na coluna 7
    int linhainicialD1 = 6 - 1; // navio diagonal 1 começa na linha 6
    int colunainicialD1 = 3 - 1; // coluna 3
    int linhainicialD2 = 10 -1; // navio diagonal 2 começa na linha 10
    int colunainicialD2 = 6 - 1; // coluna 6
    // O - 1 é par acertar a posiçao do navio ja que o indice começa em 0

    int i;

     // ===== 3) Posicionar navio horizontal (substitui 0 -> 3) =====
    for (i = 0; i < naviohorizontal; i++) {
        matriz[linhaInicialH][colunaInicialH + i] = 3;
        // ocupa: [linhaInicialH][colunaInicialH], [..+1], [..+2]
    }

    // ===== 4) Posicionar navio vertical (substitui 0 -> 3) =====
    for (i = 0; i < naviovertical; i++) {
        matriz[linhaInicialV + i][colunaInicialV] = 3;
        // ocupa: [linhaInicialV][colunaInicialV], [..+1], [..+2]
    }

    // ===== 4) Posicionar navio Diagonal 1 (substitui 0 -> 3) =====
    for (i = 0; i < naviodiagonal1; i++)
    {
        matriz[linhainicialD1 - i][colunainicialD1 - i] = 3;
        // ocupa: [linhaInicialD1][colunaInicialD1], [..+1], [..+2]
    } 
     /*
        Explicação detalhada:
        - A posição inicial é (linhainicialD1, colunainicialD1)
        - Para cada incremento de i (0,1,2), subtraímos de linha e coluna
          para mover na diagonal "para cima e para a esquerda" no tabuleiro.
        - Assim, ocupamos as seguintes posições:
          i=0: [linhainicialD1][colunainicialD1] -> posição inicial
          i=1: [linhainicialD1-1][colunainicialD1-1] -> uma casa na diagonal
          i=2: [linhainicialD1-2][colunainicialD1-2] -> outra casa na diagonal
        - Essa lógica cria um navio de tamanho 3 na diagonal.
        - Lembre-se que linhas e colunas começam do índice 0.
    */

    // ===== 4) Posicionar navio Diagonal 2 (substitui 0 -> 3) =====
    for (i = 0; i < naviodiagonal1; i++)
    {
        matriz[linhainicialD2 - i][colunainicialD2 - i] = 3;
        // ocupa: [linhaInicialD1][colunaInicialD1], [..+1], [..+2]
    }
      /*
        Explicação detalhada:
        - A posição inicial é (linhainicialD2, colunainicialD2)
        - Cada incremento de i move a posição "para cima e para a esquerda"
          novamente, formando a diagonal.
        - As posições ocupadas serão:
          i=0: [linhainicialD2][colunainicialD2] -> posição inicial
          i=1: [linhainicialD2-1][colunainicialD2-1] -> uma casa na diagonal
          i=2: [linhainicialD2-2][colunainicialD2-2] -> outra casa na diagonal
        - Novamente, cria um navio de tamanho 3 na diagonal.
        - Essa abordagem funciona porque você define manualmente as coordenadas
          e garante que elas não ultrapassem os limites do tabuleiro.
    */
    
    // ===== 5) Imprimir o tabuleiro =====
    printf("\nBATALHA NAVAL\n");

    // letras no topo (colunas A..J)
    printf("   ");
    for (int c = 0; c < colunas; c++) {
        printf("%c ", 'A' + c);
    }
    printf("\n");

    // números do lado (linhas 1..10) + conteúdo (0 = água, 3 = navio)
    //impressao do tabuleiro prenchido com as cordenadas escritas pelo programador !!!
    for (int l = 0; l < linhas; l++) {
        printf("%2d ", l + 1);
        for (int c = 0; c < colunas; c++) {
            printf("%d ", matriz[l][c]);
        }
        printf("\n");
    }

    /*
    OBS; Nao fiz analise de erro do propio programa indentificar sobreposiçao 
    dos navios, ja que nao temos entrada de ususrios externos no codigo! todas 
    as posiçoes sao definidas pelo programador!
    */
    return 0;
}
