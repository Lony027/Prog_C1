#include <stdio.h>

int recherche_dichotomique(int tab[], int rangeMin, int rangeMax, int searchedValue) {
  int index = (rangeMin + rangeMax) / 2;

  if (rangeMax - rangeMin == 1) {
    printf("value not in table\n");
    return -1;
  }

  if (searchedValue == tab[index]) {
    return index;
  } else if (searchedValue < tab[index]) {
    return recherche_dichotomique(tab, rangeMin, index, searchedValue);
  } else {
    return recherche_dichotomique(tab, index, rangeMax, searchedValue);
  }
}

int main(int argc, char *argv[]) {
  int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11};
  int index = recherche_dichotomique(tab, 0, 11, 3);
  printf("i : %d, tab[i] : %d", index, tab[index]);
  return 0;
}