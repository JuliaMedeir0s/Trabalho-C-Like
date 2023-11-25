#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// criar o tabuleiro 3x3 com alocação dinâmica (essa função retorna um ponteiro de ponteiros, ou seja, uma matriz bidimensional)
char **criarTabuleiro(int tamanho)
{
    char **tabuleiro = (char **)malloc(tamanho * sizeof(char *)); // alocando memória para um ponteiro de ponteiro (char**)
    for (int i = 0; i < tamanho; i++)
    {
        tabuleiro[i] = (char *)malloc(tamanho * sizeof(char)); // alocando o espaço correto de caractéres para a linha i (ponteiro de caracteres - char*)
        for (int j = 0; j < tamanho; j++)
        {
            tabuleiro[i][j] = ' '; // determinando os espaços
        }
    }
    return tabuleiro;
}

// liberar a memória alocada
void liberarMemoria(char **tabuleiro, int tamanho)
{
    // liberar a memória de dentro pra fora
    for (int i = 0; i < tamanho; i++)
    {
        free(tabuleiro[i]);
    }
    free(tabuleiro);
}

// imprimir o tabuleiro
void imprimirTabuleiro(char **tabuleiro, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
        if (i < 2)
        {
            printf("---+---+--- \n");
        }
    }
}

// verificar resultado final do jogo
bool verificarResultado(char **tabuleiro, int tamanho)
{
    // verificar possibilidades de vitória
    for (int i = 0; i < tamanho; i++)
    {
        // vitória em linha
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
        {
            return true;
        }
        // vitória em coluna
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
        {
            return true;
        }
    }
    // na diagonal
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
    {
        return true;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
    {
        return true;
    }

    // verificar se o jogo acabou ou se foi um empate
    for (int i = 0; i < tamanho; i++)
    { // linha
        for (int j = 0; j < tamanho; j++)
        { // coluna
            if (tabuleiro[i][j] == ' ')
            {
                return false; // jogo ainda não acabou
            }
        }
    }
    return true; // acabou o jogo e foi empate
}

int main()
{
    int tamanho = 3; // o tabuleiro é 3x3
    char **tabuleiro = criarTabuleiro(tamanho);
    int linha, coluna, jogadas = 0;
    char jogador = 'X';
    bool fimDoJogo = false;

    // registrar as jogadas
    while (!fimDoJogo)
    {
        imprimirTabuleiro(tabuleiro, tamanho);

        printf("\nJogador %c, informe a linha e a coluna que deseja jogar: ", jogador);
        scanf("%d %d", &linha, &coluna);
        printf("\n");

        // verificar se a linha e a coluna informadas são válidas e conferir se o local escolhido está disponível
        if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabuleiro[linha - 1][coluna - 1] == ' ')
        {
            tabuleiro[linha - 1][coluna - 1] = jogador;
            jogadas++;

            // verifica se o jogo acabou. se tiver acabado, retorna o resultado
            fimDoJogo = verificarResultado(tabuleiro, tamanho);

            // mudar o jogador da vez
            if (fimDoJogo == false)
            {
                jogador = (jogador == 'X') ? 'O' : 'X';
            }
            else
            {
                continue;
            }
        }
        else
        {
            printf("Jogada inválida. Tente novamente!\n");
        }
    }
    // jogo finalizou
    imprimirTabuleiro(tabuleiro, tamanho);
    printf("\nO jogo acabou!\n");
    // informar quem venceu o jogo
    if (jogadas == 9)
    {
        printf("FOI EMPATE");
    }
    else
    {
        printf("\nJogador %c venceu!\n", jogador);
    }

    // nunca se esquça de liberar a memória alocada
    liberarMemoria(tabuleiro, tamanho);

    return 0;
}