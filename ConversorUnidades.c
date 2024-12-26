#include <stdio.h>

// Declaraçao das funçoes de conversao

float converterVolume(float valor, char unidadeOrigem, char unidadeDestino);     // Mateus Soares
float converter_compri(float, char , char );  //Matheus Capuchinho
float converterMassa(float valor, char unidadeOrigem, char unidadeDestino);    // Gabriel Oliveira

// Funçao para exibir o menu principal
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
                resultado = converterMassa(valor, unidadeOrigem, unidadeDestino);
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
    printf("2. Massa Kg(q), T(t), g(g) ");
    printf("3. Comprimento (m, c(cm), l(mm))\n");
}

// Funçao implementada: Volume
float converterVolume(float valor, char unidadeOrigem, char unidadeDestino) {
    if (unidadeOrigem == 'L' && unidadeDestino == 'm') { // Litros para mililitros
        return valor * 1000;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'L') { // Mililitros para litros
        return valor / 1000;
    } else if (unidadeOrigem == 'L' && unidadeDestino == 'c') { // Litros para metros cubicos
        return valor / 1000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'L') { // Metros cubicos para litros
        return valor * 1000;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'c') { // Mililitros para metros cubicos
        return valor / 1000000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'm') { // Metros cubicos para mililitros
        return valor * 1000000;
    } else {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversao nao for valida
    }
}

//Funçao para converter Comprimento
float converter_compri(float valor, char unidadeOrigem, char unidadeDestino) {
    if (unidadeOrigem == 'm' && unidadeDestino == 'c') { // Metro para Centimetro
        return valor * 100;
    } else if (unidadeOrigem == 'm' && unidadeDestino == 'l') { // Metro para Milimetro
        return valor * 1000;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'l') { // Centimetro para Milimetro
        return valor * 10;
    } else if (unidadeOrigem == 'c' && unidadeDestino == 'm') { // Centimetro para Metro
        return valor / 100;
    } else if (unidadeOrigem == 'l' && unidadeDestino == 'm') { // Milimetro para Metro
        return valor / 1000;
    } else if (unidadeOrigem == 'l' && unidadeDestino == 'c') { // Milimetro para Centimetro
        return valor / 10;
    } else {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversao nao for valida
    }
}

// Função implementada: Massa

float converterMassa(float valor, char unidadeOrigem, char unidadeDestino){

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
    else if (unidadeOrigem == 't' && unidadeDestino == 'g'){ // toneladas para gramas
       return valor*1000000;
    }
    else if (unidadeOrigem == 't' && unidadeDestino == 'q'){ // toneladas para quilos
        return valor*1000;
    }
     else {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversão não for válida
    }
}

// Funçoes a serem implementadas:
