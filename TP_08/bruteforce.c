#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 200000000

/* ------------------------------------------------------ BRUTEFORCE */

int syracuse(unsigned long int val) {
    /* printf("%lu ", val); */
    if (val == 1) {
        return 0;
    }

    long long int steps;
    if (val % 2 == 0) {
        steps = 1 + syracuse(val / 2);
    } else {
        steps = 1 + syracuse(3 * val + 1);
    }
    return steps;
}

int get_max_fly_bruteforce() {
    int max = 0;
    int i, val;
    for (i = 1; i <= SIZE; i++) {
        val = syracuse(i);
        if (val > max) {
            max = val;
        }
    }
    return max;
}

/* ------------------------------------------------------ CACHED */

void fill_cache(long long int cache[], unsigned long int size) {
    unsigned long int i;
    for (i = 0; i < size; i++) {
        cache[i] = -1;
    }
}

long long int syracuse_cached(long long int val, long long int cache[]) {
    if (val == 1) {
        return 0;
    }

    if (val < SIZE) {
        long long int cached_value = cache[val - 1];
        if (cached_value != -1) {
            return cached_value;
        }
    }

    long long int steps;
    if (val % 2 == 0) {
        steps = 1 + (syracuse_cached(val / 2, cache));
    } else {
        steps = 1 + (syracuse_cached(3 * val + 1, cache));
    }

    if (val < SIZE) {
        if (cache[val - 1] == -1) {
            cache[val - 1] = steps;
        }
    }
    return steps;
}

int get_max_fly_cached() {
    long long int *cache = malloc(SIZE * sizeof(long long int));
    fill_cache(cache, SIZE);
    long long int max = 0;
    long long int val;
    int i;
    for (i = 1; i <= SIZE; i++) {
        val = syracuse_cached(i, cache);
        if (val > max) {
            max = val;
        }
    }
    free(cache);
    return max;
}

/* ------------------------------------------------------ MAIN */

float get_exec_time_and_fly(int *fly, int (*f)()) {
    clock_t start = clock();
    *fly = f();
    clock_t end = clock();
    return (float) (end - start) / CLOCKS_PER_SEC;
}

int main(int argc, char *argv[]) {
    /*  if (argc < 2) {
        printf("Argument attendu");
        return -1;
    }
    int n = atoi(argv[1]); */

    int fly_bruteforce, fly_cached;

    float time_cached = get_exec_time_and_fly(&fly_cached, get_max_fly_cached);
    printf("CACHED\nMAX_FLY %d, SIZE: %d, TIME:%f sec\n", fly_cached, SIZE,
           time_cached);

    float time_bruteforce =
        get_exec_time_and_fly(&fly_bruteforce, get_max_fly_bruteforce);
    printf("BRUTEFORCE\nMAX_FLY %d, SIZE: %d, TIME:%f sec\n", fly_bruteforce,
           SIZE, time_bruteforce);

    return 0;
}

/*
    C formatter
    https://en.wikipedia.org/wiki/C_data_types
    Mettre dans un .md
    Utilisation mémoire :
    Temps :
 */