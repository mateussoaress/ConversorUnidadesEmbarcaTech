#include <stdio.h>

// DeclaraÃ§Ã£o das funÃ§Ãµes de conversÃ£o

float converterVolume(float valor, char unidadeOrigem, char unidadeDestino);     // Mateus Soares
float converterPeso(float valor, char unidadeOrigem, char unidadeDestino);    // Gabriel Oliveira

// FunÃ§Ã£o para exibir o menu principal
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
                resultado = converterPeso(valor, unidadeOrigem, unidadeDestino);
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

// FunÃ§Ã£o implementada: Volume
float converterVolume(float valor, char unidadeOrigem, char unidadeDestino) {
    if (unidadeOrigem == 'L' && unidadeDestino == 'm') { // Litros para mililitros
        return valor * 1000;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'L') { // Mililitros para litros
        return valor / 1000;
    } else if (unidadeOrigem == 'L' && unidadeDestino == 'c') { // Litros para metros cÃºbicos
        return valor / 1000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'L') { // Metros cÃºbicos para litros
        return valor * 1000;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'c') { // Mililitros para metros cÃºbicos
        return valor / 1000000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'm') { // Metros cÃºbicos para mililitros
        return valor * 1000000;
    } else {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversÃ£o nÃ£o for vÃ¡lida
    }
}

// FunÃ§Ã£o implementada: Comprimento

float converterPeso(float valor, char unidadeOrigem, char unidadeDestino){

    if (unidadeOrigem == 'q' && unidadeDestino == 'g'){ // Quilos para gramas
       return valor * 1000;
    }
    else if (unidadeOrigem == 'g' && unidadeDestino == 'q'){ // gramas para quilos
       return valor/1000;
    }
    else if (unidadeOrigem == 'q' && unidadeDestino == 't'){ // quilos para toneladas
       return valor/1000;
    }
    else if (unidadeOrigem == 'g' && unidadeDestino == 't'){ // gramas para toneladas
       return valor/100000;
    }
    else if (unidadeOrigem == 'm' && unidadeDestino == 'M'){ // toneladas para gramas
       return valor*1000000;
    }
    else if (unidadeOrigem == 'm' && unidadeDestino == 'c'){ // toneladas para quilos
        return valor*1000;
    }
     else {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversÃ£o nÃ£o for vÃ¡lida
    }
}

// FunÃ§Ãµes a serem implementadas: