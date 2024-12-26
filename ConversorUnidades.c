#include <stdio.h>

// Declara��o das fun��es de convers�o

float converterVolume(float valor, char unidadeOrigem, char unidadeDestino);     // Mateus Soares
float converter_compri(float, char , char );  //Matheus Capuchinho

// Fun��o para exibir o menu principal
void exibirMenu();

int main() {
    int escolha;
    float valor, resultado;
    char unidadeOrigem, unidadeDestino;

    while (1) {
        exibirMenu();
        printf("Escolha uma opcao (ou 0 para sair): ");
        scanf("%d", &escolha);

        if (escolha == 0) {
            printf("Programa encerrado.\n");
            break;
        }

        printf("Digite o valor a ser convertido: ");
        scanf("%f", &valor);
        printf("Digite a unidade de origem: ");
        scanf(" %c", &unidadeOrigem);
        printf("Digite a unidade de destino: ");
        scanf(" %c", &unidadeDestino);

        switch (escolha) {
            case 1:
                resultado = converterVolume(valor, unidadeOrigem, unidadeDestino); // Exemplo
                break;
            case 3:
                resultado = converter_compri(valor, unidadeOrigem, unidadeDestino);
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                continue;
        }

        printf("Resultado da conversao: %.2f\n", resultado);
    }

    return 0;
}

void exibirMenu() {
    printf("\n--- Conversor de Unidades ---\n");
    printf("1. Volume (L, mL, m3)\n");
    printf("3. Comprimento (m, c(cm), l(mm))\n");
}

// Fun��o implementada: Volume
float converterVolume(float valor, char unidadeOrigem, char unidadeDestino) {
    if (unidadeOrigem == 'L' && unidadeDestino == 'm') { // Litros para mililitros
        return valor * 1000;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'L') { // Mililitros para litros
        return valor / 1000;
    } else if (unidadeOrigem == 'L' && unidadeDestino == 'c') { // Litros para metros c�bicos
        return valor / 1000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'L') { // Metros c�bicos para litros
        return valor * 1000;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'c') { // Mililitros para metros c�bicos
        return valor / 1000000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'm') { // Metros c�bicos para mililitros
        return valor * 1000000;
    } else {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a convers�o n�o for v�lida
    }
}

//Fun�ao para converter Comprimento
float converter_compri(float valor, char unidadeOrigem, char unidadeDestino) {
    if (unidadeOrigem == 'm' && unidadeDestino == 'c') { // Metro para Cent�metro
        return valor * 100;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'l') { // Metro para Mil�metro
        return valor * 1000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'l') { // Cent�metro para Mil�metro
        return valor * 10;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'm') { // Cent�metro para Metro
        return valor / 100;
    } else if (unidadeOrigem == 'l' && unidadeDestino == 'm') { // Mil�metro para Metro
        return valor / 1000;
    } else if (unidadeOrigem == 'l' && unidadeDestino == 'c') { // Mil�metro para Cent�metro
        return valor / 10;
    } else {
        printf("Convers�o inv�lida. Unidades n�o reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a convers�o n�o for v�lida
    }
}

// Fun��es a serem implementadas:
