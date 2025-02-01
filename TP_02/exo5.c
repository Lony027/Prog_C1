#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *f = fopen("exo5.c", "r");

    char c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    return 0;
}