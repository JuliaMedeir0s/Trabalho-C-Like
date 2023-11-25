import java.util.Scanner;

public class Main {
    // criar o tabuleiro 3x3 com alocação dinâmica (essa função retorna uma matriz bidimensional)
    public static char[][] criarTabuleiro(int tamanho) {
        char[][] tabuleiro = new char[tamanho][tamanho];
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                tabuleiro[i][j] = ' '; // determinando os espaços
            }
        }
        return tabuleiro;
    }

    // imprimir o tabuleiro
    public static void imprimirTabuleiro(char[][] tabuleiro) {
        for (int i = 0; i < tabuleiro.length; i++) {
            System.out.printf(" %c | %c | %c \n", tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
            if (i < tabuleiro.length - 1) {
                System.out.println("---+---+---");
            }
        }
    }

    // verificar resultado final do jogo
    public static boolean verificarResultado(char[][] tabuleiro) {
        int tamanho = tabuleiro.length;

        // verificar possibilidades de vitória
        for (int i = 0; i < tamanho; i++) {
            // vitória em linha
            if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
                return true;
            }
            // vitória em coluna
            if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
                return true;
            }
        }
        // na diagonal
        if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ') {
            return true;
        }
        if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
            return true;
        }

        // verificar se o jogo acabou ou se foi um empate
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                if (tabuleiro[i][j] == ' ') {
                    return false; // jogo ainda não acabou
                }
            }
        }
        return true; // acabou o jogo e foi empate
    }

    public static void main(String[] args) {
        int tamanho = 3; // o tabuleiro é 3x3
        char[][] tabuleiro = criarTabuleiro(tamanho);
        int linha, coluna, jogadas = 0;
        char jogador = 'X';
        boolean fimDoJogo = false;
        Scanner scanner = new Scanner(System.in);

        // registrar as jogadas
        while (!fimDoJogo) {
            imprimirTabuleiro(tabuleiro);
            do {
                System.out.printf("\nJogador %c, informe a linha que deseja jogar: ", jogador);
                linha = scanner.nextInt();
              System.out.printf("\nJogador %c, informe a coluna que deseja jogar: ", jogador);
                coluna = scanner.nextInt();
                if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
                    System.out.println("Posição inválida! Tente novamente");
                } else {
                    System.out.println();
                }
            } while (linha < 1 || linha > 3 || coluna < 1 || coluna > 3);

            // verificar se a linha e a coluna informadas são válidas e conferir se o local escolhido está disponível
            if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabuleiro[linha - 1][coluna - 1] == ' ') {
                tabuleiro[linha - 1][coluna - 1] = jogador;
                jogadas++;

                // verifica se o jogo acabou. se tiver acabado, retorna o resultado
                fimDoJogo = verificarResultado(tabuleiro);

                // mudar o jogador da vez
                if (!fimDoJogo) {
                    jogador = (jogador == 'X') ? 'O' : 'X';
                } else {
                    continue;
                }
            } else {
                System.out.println("Jogada inválida. Tente novamente!");
            }
        }

        // jogo finalizou
        imprimirTabuleiro(tabuleiro);
        System.out.println("\nO jogo acabou!");

        // informar quem venceu o jogo
        if (jogadas == 9) {
            System.out.println("FOI EMPATE");
        } else {
            System.out.printf("\nJogador %c venceu!\n", jogador);
        }

        scanner.close();
        // não é necessário liberar a memória em Java, o coletor de lixo faz isso automaticamente.
    }
}
