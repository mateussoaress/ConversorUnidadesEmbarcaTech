#include <stdio.h>

// Declaraçao das funçoes de conversao

double converterVolume(double valor, char unidadeOrigem, char unidadeDestino);        // Mateus Soares
double converter_compri(double, char, char);                                          // Matheus Capuchinho
double converterMassa(double valor, char unidadeOrigem, char unidadeDestino);         // Gabriel Oliveira
double converterArmazenamento(double valor, char unidadeOrigem, char unidadeDestino); // Gabriel Menezes
double converterTempo(double valor, char unidadeOrigem, char unidadeDestino); // Sanara Marinho

// Funçao para exibir o menu principal
void exibirMenu();

int main()
{
    int escolha;
    double valor, resultado;
    char unidadeOrigem, unidadeDestino;

    while (1)
    {
        exibirMenu();
        printf("Escolha uma opcao (ou 0 para sair): ");
        scanf("%d", &escolha);

        if (escolha == 0)
        {
            printf("Programa encerrado.\n");
            break;
        }

        printf("Digite o valor a ser convertido: ");
        scanf("%lf", &valor);
        printf("Digite a unidade de origem: ");
        scanf(" %c", &unidadeOrigem);
        printf("Digite a unidade de destino: ");
        scanf(" %c", &unidadeDestino);

        switch (escolha)
        {
        case 1:
            resultado = converterVolume(valor, unidadeOrigem, unidadeDestino); 
            break;
        case 2:
            resultado = converterMassa(valor, unidadeOrigem, unidadeDestino);
            break;

        case 3:
            resultado = converter_compri(valor, unidadeOrigem, unidadeDestino);
            break;
        case 4:
            resultado = converterArmazenamento(valor, unidadeOrigem, unidadeDestino);
    
        case 5:
            resultado = converterTempo(valor, unidadeOrigem, unidadeDestino);
            
            if (resultado != -1)
            {
                if (resultado < 1e-10)
                    printf("Resultado da conversao: %.10e\n", resultado);
                else
                    printf("Resultado da conversao: %.10f\n", resultado);
            }
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
            continue;
        }

        printf("Resultado da conversao: %.2f\n", resultado);
    }

    return 0;
}

void exibirMenu()
{
    printf("\n--- Conversor de Unidades ---\n");
    printf("1. Volume (L, mL, m3)\n");
    printf("2. Massa Kg(q), T(t), g(g) \n");
    printf("3. Comprimento (m, c(cm), l(mm))\n");
    printf("4. Armazenamento (b, B, K, M, G, T)\n");
    printf("5. Tempo (s (segundos), m (minutos), h (horas))\n");
}

// Funçao implementada: Volume
double converterVolume(double valor, char unidadeOrigem, char unidadeDestino)
{
    if (unidadeOrigem == 'L' && unidadeDestino == 'm')
    { // Litros para mililitros
        return valor * 1000;
    }
    else if (unidadeOrigem == 'm' && unidadeDestino == 'L')
    { // Mililitros para litros
        return valor / 1000;
    }
    else if (unidadeOrigem == 'L' && unidadeDestino == 'c')
    { // Litros para metros cubicos
        return valor / 1000;
    }
    else if (unidadeOrigem == 'c' && unidadeDestino == 'L')
    { // Metros cubicos para litros
        return valor * 1000;
    }
    else if (unidadeOrigem == 'm' && unidadeDestino == 'c')
    { // Mililitros para metros cubicos
        return valor / 1000000;
    }
    else if (unidadeOrigem == 'c' && unidadeDestino == 'm')
    { // Metros cubicos para mililitros
        return valor * 1000000;
    }
    else
    {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversao nao for valida
    }
}

// Funçao para converter Comprimento
double converter_compri(double valor, char unidadeOrigem, char unidadeDestino)
{
    if (unidadeOrigem == 'm' && unidadeDestino == 'c')
    { // Metro para Centimetro
        return valor * 100;
    }
    else if (unidadeOrigem == 'm' && unidadeDestino == 'l')
    { // Metro para Milimetro
        return valor * 1000;
    }
    else if (unidadeOrigem == 'c' && unidadeDestino == 'l')
    { // Centimetro para Milimetro
        return valor * 10;
    }
    else if (unidadeOrigem == 'c' && unidadeDestino == 'm')
    { // Centimetro para Metro
        return valor / 100;
    }
    else if (unidadeOrigem == 'l' && unidadeDestino == 'm')
    { // Milimetro para Metro
        return valor / 1000;
    }
    else if (unidadeOrigem == 'l' && unidadeDestino == 'c')
    { // Milimetro para Centimetro
        return valor / 10;
    }
    else
    {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversao nao for valida
    }
}

// Função implementada: Massa

double converterMassa(double valor, char unidadeOrigem, char unidadeDestino)
{

    if (unidadeOrigem == 'q' && unidadeDestino == 'g')
    { // Quilos para gramas
        return valor * 1000;
    }
    else if (unidadeOrigem == 'g' && unidadeDestino == 'q')
    { // gramas para quilos
        return valor / 1000;
    }
    else if (unidadeOrigem == 'q' && unidadeDestino == 't')
    { // quilos para toneladas
        return valor / 1000;
    }
    else if (unidadeOrigem == 'g' && unidadeDestino == 't')
    { // gramas para toneladas
        return valor / 100000;
    }
    else if (unidadeOrigem == 't' && unidadeDestino == 'g')
    { // toneladas para gramas
        return valor * 1000000;
    }
    else if (unidadeOrigem == 't' && unidadeDestino == 'q')
    { // toneladas para quilos
        return valor * 1000;
    }
    else
    {
        printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversão não for válida
    }
}

// Função implementada: Armazenamento
double converterArmazenamento(double valor, char unidadeOrigem, char unidadeDestino)
{
    // Conversão direta sem passar por bits para evitar precisão excessiva ou overflow
    const double factor = 1024.0; // Fator de conversão entre unidades

    switch (unidadeOrigem)
    {
    case 'b': case 'B': // Bits e Bytes são tratados como entrada direta
        break;

    case 'K':
        valor *= factor;
        break;
    case 'M':
        valor *= factor * factor;
        break;
    case 'G':
        valor *= factor * factor * factor;
        break;
    case 'T':
        valor *= factor * factor * factor * factor;
        break;
    default:
        printf("Unidade de entrada invalida.\n");
        return -1;
    }

    // Conversão para a unidade de destino
    switch (unidadeDestino)
    {
    case 'b':
        return valor * 8; // Byte para bit
    case 'B':
        return valor;
    case 'K':
        return valor / factor;
    case 'M':
        return valor / (factor * factor);
    case 'G':
        return valor / (factor * factor * factor);
    case 'T':
        return valor / (factor * factor * factor * factor);
    default:
        printf("Unidade de destino invalida.\n");
        return -1;
    }
}

// Função implementada: Tempo

double converterTempo(double valor, char unidadeOrigem, char unidadeDestino)
{
    if (unidadeOrigem == 's' && unidadeDestino == 'm')
    { // Segundos para Minutos
        return valor / 60 ;
    }
    else if (unidadeOrigem == 's' && unidadeDestino == 'h')
    { // Segundos para Horas
       return valor / 3600;
    }
    else if (unidadeOrigem == 'm' && unidadeDestino == 's')
    { // Minutos para Segundos
        return valor * 60;
    }
    else if (unidadeOrigem == 'm' && unidadeDestino == 'h')
    { // Minutos para Horas
        return valor / 60;
    }
    else if (unidadeOrigem == 'h' && unidadeDestino == 's')
    { // Horas para Segundos
        return valor * 3600;
    }
    else if (unidadeOrigem == 'h' && unidadeDestino == 'm')
    { // Horas para Minutos
       return valor * 60;
    }
    else
    {
         printf("Conversao invalida. Unidades nao reconhecidas.\n");
        return valor; // Retorna o mesmo valor se a conversao nao for valida
    }
    


}
