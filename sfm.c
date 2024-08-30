// Aluno:Silvio Fittipaldi de Morais
// Primeira primeiro commit 00:15 30/08/2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BinarioFuncao(int num) {
    int binario[32];
    int i = 0;

    printf("\nConvertendo %d para base 2:\n", num);
    while (num > 0) {
            binario[i] = num % 2;
        printf("Passo %d: %d %% 2 = %d (resto), %d / 2 = %d (quociente)\n", i+1, num, binario[i], num, num / 2);
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
    int octal[32];
    int i = 0;

    printf("\nConvertendo %d para base 8:\n", num);
    while (num > 0) {
        octal[i] = num % 8;
        printf("Passo %d: %d %% 8 = %d (resto), %d / 8 = %d (quociente)\n", i+1, num, octal[i], num, num / 8);
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
    char hexadecimal[32];
    int i = 0;

    printf("\nConvertendo %d para base 16:\n", num);
    while (num > 0) {
        int remainder = num % 16;
        if (remainder < 10)
            hexadecimal[i] = 48 + remainder;
        else
            hexadecimal[i] = 55 + remainder;
        
        printf("Passo %d: %d %% 16 = %d (resto), %d / 16 = %d (quociente)\n", i+1, num, remainder, num, num / 16);
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
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
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
            default:
                printf("Opção inválida!\n");
        }

        printf("\n");
    }

    return 0;
}
