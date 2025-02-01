#include <stdio.h>

int dichotomic_search(int tab[], int rangeMin, int rangeMax,
                      int searchedValue) {
    int index = (rangeMin + rangeMax) / 2;

    if (rangeMax - rangeMin == 1) {
        printf("value not in table\n");
        return -1;
    }

    if (searchedValue == tab[index]) {
        return index;
    } else if (searchedValue < tab[index]) {
        return dichotomic_search(tab, rangeMin, index, searchedValue);
    } else {
        return dichotomic_search(tab, index, rangeMax, searchedValue);
    }
}

void print_array(int *tab, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", tab[i]);
    }
    putchar('\n');
}

int main(int argc, char *argv[]) {
    int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
    int searched_value = 3;
    int tab_size = 10;

    print_array(tab, tab_size);
    int found_index = dichotomic_search(tab, 0, tab_size, searched_value);
    printf("Searched value : %d\n", searched_value);
    printf("Found at index : %d\n", found_index);
    return 0;
}