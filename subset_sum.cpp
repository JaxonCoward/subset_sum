// Image <main.c>
// EE 312 practice maze
// Jaxon Coward
// Jsc3536
// Slip days used: <0>
// Spring 2020

int sumsTo(unsigned int x[], unsigned int n, unsigned int k, unsigned int v){
    // printf(”x[0], n, k, v: %d, %d, %d, %d\n”, x[0], n, k, v);
    // used up all numbers to reach sum 0
     if(v == 0 && k == 0)
         return true;
    // used up all numbers without reaching sum 0
     if(v!=0 && k == 0)
         return false;
    // used up all numbers without reaching sum 0
     if(n == 0)
         return false;

     int res1 = 0;
     if(v>= x[0])
        // include the first number of the array in the sum
         res1 = sumsTo(x + 1, n−1, k−1, v−x[0]);
    // exclude the first number in the sum
     int res2 = sumsTo(x + 1, n−1, k, v);
     return res1 + res2>0;
}