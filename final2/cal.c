#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double plus(double a, double b);
double minus(double a, double b);
double multiple(double a, double b);
double divide(double a, double b);

int is_numeric(char *str) {
    int i = 0;
    if (str[0] == '-') i = 1;
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i]) && str[i] != '.') return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <operator> <number1> <number2>\n", argv[0]);
        return 1;
    }

    char *op = argv[1];
    if (strcmp(op, "+") != 0 && strcmp(op, "-") != 0 && strcmp(op, "x") != 0 && strcmp(op, "/") != 0) {
        printf("Error: First parameter must be an arithmetic operator (+, -, x, /).\n");
        return 1;
    }

    if (!is_numeric(argv[2]) || !is_numeric(argv[3])) {
        printf("Error: Second and third parameters must be numbers.\n");
        return 1;
    }

    double a = atof(argv[2]);
    double b = atof(argv[3]);
    double res = 0;

    if (strcmp(op, "+") == 0) res = plus(a, b);
    else if (strcmp(op, "-") == 0) res = minus(a, b);
    else if (strcmp(op, "x") == 0) res = multiple(a, b);
    else if (strcmp(op, "/") == 0) {
        if (b == 0) {
            printf("Error: Cannot divide by zero.\n");
            return 1;
        }
        res = divide(a, b);
    }

    printf("20232753 : %g %s %g = %g\n", a, op, b, res);
    return 0;
}
