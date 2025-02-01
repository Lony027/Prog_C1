#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

/* Not optimized */
void bubble_sort(int *tab, int tab_size) {
    int i, j;
    for (i = tab_size - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (tab[j + 1] < tab[j]) {
                swap(&tab[j], &tab[j + 1]);
            }
        }
    }
}

void print_array(int *tab, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    putchar('\n');
}

void fill_tab_randomly(int *tab, int size, int number_range_min,
                       int number_range_max) {
    int i;
    for (i = 0; i < size; i++) {
        tab[i] = rand() % (number_range_max - number_range_min + 1) +
                 number_range_min;
    }
}

int main(int argc, char *argv[]) {
    int size = 20;
    int tab[size];
    int i;
    for (i = 0; i < 5; i++) {
        fill_tab_randomly(tab, size, 0, 100);
        printf("Random tab : ");
        print_array(tab, 10);
        bubble_sort(tab, 10);
        printf("Sorted tab : ");
        print_array(tab, 10);
        putchar('\n');
    }
    return 0;
}