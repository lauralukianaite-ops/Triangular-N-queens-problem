#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "n_queen.h"

#define MAX_N 1001

clock_t startTime;
double timeoutMs = 5000;
bool limitReached = false;
long long totalNodes = 0;
int firstQueenR = 1;
int firstQueenC = 1;

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

double calculateProgress(int r, int c, int n){
    double total = (n * (n + 1)) / 2.0;
    double progress = (r * (r - 1)) / 2.0 + c;
    return (progress / total) * 100.0;
}

void printPositions(int n, int m, int testNr, bool success){
    printf("Test%d: N=%d, M=%d;\n",testNr,n,m);

    if(limitReached){
        double progress = calculateProgress(firstQueenR, firstQueenC, n);
        printf("-timeout (completed %.5f%% backtracks).\n",progress);
    }
    else if(success){
        for(int i = 0; i < m; i++){
            printf("[%d;%d] ", found[i].r, found[i].c);
            if((i + 1) % 8 == 0)
                printf("\n");
        }
    } 
    else{
        printf("No solution.");
    }
    
    printf("\n\n");
}

bool backtrack(int rStart, int cStart, int queensPlaced, int n, int m){

    totalNodes++;
    if(totalNodes % 1000 == 0){
        double duration = (double)(clock() - startTime) * 1000.0 / CLOCKS_PER_SEC;
        if(duration > timeoutMs){
            limitReached = true;
            return false;
        }
    }

    if(queensPlaced == m)
        return true;

    for(int r = rStart; r <= n; r++){
        int startC;
        if(r == rStart)
            startC = cStart;
        else
            startC = 1;

            for(int c = startC; c <= r; c++){
                if(queensPlaced == 0){
                    firstQueenR = r;
                    firstQueenC = c;
                }

                int d = r - c;
                if(!row[r] && !column[c] && !diagonal[d]){
                    found[queensPlaced].r = r;
                    found[queensPlaced].c = c;
                    row[r] = column[c] = diagonal[d] = true;

                    if(backtrack(r,c+1,queensPlaced + 1,n,m))
                        return true;

                    if(limitReached)
                        return false;

                    row[r] = column[c] = diagonal[d] = false;
                }
            }
    }
    return false;
}

void solveProblem(int n, int m, int testNr){
    startTime = clock();
    limitReached = false;
    totalNodes = 0;
    firstQueenR = 1;
    firstQueenC = 1;

    for(int i = 0; i < MAX_N; i++)
        row[i] = column[i] = diagonal[i] = false;

    bool success = false;
    if(isSolvable(n,m))
        success = backtrack(1,1,0,n,m);
        
    printPositions(n,m,testNr,success);
}

