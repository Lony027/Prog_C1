#include <stdio.h>

void wc(int *char_count, int *word_count, int *line_count) {
    int is_word = 0;
    char c, last;
    while ((c = getchar()) != EOF) {
        last = c;
        (*char_count)++;
        if (c == '\n') {
            (*line_count)++;
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            if (is_word) {
                (*word_count)++;
            }
            is_word = 0;
        } else {
            is_word = 1;
        }
    }
    if (last != '\n' && last != '\t' && last != ' ') {
        (*word_count)++;
    }
    return;
}

int main(int argc, char *argv[]) {
    /* printf("CTRL + D"); */
    int char_count = 0, word_count = 0, line_count = 1;
    wc(&char_count, &word_count, &line_count);
    printf("\nChar : %d, Word : %d, Lines : %d\n", char_count, word_count,
           line_count);
    return 0;
}