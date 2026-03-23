#include <stdio.h>
#include <math.h>
#include "n_queen.h"


int main(){
    solveProblem(3,3,1);
    solveProblem(4,3,2);
    solveProblem(4,4,3);
    solveProblem(6,4,4);
    solveProblem(8,5,5);
    solveProblem(10,7,6);
    solveProblem(10,8,7);
    //solveProblem(999,666,8);
    //solveProblem(100,67,9);
    solveProblem(100,30,11);
    return 0;
}