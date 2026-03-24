#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "n_queen.h"

extern double timeoutMs;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Naudojimas:\n  1. Iš failo: %s duomenys.txt\n  2. Is klaviatūros: %s -n 10 -m 7 -timeout 5000\n", argv[0], argv[0]);
        return 1;
    }

    int n = 0, m = 0;
    int testCount = 0;

    //Nuskaitoma kas buvo įvesta jei per klaviatūrą
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) n = atoi(argv[++i]);
        else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) m = atoi(argv[++i]);
        else if (strcmp(argv[i], "-timeout") == 0 && i + 1 < argc) timeoutMs = atof(argv[++i]);
    }

    // 1 variantas: jei N ir M jau nurodyti per parametrus (-n 10 -m 7)
    if (n > 0 && m > 0) {
        solveProblem(n, m, 1);
        return 0;
    }

    // 2 variantas: skaitymas iš failo
    if (argv[1][0] != '-') {
        FILE *inputSource = fopen(argv[1], "r");
        if (inputSource == NULL) {
            fprintf(stderr, "Klaida: Failas '%s' nerastas.\n", argv[1]);
            return 1;
        }
        
        while (fscanf(inputSource, "%d %d", &n, &m) == 2) {
            testCount++;
            solveProblem(n, m, testCount);
        }
        fclose(inputSource);
    }

    // Jei nieko neįvyko
    if (testCount == 0 && n == 0) {
        fprintf(stderr, "Klaida: Nenurodyti parametrai arba nerastas duomenu failas.\n");
        return 1;
    }

    return 0;
}