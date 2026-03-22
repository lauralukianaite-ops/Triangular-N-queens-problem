#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "n_queen.h"

#define MAX_N 1001

bool row[MAX_N];
bool column[MAX_N];
bool diagonal[MAX_N];
Queen found[MAX_N];

bool isSolvable(int n, int m){
    int queens = floor((2*n+1)/3);
    if(m<=queens)
        return true;
    else
        return false;
}

void printPositions(int n, int m, int testNr){
    printf("Test%d: M=%d, N=%d;\n",testNr,n,m);
    for(int i = 0; i < m; i++){
        if(isSolvable(n,m))
            printf("[%d;%d] ", found[i].r, found[i].c);
        else
            printf("No solution.");
    }
    printf("\n");
}

bool backtrack(int rStart, int cStart, int queensPlaced, int n, int m){
    if(queensPlaced == m)
        return true;

    for(int r = rStart; r <= n; r++){
        int startC;
        if(r == rStart)
            startC = cStart;
        else
            startC = 1;

            for(int c = startC; c <= r; c++){
                int d = r - c;
                if(!row[r] && !column[c] && !diagonal[d]){
                    found[queensPlaced].r = r;
                    found[queensPlaced].c = c;
                    row[r] = column[c] = diagonal[d] = true;

                    if(backtrack(r,c+1,queensPlaced + 1,n,m))
                        return true;

                    row[r] = column[c] = diagonal[d] = false;
                }
            }
    }
    return false;
}

void solveProblem(int n, int m, int testNr){
    for(int i = 0; i < MAX_N; i++)
        row[i] = column[i] = diagonal[i] = false;

    if(isSolvable)
        backtrack(1,1,0,n,m);
        
    printPositions(n,m,testNr);
}

