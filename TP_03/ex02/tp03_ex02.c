#include <stdio.h>

/* int[] word_count(char *string) {
  int i = 0;
  int cmptWord = 0;
  int cmptNewLine = 1;
  while (string[i] != '\0') {
    i++;
    if ((string[i] == ' ' || string[i] == '\n' || string[i] == '\t' || string[i]
== '\0') && (i > 0 && string[i - 1] != ' ' && string[i - 1] != '\n' && string[i
- 1] != '\t')) { cmptWord++;
    }
    if (string[i] == '\n') {
        cmptNewLine++;
    }
  }
  int tab[3] = {i, cmptWord, cmptNewLine};
} */

/* ch = getchar()) != EOF */
void word_count() {
  char ch;
  while ((ch = getchar()) != EOF) {
  }
  return;
}

int main(int argc, char *argv[]) {
  word_count();
  /* int tab[] = word_count();
  printf("Caractères : %d, Mots : %d, Lignes : %d", tab[0], tab[1], tab[2]);*/
  return 0; 
}

/*  a ls\t\tsal\ni  \n 
https://www.tutorialspoint.com/c_standard_library/c_function_getchar.htm*/