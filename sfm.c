// Aluno:Silvio Fittipaldi de Morais
// E-mail: sfm@cesar.school
// Primeiro commit 00:15 30/08/2024
// Segundo commit 13:45 30/08/2024
// Terceiro commit 20:35 30/08/2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BinarioFuncao(int num) {
    if (num < 0) {
        printf("Números negativos não são suportados para esta operação.\n");
        return;
    }
    int binario[32];
    int i = 0;

    printf("\nConvertendo %d para base 2:\n", num);
    while (num > 0) {
        binario[i] = num % 2;
        printf("Passo %d: %d %% 2 = %d (resto), %d / 2 = %d (quociente)\n", i + 1, num, binario[i], num, num / 2);
        num = num / 2;
        i++;
    }

    printf("Resultado em binário: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binario[j]);
    }
    printf("\n");
}

void OctalFuncao(int num) {
    if (num < 0) {
        printf("Números negativos não são suportados para esta operação.\n");
        return;
    }
    int octal[32];
    int i = 0;

    printf("\nConvertendo %d para base 8:\n", num);
    while (num > 0) {
        octal[i] = num % 8;
        printf("Passo %d: %d %% 8 = %d (resto), %d / 8 = %d (quociente)\n", i + 1, num, octal[i], num, num / 8);
        num = num / 8;
        i++;
    }

    printf("Resultado em octal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", octal[j]);
    }
    printf("\n");
}

void HexadecimalFuncao(int num) {
    if (num < 0) {
        printf("Números negativos não são suportados para esta operação.\n");
        return;
    }
    char hexadecimal[32];
    int i = 0;

    printf("\nConvertendo %d para base 16:\n", num);
    while (num > 0) {
        int remainder = num % 16;
        if (remainder < 10)
            hexadecimal[i] = 48 + remainder;
        else
            hexadecimal[i] = 55 + remainder;

        printf("Passo %d: %d %% 16 = %d (resto), %d / 16 = %d (quociente)\n", i + 1, num, remainder, num, num / 16);
        num = num / 16;
        i++;
    }

    printf("Resultado em hexadecimal: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

void BCDfuncao(int num) {
    if (num < 0) {
        printf("Números negativos não são suportados para esta operação.\n");
        return;
    }
    printf("\nConvertendo %d para BCD:\n", num);
    int digit, i = 0;

    printf("Número em decimal: %d\n", num);
    printf("Representação em BCD: ");
    while (num > 0) {
        digit = num % 10;
        for (int j = 3; j >= 0; j--) {
            printf("%d", (digit >> j) & 1);
        }
        printf(" ");
        num = num / 10;
        i++;
    }
    printf("\n");
}

void complemento2Funcao(int num) {
    if (num < -32768 || num > 32767) {
        printf("Erro: O número %d está fora do intervalo representável em 16 bits com sinal.\n", num);
        return;
    }

    int complemento2;
    if (num >= 0) {
        complemento2 = num;
    } else {
        complemento2 = 65536 + num;
    }

    printf("\nConvertendo %d para complemento a 2 (16 bits):\n", num);
    printf("Resultado em complemento a 2 (16 bits): ");
    for (int i = 15; i >= 0; i--) {
        printf("%d", (complemento2 >> i) & 1);
    }
    printf("\n");
}

void FloatFuncao(float num) {
    int bits = *(int*)&num;

    int sinal = (bits >> 31) & 1;
    int expoente = (bits >> 23) & 0xFF;
    int fracao = bits & 0x7FFFFF;

    printf("\nConvertendo %f para formato float:\n", num);
    printf("Sinal: %d\n", sinal);
    printf("Expoente: %d (sem viés)\n", expoente);
    printf("Expoente com viés: %d\n", expoente - 127);
    printf("Fração: 0x%X\n", fracao);
}

void DoubleFuncao(double num) {
    long long bits = *(long long*)&num;

    int sinal = (bits >> 63) & 1;
    int expoente = (bits >> 52) & 0x7FF;
    long long fracao = bits & 0xFFFFFFFFFFFFF;

    printf("\nConvertendo %f para formato double:\n", num);
    printf("Sinal: %d\n", sinal);
    printf("Expoente: %d (sem viés)\n", expoente);
    printf("Expoente com viés: %d\n", expoente - 1023);
    printf("Fração: 0x%llX\n", fracao);
}

int main() {
    char input[100];
    int num;
    int opcao;

    while (1) {
        printf("Digite um número em base 10 (ou 'parar' para encerrar): ");
        scanf("%s", input);

        if (strcmp(input, "parar") == 0) {
            printf("Encerrando o programa.\n");
            break;
        }

        num = atoi(input);

        printf("Escolha uma conversão:\n");
        printf("1 - Converter para base 2\n");
        printf("2 - Converter para base 8\n");
        printf("3 - Converter para base 16\n");
        printf("4 - Converter para BCD\n");
        printf("5 - Converter para Complemento a 2 (16 bits)\n");
        printf("6 - Converter para formato float\n");
        printf("7 - Converter para formato double\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                BinarioFuncao(num);
                break;
            case 2:
                OctalFuncao(num);
                break;
            case 3:
                HexadecimalFuncao(num);
                break;
            case 4:
                BCDfuncao(num);
                break;
            case 5:
                complemento2Funcao(num);
                break;
            case 6: {
                float numFloat = strtof(input, NULL);
                FloatFuncao(numFloat);
                break;
            }
            case 7: {
                double numDouble = strtod(input, NULL);
                DoubleFuncao(numDouble);
                break;
            }
            default:
                printf("Opção inválida!\n");
        }

        printf("\n");
    }

    return 0;
}
