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
            if (dot_count > 1) return 0; // 소수점이 2개 이상이면 숫자가 아님
        }
        else if (!isdigit(str[i])) {
            return 0; // 숫자가 아닌 문자가 섞여 있음
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("사용법: %s <연산자> <숫자1> <숫자2>\n", argv[0]);
        printf("연산자: +, -, x, /\n");
        return 1;
    }

    char *operator = argv[1];
    char *num1_str = argv[2];
    char *num2_str = argv[3];
    double a, b, result;

    if (strcmp(operator, "+") != 0 && strcmp(operator, "-") != 0 &&
        strcmp(operator, "x") != 0 && strcmp(operator, "/") != 0) {
        printf("Error: 첫 번째 매개변수는 사칙연산자(+, -, x, /)여야 합니다.\n");
        return 1;
    }

    if (!is_number(num1_str) || !is_number(num2_str)) {
        printf("Error: 두 번째와 세 번째 매개변수는 숫자여야 합니다.\n");
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
        if (b == 0) {
            printf("Error: 0으로 나눌 수 없습니다 (Divide by zero).\n");
            return 1;
        }
        result = divide(a, b);
    }

    printf("20236213 : %g %s %g = %g\n", a, operator, b, result);

    return 0;
}
