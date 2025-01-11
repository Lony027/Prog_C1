#include <stdio.h>
#define N 3

void print_permutations(int *tab, int taille, int max) {
  int i;

  for (i = 0; i < taille - 1; i++) {
    putchar('\t');
  }
  printf("--> ");

  putchar('[');
  for (i = 0; i < max - 1; i++) {
    printf("%d, ", tab[i]);
  }
  printf("%d]\n", tab[max - 1]);
}

/*
• un tableau d’entiers (initialement rempli de 0),
• un entier représentant la valeur courante à mettre dans le tableau,
• un entier représentant la valeur maximale à placer
*/
void permutations(int buffer[], int current, int max) {
  if (current > max) {
    return;
  }
  int i;
  for (i = 0; i < max; i++) {
    if (buffer[i] == 0) {
      /* printf("%d", buffer[i]); */
      buffer[i] = current;

      print_permutations(buffer, current, max);
      permutations(buffer, current + 1, max);
      buffer[i] = 0;
    }
  }
}

/* int *zero_tab() {
    int* buffer[N];
    int i;
    for (i=0; i<N; i++) {
        buffer[i]=0;
    }
    return buffer;

} */

int main(int argc, char *argv[]) {
  /* int *buffer = zero_tab(); */
  int buffer[N];
  int i;
  for (i = 0; i < N; i++) {
    buffer[i] = 0;
  }

  permutations(buffer, 1, N);
  return 0;
}