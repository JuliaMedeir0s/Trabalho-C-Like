# Criar o tabuleiro 3x3
def criar_tabuleiro(tamanho):
    tabuleiro = [[' ' for _ in range(tamanho)] for _ in range(tamanho)]
    return tabuleiro

# Liberar a memória alocada (não é necessário em Python, o gerenciamento de memória é automático)
def liberar_memoria(tabuleiro):
    pass  # Não é necessário no Python, a liberação de memória é automática

# Imprimir o tabuleiro
def imprimir_tabuleiro(tabuleiro):
    for row in tabuleiro:
        print(' ' + ' | '.join(row))
        print('---+---+---')

# Verificar resultado final do jogo
def verificar_resultado(tabuleiro):
    # Verificar possibilidades de vitória
    for i in range(3):
        # Vitória em linha
        if tabuleiro[i][0] == tabuleiro[i][1] == tabuleiro[i][2] != ' ':
            return True
        # Vitória em coluna
        if tabuleiro[0][i] == tabuleiro[1][i] == tabuleiro[2][i] != ' ':
            return True
    # Na diagonal
    if tabuleiro[0][0] == tabuleiro[1][1] == tabuleiro[2][2] != ' ':
        return True
    if tabuleiro[0][2] == tabuleiro[1][1] == tabuleiro[2][0] != ' ':
        return True

    # Verificar se o jogo acabou ou se foi um empate
    for row in tabuleiro:
        for cell in row:
            if cell == ' ':
                return False  # Jogo ainda não acabou
    return True  # Acabou o jogo e foi empate

# Função principal (main)
def main():
    tamanho = 3  # O tabuleiro é 3x3
    tabuleiro = criar_tabuleiro(tamanho)
    jogadas = 0
    jogador = 'X'
    fim_do_jogo = False

    # Registrar as jogadas
    while not fim_do_jogo:
        imprimir_tabuleiro(tabuleiro)
        while True:
            try:
                linha, coluna = map(int, input(f"\nJogador {jogador}, informe a linha e a coluna que deseja jogar (1-3): ").split())
                if linha < 1 or linha > 3 or coluna < 1 or coluna > 3 or tabuleiro[linha - 1][coluna - 1] != ' ':
                    print("Jogada inválida. Tente novamente!")
                    continue
                break
            except ValueError:
                print("Entrada inválida. Informe dois números separados por espaço!")

        tabuleiro[linha - 1][coluna - 1] = jogador
        jogadas += 1

        # Verifica se o jogo acabou. Se tiver acabado, retorna o resultado
        fim_do_jogo = verificar_resultado(tabuleiro)

        # Mudar o jogador da vez
        jogador = 'O' if jogador == 'X' else 'X'

    # Jogo finalizou
    imprimir_tabuleiro(tabuleiro)
    print("\nO jogo acabou!")
    # Informar quem venceu o jogo ou se foi empate
    if fim_do_jogo and jogadas < 9:
        jogador = 'O' if jogador == 'X' else 'X'  # Alternar jogador, pois o último a jogar foi invertido
        print(f"Jogador {jogador} venceu!")
    else:
        print("FOI EMPATE")

if __name__ == "__main__":
    main()
