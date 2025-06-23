#include <stdio.h>
#include <stdlib.h>

void usage(char *programname) {
    printf("\nHow to use: %s <liczba1> <operator> <liczba2>\n", programname);
    printf("Options: +, -, *, /\n");
    exit(1);
}

int main(int argc, char *argv[]) {

    int number1 = 0;
    int number2 = 0;
    int result = 0;

    if (argc != 4) {
        usage(argv[0]);
    }

    number1 = atoi(argv[1]);
    number2 = atoi(argv[3]);
    char op = argv[2][0];

    switch (op) {

        case '+':
            result = number1 + number2;
            printf("%d + %d = %d\n", number1, number2, result);
            break;

        case '-':
            result = number1 - number2;
            printf("%d - %d = %d\n", number1, number2, result);
            break;

        case '*':
            result = number1 * number2;
            printf("%d * %d = %d\n", number1, number2, result);
            break;

        case '/':
            if (number2 == 0) {
                printf("Błąd: Dzielenie przez zero!\n");
                return 1;
            }
            result = number1 / number2;
            printf("%d / %d = %d\n", number1, number2, result);
            break;

        default:
            printf("Nieznany operator: %s\n", argv[2]);
            usage(argv[0]);
    }

    return 0;
}
