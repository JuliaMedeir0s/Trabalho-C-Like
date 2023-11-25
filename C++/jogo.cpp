#include <iostream>
#include <vector>

using namespace std;

// criar o tabuleiro 3x3 com alocação dinâmica usando vector
vector<vector<char>> criarTabuleiro(int tamanho)
{
    return vector<vector<char>>(tamanho, vector<char>(tamanho, ' '));
}

// liberar a memória alocada
void liberarMemoria(vector<vector<char>>& tabuleiro)
{
    tabuleiro.clear();
}

// imprimir o tabuleiro
void imprimirTabuleiro(const vector<vector<char>>& tabuleiro, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        cout << " " << tabuleiro[i][0] << " | " << tabuleiro[i][1] << " | " << tabuleiro[i][2] << " \n";
        if (i < 2)
        {
            cout << "---+---+--- \n";
        }
    }
}

// verificar resultado final do jogo
bool verificarResultado(const vector<vector<char>>& tabuleiro, int tamanho)
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
    vector<vector<char>> tabuleiro = criarTabuleiro(tamanho);
    int linha, coluna, jogadas = 0;
    char jogador = 'X';
    bool fimDoJogo = false;

    // registrar as jogadas
    while (!fimDoJogo)
    {
        imprimirTabuleiro(tabuleiro, tamanho);
        do
        {
            cout << "\nJogador " << jogador << ", informe a linha e a coluna que deseja jogar: ";
            cin >> linha >> coluna;
            if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3)
            {
                cout << "Posição inválida! Tente novamente\n";
            }
            else
            {
                cout << "\n";
            }
        } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3);

        // verificar se a linha e a coluna informadas são válidas e conferir se o local escolhido está disponível
        if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabuleiro[linha - 1][coluna - 1] == ' ')
        {
            tabuleiro[linha - 1][coluna - 1] = jogador;
            jogadas++;

            // verifica se o jogo acabou. se tiver acabado, retorna o resultado
            fimDoJogo = verificarResultado(tabuleiro, tamanho);

            // mudar o jogador da vez
            if (!fimDoJogo)
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
            cout << "Jogada inválida. Tente novamente!\n";
        }
    }
    // jogo finalizou
    imprimirTabuleiro(tabuleiro, tamanho);
    cout << "\nO jogo acabou!\n";
    // informar quem venceu o jogo
    if (jogadas == 9)
    {
        cout << "FOI EMPATE";
    }
    else
    {
        cout << "\nJogador " << jogador << " venceu!\n";
    }

    // nunca se esqueça de liberar a memória alocada
    liberarMemoria(tabuleiro);

    return 0;
}
