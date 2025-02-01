#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int base26_to_decimal(char *s) {
    int result = 0;
    int i = 0;
    while (s[i] != '\0') {
        result = result * 26 + (s[i] - 'a');
        i++;
    }
    return result;
}

void decimal_to_base26(int number, char *result, int string_size) {
    char buffer[string_size];

    if (number == 0) {
        result[0] = 'a';
        result[1] = '\0';
        return;
    }

    int i = 0;
    while (number > 0) {
        buffer[i] = (number % 26) + 'a';
        number /= 26;
        i++;
    }

    int j;
    for (j = 0; j < i; j++) {
        result[j] = buffer[i - j - 1];
    }
    result[i] = '\0';
}

int is_lowercase(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] < 'a' || s[i] > 'z') {
            return 0;
        }
        i++;
    }
    return 1;
}

int is_number(char *s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] < '0' || s[i] > '9') {
            return 0;
        }
        i++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 2) {
        printf("this function needs one argument\n");
        return -1;
    }

    char *typed_s = argv[1];
    if (is_lowercase(typed_s)) {
        printf("%d\n", base26_to_decimal(typed_s));
    } else if (is_number(typed_s)) {
        int string_size = strlen(typed_s);
        char string[string_size];
        decimal_to_base26(atoi(typed_s), string, string_size);
        printf("%s\n", string);
    } else {
        printf("only lowercase or only numeric values\n");
        return -1;
    }
    return 0;
}