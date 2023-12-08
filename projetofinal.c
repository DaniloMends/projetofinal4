#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Veiculo {
    char proprietario[50];
    char combustivel[10];
    char modelo[50];
    char cor[20];
    char chassi[20];
    int ano;
    char placa[8];
    struct Veiculo *prox;
} Veiculo;

Veiculo *inicializaLista(){
    return NULL;
}

Veiculo *adicionaVeiculo(Veiculo *lista){
    Veiculo *novoVeiculo = (Veiculo *)malloc(sizeof(Veiculo));

    printf("Proprietário: ");
    scanf(" %[^\n]s", novoVeiculo->proprietario);
    printf("Combustível (álcool, diesel ou gasolina): ");
    scanf(" %[^\n]s", novoVeiculo->combustivel);
    printf("Modelo: ");
    scanf(" %[^\n]s", novoVeiculo->modelo);
    printf("Cor: ");
    scanf(" %[^\n]s", novoVeiculo->cor);
    printf("Nº chassi: ");
    scanf(" %[^\n]s", novoVeiculo->chassi);
    printf("Ano: ");
    scanf("%d", &novoVeiculo->ano);
    printf("Placa (XXX9999): ");
    scanf(" %[^\n]s", novoVeiculo->placa);

    novoVeiculo->prox = lista;
    return novoVeiculo;
}

void listarProprietariosDiesel2010OuPosterior(Veiculo *lista){
    printf("\nProprietários de carros do ano 2010 ou posterior e movidos a diesel:\n");
    while (lista != NULL) {
        if (lista->ano >= 2010 && strcmp(lista->combustivel, "diesel") == 0) {
            printf("%s\n", lista->proprietario);
        }
        lista = lista->prox;
    }
}

void listarPlacasComJ(Veiculo *lista){
    printf("\nPlacas que começam com J e terminam com 0, 2, 4 ou 7 e seus proprietários:\n");
    while (lista != NULL){
        if (lista->placa[0] == 'J' && (lista->placa[6] == '0' || lista->placa[6] == '2' || lista->placa[6] == '4' || lista->placa[6] == '7')) {
            printf("Placa: %s, Proprietário: %s\n", lista->placa, lista->proprietario);
        }
        lista = lista->prox;
    }
}

void listarModeloCorPlacasVogalSomaPar(Veiculo *lista){
    printf("\nModelo e cor dos veículos com placas cuja segunda letra é uma vogal e a soma dos valores numéricos é par:\n");
    while (lista != NULL) {
        if ((lista->placa[1] == 'A' || lista->placa[1] == 'E' || lista->placa[1] == 'I' || lista->placa[1] == 'O' || lista->placa[1] == 'U') &&
            ((lista->placa[2] - '0') + (lista->placa[3] - '0') + (lista->placa[4] - '0') + (lista->placa[5] - '0') + (lista->placa[6] - '0')) % 2 == 0) {
            printf("Modelo: %s, Cor: %s\n", lista->modelo, lista->cor);
        }
        lista = lista->prox;
    }
}


void trocarProprietario(Veiculo *lista){
    char chassi[20];
    printf("\nDigite o número do chassi para trocar o proprietário: ");
    scanf(" %[^\n]s", chassi);

    while (lista != NULL) {
        if (strstr(lista->chassi, chassi) != NULL) {
            int temZero = 0;
            for (int i = 0; i < 7; i++) {
                if (lista->placa[i] == '0') {
                    temZero = 1;
                    break;
                }
            }

            if (!temZero) {
                printf("Digite o novo proprietário para o veículo com chassi %s: ", lista->chassi);
                scanf(" %[^\n]s", lista->proprietario);
                printf("Proprietário atualizado com sucesso!\n");
                return;
            } else {
                printf("O veículo com chassi %s possui dígito zero na placa. A troca de proprietário não é permitida.\n", lista->chassi);
                return;
            }
        }
        lista = lista->prox;
    }

    printf("Veículo com chassi %s não encontrado.\n", chassi);
}


int main() {
    Veiculo *listaVeiculos = inicializaLista();
    int escolha;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Veículo\n");
        printf("2. Listar Proprietários Diesel 2010 ou Posterior\n");
        printf("3. Listar Placas com J (0, 2, 4 ou 7)\n");
        printf("4. Listar Modelo e Cor de Placas com Vogal e Soma Par\n");
        printf("5. Trocar Proprietário por Chassi (sem dígito zero na placa)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                listaVeiculos = adicionaVeiculo(listaVeiculos);
                break;
            case 2:
                listarProprietariosDiesel2010OuPosterior(listaVeiculos);
                break;
            case 3:
                listarPlacasComJ(listaVeiculos);
                break;
            case 4:
                listarModeloCorPlacasVogalSomaPar(listaVeiculos);
                break;
            case 5:
                trocarProprietario(listaVeiculos);
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
                
          default:
                printf("Opção inválida.\n");
                }
                }while (escolha != 0);

                while (listaVeiculos != NULL) {
                Veiculo *temp = listaVeiculos;
                listaVeiculos = listaVeiculos->prox;
                free(temp);
                }

              
}
