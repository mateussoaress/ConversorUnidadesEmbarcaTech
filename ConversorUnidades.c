#include <stdio.h>

// Declaração das funções de conversão

float converterVolume(float valor, char unidadeOrigem, char unidadeDestino);     // Mateus Soares
float converterComprimento(float valor, char unidadeOrigem, char unidadeDestino);    // Gabriel Oliveira

// Função para exibir o menu principal
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
            case 2:
                resultado = converterComprimento(valor, unidadeOrigem, unidadeDestino);
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
    printf("2. Comprimento (M, cm, mm)\n ");

}

// Função implementada: Volume
float converterVolume(float valor, char unidadeOrigem, char unidadeDestino) {
    if (unidadeOrigem == 'L' && unidadeDestino == 'm') { // Litros para mililitros
        return valor * 1000;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'L') { // Mililitros para litros
        return valor / 1000;
    } else if (unidadeOrigem == 'L' && unidadeDestino == 'c') { // Litros para metros cúbicos
        return valor / 1000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'L') { // Metros cúbicos para litros
        return valor * 1000;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'c') { // Mililitros para metros cúbicos
        return valor / 1000000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'm') { // Metros cúbicos para mililitros
        return valor * 1000000;
    } else {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversão não for válida
    }
}

// Função implementada: Comprimento

float converterComprimento(float valor, char unidadeOrigem, char unidadeDestino){

    if (unidadeOrigem == 'M' && unidadeDestino == 'c'){ // Metros para centimetros
       return valor * 100;
    }
    else if (unidadeOrigem == 'c' && unidadeDestino == 'M'){ // centimetros para metros
       return valor/100;
    }
    else if (unidadeOrigem == 'M' && unidadeDestino == 'm'){ // Metros para milimetros
       return valor*1000;
    }
    else if (unidadeOrigem == 'c' && unidadeDestino == 'm'){ // centimetros para milimetros
       return valor*10;
    }
    else if (unidadeOrigem == 'm' && unidadeDestino == 'M'){ // milimetros para metros
       return valor/1000;
    }
    else if (unidadeOrigem == 'm' && unidadeDestino == 'c'){
        return valor/10;
    }
     else {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversão não for válida
    }
}

// Funções a serem implementadas:
