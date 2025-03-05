#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NRELEM 100000000

int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    int *seq;
    if ( (seq = (int *) malloc(NRELEM * sizeof(int))) == NULL) {
        fprintf(stderr, "Eroare: Nu exista suficient spatiu\n");
        return 1;
    }
    seq[0] = 1;
    seq[1] = 2;
    seq[2] = 2;
    int pointer = 2, i = 3, elem = 2;
    // i va indica catre ultimul element din secventa + 1
    while (i < NRELEM) {
        // Calculam ce element adaugam
        elem = 3 - elem;

        // Calculam cate elemente adaugam
        int j = seq[pointer];

        // Adaugam elementele
        while (j > 0 && i < NRELEM) {
            seq[i ++] = elem;
            j --;
        }

        // Mutam pointerul
        pointer = pointer + 1;
    }
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Timp de executie: %f\n", cpu_time_used);
    return 0;
}