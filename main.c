#include <stdio.h>
#include <math.h>
#include "n-queen.h"

int calculateQueens(int n){
    return floor((2*n+1)/3);
}

int main(){
    int test = 5;
    solveProblem(3,calculateQueens(3));
    solveProblem(6,calculateQueens(6));
    solveProblem(9,calculateQueens(9));
    solveProblem(10,calculateQueens(10));
    solveProblem(14,calculateQueens(14));
    return 0;
}