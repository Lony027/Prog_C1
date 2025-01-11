#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Allocate memory for an array which can contain `size`
   integers. The returned C array has memory for an extra last
   integer labelling the end of the array. */
int *allocate_integer_array(int size) {
  int *new_tab;

  new_tab = (int *)malloc((size + 1) * sizeof(int));
  if (new_tab == NULL) {
    fprintf(stderr, "Memory allocation error\n");
    return NULL;
  }
  return new_tab;
}

/* Free an integer array */
void free_integer_array(int *tab) { free(tab); }

/* EXERCICE 1 --------------------------------------------------------- */

/*
An empty array should not be passed as argument,
the last number in the array should be -1
The array should only be > 0
 */
int array_size(int *array) {
  int count = 0;
  while (array[count] != -1) {
    count++;
  }
  return count + 1;
}

void print_array(int *array) {
  int count = 0;
  int array_value;
  do {
    array_value = array[count];
    count++;
    printf("| %d\t", array_value);
  } while (array_value != -1);
  putchar('|');
  putchar('\n');
}

int are_arrays_equal(int *first, int *second) {
  int first_tab_size = array_size(first);
  int second_tab_size = array_size(second);
  if (first_tab_size != second_tab_size) {
    return 0;
  }
  /* if (first_tab_size == 0) { return 1; } */
  int i;
  for (i = 0; i < first_tab_size; i++) {
    if (first[i] != second[i]) {
      return 0;
    }
  }
  return 1;
}

/*
New tab to be freed
*/
int *copy_array(int *array) {
  int tab_size = array_size(array);
  int *new_tab = allocate_integer_array(tab_size);
  int i;
  for (i = 0; i < tab_size; i++) {
    new_tab[i] = array[i];
  }
  return new_tab;
}

/* EXERCICE 2 --------------------------------------------------------- */

int *fill_array(void) {
  int tab_size;
  do {
    printf("Length of the tab (>0) : ");
    scanf("%d", &tab_size);
  } while (tab_size < 1);
  int *array = allocate_integer_array(tab_size);

  int input_array_value, i;
  for (i = 0; i < tab_size; i++) {
    printf("Value at the index, %d : ", i);
    scanf("%d", &input_array_value);
    array[i] = input_array_value;
    /* HANDLE NEGATIVE VALUE */
    putchar('\n');
  }
  array[tab_size] = -1;
  return array;
}

/*
 Retourne un nouveau tableau contenant size entiers positifs compris entre 0 et
 max_entry Array to be freed
*/
int *random_array(int size, int max_entry) {
  srand(time(NULL));
  int *array = allocate_integer_array(size);
  int i, random_value;
  for (i = 0; i < size; i++) {
    random_value = rand() % max_entry;
    array[i] = random_value;
  }
  array[size] = -1;
  return array;
}

int *concat_array(int *first, int *second) {
  int first_array_size = array_size(first) - 1; /* To remove the first -1 */
  int second_array_size = array_size(second);

  int concat_array_size = first_array_size + second_array_size - 1;
  int *new_tab = allocate_integer_array(concat_array_size);

  int i;
  for (i = 0; i < first_array_size; i++) {
    new_tab[i] = first[i];
  }
  int offset_second_array = i;
  for (i = 0; i < second_array_size; i++) {
    new_tab[i + offset_second_array] = second[i];
  }
  return new_tab;
}

/* EXERCICE 3 --------------------------------------------------------- */

/* Array in args already sorted*/
// Manière récursive de le faire
int *merge_sorted_arrays(int *first, int *second) {
    /* verif array pas vide */
    int first_size = array_size(first) - 1;
    int second_size = array_size(second) - 1;

    int merged_array_size = first_size + second_size;
    int *merged_array = allocate_integer_array(merged_array_size);
        
    int index_first = 0;
    int index_second = 0;
    int smallest_value, i;
    for (i = 0; i < merged_array_size; i++) {

        if (index_first < first_size && index_second < second_size) {
            if (first[index_first] < second[index_second]) {
                smallest_value = first[index_first];
                index_first++;
            } else {
                smallest_value = second[index_second];
                index_second++;
            }
        } else if (index_first < first_size && index_second >= second_size) {
            smallest_value = first[index_first];
            index_first++;
        } else if (index_first >= first_size && index_second < second_size) {
            smallest_value = second[index_second];
            index_second++;
        }
        merged_array[i]=smallest_value;
    }

    merged_array[merged_array_size] = -1;
    return merged_array;
}

void split_arrays(int* array, int** first, int** second) {
    int tab_size = array_size(array)-1;

    int moitie = tab_size/2;
    int reste = tab_size%2;

    int first_tab_size = moitie+reste;
    int second_tab_size = moitie;

    *first = allocate_integer_array(first_tab_size);
    *second = allocate_integer_array(second_tab_size);

    int i, offset ;
    for (i = 0; i < first_tab_size; i++) {
        (*first)[i] = *(array+i);
    }
    (*first)[first_tab_size] = -1;

    offset = i;
    for (i=0; i < moitie; i++) {
        (*second)[i] = *(array+i+offset);
    }
    (*second)[second_tab_size] = -1;
}

int* merge_sort(int* array) {
    int tab_size = array_size(array)-1; // enlever le -1?
    if (tab_size <= 1) {
        return array;
    } else {
       /*  return merge_sorted_arrays(merge_sort()); */
    }

}

/* -------------------------------------------------------------------- */

/* An empty main to test the compilation of the allocation and free
   functions. */

void exercice_1() {
  int size_first_exercice = 6;
  int *t = allocate_integer_array(size_first_exercice);
  t[0] = 1;
  t[size_first_exercice - 1] = size_first_exercice - 1;
  t[size_first_exercice] = -1;

  int t_size = array_size(t);
  printf("Taille du tableau T : %d\n", t_size);
  print_array(t);

  int *first = allocate_integer_array(size_first_exercice);
  int *second = allocate_integer_array(size_first_exercice);

  int i;
  for (i = 0; i < size_first_exercice - 1; i++) {
    first[i] = size_first_exercice;
    second[i] = size_first_exercice;
  }
  first[size_first_exercice] = -1;
  second[size_first_exercice] = -1;

  int equals = are_arrays_equal(first, second);
  printf("first array == second | expected : 1 | actual : %d\n", equals);

  first[size_first_exercice - 2] = size_first_exercice - 2;

  equals = are_arrays_equal(first, second);
  printf("first array == second | expected : 0 | actual : %d\n", equals);

  int *third = allocate_integer_array(size_first_exercice - 3);
  for (i = 0; i < size_first_exercice - 4; i++) {
    third[i] = size_first_exercice - 4;
  }
  third[size_first_exercice - 3] = -1;

  equals = are_arrays_equal(first, second);
  printf("first array == third | expected : 0 | actual : %d\n", equals);

  int *t2 = copy_array(t);
  equals = are_arrays_equal(t, t2);
  putchar('\n');
  printf("Tableau T2 copié depuis T1");
  print_array(t2);
  printf(" t == t2 | expected : 1 | actual : %d\n", equals);

  free_integer_array(t);
  free_integer_array(first);
  free_integer_array(second);
  free_integer_array(third);
  free_integer_array(t2);
}

void exercice_2() {

  /* printf("fill_array\n");
  int* t = fill_array();

  print_array(t);
  putchar('\n'); */

  printf("random_array\n");
  int *t2 = random_array(5, 10);
  print_array(t2);

  printf("concat_array\n");
  int *t3 = random_array(5, 10);
  int *t4 = concat_array(t2, t3);
  print_array(t3);
  print_array(t4);

  /* free_integer_array(t); */
  free_integer_array(t2);
  free_integer_array(t3);
  free_integer_array(t4);
}

void exercice_3() {
    int *first = allocate_integer_array(5);
    
    first[0] = 0;
    first[1] = 2;
    first[2] = 8;
    first[3] = 9;
    first[4] = 11;
    first[5] = -1;

    

    int *second = allocate_integer_array(6);
    second[0] = 3;
    second[1] = 7;
    second[2] = 8;
    second[3] = 10;
    second[4] = 12;
    second[5] = 14;
    second[6] = -1;

    print_array(first);
    print_array(second);

    int* sorted_merged_array = merge_sorted_arrays(first, second);
    print_array(sorted_merged_array);

    putchar('\n');

    int* first_p;
    int* second_p;
    split_arrays(sorted_merged_array, &first_p, &second_p);
    print_array(first_p);
    print_array(second_p);

    free_integer_array(sorted_merged_array); 
    free_integer_array(first);
    free_integer_array(second);
    free(first_p);
    free(second_p);
}

int main(int argc, char *argv[]) {
  /* exercice_1(); */
  /* exercice_2(); */
  
  exercice_3();
  return 0;
}