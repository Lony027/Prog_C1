#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trie_a_bulle(int *tab, int tab_size) {
  int i, j, buffer;
  for (i = tab_size - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if (tab[j + 1] < tab[j]) {
        buffer = tab[j + 1];
        tab[j + 1] = tab[j];
        tab[j] = buffer;
      }
    }
  }
}

void afficher_tableau(int *tab, int tab_size) {
  if (tab_size == 0) {
    return;
  }
  putchar('|');
  int i;
  for (i = 0; i < tab_size; i++) {
    printf(" %d |", tab[i]);
  }
  putchar('\n');
}

int *get_random_tab(int number_range_min, int number_range_max) {
  static int tab[20];
  int i;
  for (i = 0; i < 20; i++) {
    tab[i] =
        rand() % (number_range_max - number_range_min + 1) + number_range_min;
  }
  return tab;
}

int main(int argc, char *argv[]) {
  int *tab;
  int i;
  for (i = 0; i < 5; i++) {
    tab = get_random_tab(0, 100);
    afficher_tableau(tab, 10);
    trie_a_bulle(tab, 10);
    afficher_tableau(tab, 10);
    putchar('\n');
  }
  return 0;
}