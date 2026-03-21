#include <stdlib.h>
#include <stdio.h>
#include "n-queen.h"

#define MAX_N 1001

Queen found[queensPlaced];


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

void solveProblem(int n, int m){
    for(int i = 0; i < MAX_N; i++)
        row[i] = col[i] = diagonal[i] = false;

    if(backtrack(1,1,0,n,m))
        print(n,m);
    
}

