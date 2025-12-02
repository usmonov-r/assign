#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include "cal.h"

int is_number(char *str) {
    int i = 0;
    if (str[0] == '-') i = 1;
    int dot_count = 0;
    
    for (; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1) return 0;
        }
        else if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <operator> <number1> <number2>\n", argv[0]);
        printf("Operators: +, -, x, /\n");
        return 1;
    }

    char *operator = argv[1];
    char *num1_str = argv[2];
    char *num2_str = argv[3];
    double a, b, result;

    if (strcmp(operator, "+") != 0 && strcmp(operator, "-") != 0 &&
        strcmp(operator, "x") != 0 && strcmp(operator, "/") != 0) {
        printf("Error: First parameter must be an arithmetic operator (+, -, x, /).\n");
        return 1;
    }

    if (!is_number(num1_str) || !is_number(num2_str)) {
        printf("Error: Second and third parameters must be numbers.\n");
        return 1;
    }

    a = atof(num1_str);
    b = atof(num2_str);

    if (strcmp(operator, "+") == 0) {
        result = plus(a, b);
    } else if (strcmp(operator, "-") == 0) {
        result = minus(a, b);
    } else if (strcmp(operator, "x") == 0) {
        result = multiple(a, b);
    } else if (strcmp(operator, "/") == 0) {
        // 3. Check for divide by zero
        if (b == 0) {
            printf("Error: Cannot divide by zero.\n");
            return 1;
        }
        result = divide(a, b);
    }

    printf("20232753 : %g %s %g = %g\n", a, operator, b, result);

    return 0;
}
