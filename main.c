#include <stdio.h>
#include <string.h>

#define MAX_JOGADORES 20

typedef struct {
    int id;
    char nome[50];
    int pontos;
} Jogador;

void cadastrarJogador(Jogador jogadores[], int *quantidade) {
    if (*quantidade >= MAX_JOGADORES) {
        printf("\n O limite de %d jogadores foi atingido! Banco de reservas cheio.\n", MAX_JOGADORES);
        return;
    }

    Jogador novo;
    novo.id = *quantidade + 1;

    printf("\n=== CADASTRO DE JOGADOR - COPA DO MUNDO ===\n");
    printf("ID atribuído: %d\n", novo.id);
    printf("Nome do jogador: ");
    scanf(" %[^\n]", novo.nome);
    printf("Gols marcados (pontuação): ");
    scanf("%d", &novo.pontos);

    jogadores[*quantidade] = novo;
    (*quantidade)++;

    printf("Jogador '%s' escalado para a Copa do Mundo!\n", novo.nome);
}

void listarJogadores(Jogador jogadores[], int quantidade) {
    printf("\n=== ELENCO DA COPA DO MUNDO ===\n");
    if (quantidade == 0) {
        printf("Nenhum jogador cadastrado ainda.\n");
        return;
    }
    printf("%-5s %-30s %-10s\n", "ID", "Nome", "Gols");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%-5d %-30s %-10d\n",
               jogadores[i].id,
               jogadores[i].nome,
               jogadores[i].pontos);
    }
    printf("--------------------------------------------------\n");
    printf("Total de jogadores: %d\n", quantidade);
}

int buscarPorId(Jogador jogadores[], int quantidade, int id) {
    for (int i = 0; i < quantidade; i++) {
        if (jogadores[i].id == id) {
            return i;
        }
    }
    return -1;
}

void ordenarPorPontuacao(Jogador jogadores[], int quantidade) {
    Jogador temp;
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = i + 1; j < quantidade; j++) {
            if (jogadores[j].pontos > jogadores[i].pontos) {
                temp = jogadores[i];
                jogadores[i] = jogadores[j];
                jogadores[j] = temp;
            }
        }
    }
    printf("\nRanking ordenado por gols (maior → menor)!\n");
}

void exibirCampeao(Jogador jogadores[], int quantidade) {
    if (quantidade == 0) {
        printf("\nNenhum jogador cadastrado para eleger o campeão.\n");
        return;
    }

    int indiceCampeao = 0;
    for (int i = 1; i < quantidade; i++) {
        if (jogadores[i].pontos > jogadores[indiceCampeao].pontos) {
            indiceCampeao = i;
        }
    }

    printf("\n====== ARTILHEIRO DA COPA DO MUNDO ======\n");
    printf("   ID    : %d\n", jogadores[indiceCampeao].id);
    printf("   Nome  : %s\n", jogadores[indiceCampeao].nome);
    printf("   Gols  : %d\n", jogadores[indiceCampeao].pontos);
    printf("===========================================\n");
}

int main() {
    Jogador jogadores[MAX_JOGADORES];
    int quantidade = 0;
    int opcao, id, indice;

    printf("\n Bem-vindo ao Sistema de Ranking da Copa do Mundo!\n");

    do {
        printf("\n========= MENU COPA DO MUNDO =========\n");
        printf("1 - Cadastrar jogador\n");
        printf("2 - Listar jogadores\n");
        printf("3 - Buscar jogador por ID\n");
        printf("4 - Ordenar ranking por gols\n");
        printf("5 - Exibir artilheiro (campeão)\n");
        printf("0 - Sair\n");
        printf("======================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarJogador(jogadores, &quantidade);
                break;

            case 2:
                listarJogadores(jogadores, quantidade);
                break;

            case 3:
                printf("\nDigite o ID do jogador: ");
                scanf("%d", &id);
                indice = buscarPorId(jogadores, quantidade, id);
                if (indice != -1) {
                    printf("\n Jogador encontrado:\n");
                    printf("   ID    : %d\n", jogadores[indice].id);
                    printf("   Nome  : %s\n", jogadores[indice].nome);
                    printf("   Gols  : %d\n", jogadores[indice].pontos);
                } else {
                    printf("Jogador com ID %d não encontrado.\n", id);
                }
                break;

            case 4:
                if (quantidade == 0) {
                    printf("\nNenhum jogador cadastrado para ordenar.\n");
                } else {
                    ordenarPorPontuacao(jogadores, quantidade);
                    listarJogadores(jogadores, quantidade);
                }
                break;

            case 5:
                exibirCampeao(jogadores, quantidade);
                break;

            case 0:
                printf("\n Encerrando o sistema... Até a próxima Copa!\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
