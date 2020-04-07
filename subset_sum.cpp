// Subset Sum <subset_sum.cpp>
// EE 312 Quiz 2
// Jaxon Coward
// Jsc3536
// Slip days used: <0>
// Spring 2020
//===================================================================================
//Copied from example code by Milos Gligoric
//Only because I've been told that's what we were supposed to do for this assignment
//This is to make it clear I am in no way trying to pass this off as my own
//===================================================================================

#include <stdio.h>

int sumsTo(unsigned int x[], unsigned int n, unsigned int k, unsigned int v){
    if(v == 0 && k == 0)
        return true;
    if(v != 0 && k == 0)
        return false;
    if(n == 0)
        return false;

    int case1 = 0;
    int case2 = 0;

    if(v >= x[0])
        case2 = sumsTo(x + 1, n - 1, k - 1, v - x[0]);

    case1 = sumsTo(x + 1, n - 1, k, v);

    return case1 + case2 > 0;
}

int main(void){
    unsigned int array[5] = {1,8,6,4,3};
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 10; j++){
            printf("k = %d, v = %d    ", i, j);
            if(sumsTo(array, 5, i, j))
                printf("true\n");
            else
                printf("false\n");
        }
    }
}