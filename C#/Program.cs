using System;

class Program
{
    // criar o tabuleiro 3x3 com alocação dinâmica (essa função retorna uma matriz bidimensional)
    static char[,] CriarTabuleiro(int tamanho)
    {
        char[,] tabuleiro = new char[tamanho, tamanho]; // criando uma matriz 2D

        for (int i = 0; i < tamanho; i++)
        {
            for (int j = 0; j < tamanho; j++)
            {
                tabuleiro[i, j] = ' '; // determinando os espaços
            }
        }
        return tabuleiro;
    }

    // imprimir o tabuleiro
    static void ImprimirTabuleiro(char[,] tabuleiro, int tamanho)
    {
        for (int i = 0; i < tamanho; i++)
        {
            Console.WriteLine($" {tabuleiro[i, 0]} | {tabuleiro[i, 1]} | {tabuleiro[i, 2]} ");
            if (i < tamanho - 1)
            {
                Console.WriteLine("---+---+---");
            }
        }
    }

    // verificar resultado final do jogo
    static bool VerificarResultado(char[,] tabuleiro, int tamanho)
    {
        // verificar possibilidades de vitória
        for (int i = 0; i < tamanho; i++)
        {
            // vitória em linha
            if (tabuleiro[i, 0] == tabuleiro[i, 1] && tabuleiro[i, 1] == tabuleiro[i, 2] && tabuleiro[i, 0] != ' ')
            {
                return true;
            }
            // vitória em coluna
            if (tabuleiro[0, i] == tabuleiro[1, i] && tabuleiro[1, i] == tabuleiro[2, i] && tabuleiro[0, i] != ' ')
            {
                return true;
            }
        }
        // na diagonal
        if (tabuleiro[0, 0] == tabuleiro[1, 1] && tabuleiro[1, 1] == tabuleiro[2, 2] && tabuleiro[0, 0] != ' ')
        {
            return true;
        }
        if (tabuleiro[0, 2] == tabuleiro[1, 1] && tabuleiro[1, 1] == tabuleiro[2, 0] && tabuleiro[0, 2] != ' ')
        {
            return true;
        }

        // verificar se o jogo acabou ou se foi um empate
        for (int i = 0; i < tamanho; i++)
        {
            for (int j = 0; j < tamanho; j++)
            {
                if (tabuleiro[i, j] == ' ')
                {
                    return false; // jogo ainda não acabou
                }
            }
        }
        return true; // acabou o jogo e foi empate
    }

    static void Main(string[] args)
    {
        int tamanho = 3; // o tabuleiro é 3x3
        char[,] tabuleiro = CriarTabuleiro(tamanho);
        int linha, coluna, jogadas = 0;
        char jogador = 'X';
        bool fimDoJogo = false;

        // registrar as jogadas
        while (!fimDoJogo)
        {
            ImprimirTabuleiro(tabuleiro, tamanho);
            do
            {
                Console.Write($"\nJogador {jogador}, informe a linha e a coluna que deseja jogar (1-3 separados por espaço): ");
                string[] input = Console.ReadLine().Split(' ');
                linha = int.Parse(input[0]) - 1;
                coluna = int.Parse(input[1]) - 1;

                if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2)
                {
                    Console.WriteLine("Posição inválida! Tente novamente\n");
                }
                else
                {
                    Console.WriteLine("\n");
                }
            } while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2);

            // verificar se a linha e a coluna informadas são válidas e conferir se o local escolhido está disponível
            if (tabuleiro[linha, coluna] == ' ')
            {
                tabuleiro[linha, coluna] = jogador;
                jogadas++;

                // verifica se o jogo acabou. se tiver acabado, retorna o resultado
                fimDoJogo = VerificarResultado(tabuleiro, tamanho);

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
                Console.WriteLine("Jogada inválida. Tente novamente!\n");
            }
        }
        // jogo finalizou
        ImprimirTabuleiro(tabuleiro, tamanho);
        Console.WriteLine("\nO jogo acabou!\n");
        // informar quem venceu o jogo
        if (jogadas == 9)
        {
            Console.WriteLine("FOI EMPATE");
        }
        else
        {
            Console.WriteLine($"\nJogador {jogador} venceu!\n");
        }

        Console.ReadKey(); // Espera um pressionamento de tecla para encerrar o console
    }
}