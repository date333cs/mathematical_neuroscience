/*
  irl_utility.c
*/

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

/* a random sample from standard normal distribution */
double nrand()
{
    static int sw = 0;
    static double r1, r2, s;
    
    if (sw == 0) {
        sw = 1;
        do {
            r1 = 2.0 * drand48() - 1.0;
            r2 = 2.0 * drand48() - 1.0;
            s = r1 * r1 + r2 * r2;
        } while (s > 1.0 || s == 0.0);
        s = sqrt(-2.0 * log(s) / s);
        return (r1 * s);
    } else {
        sw = 0;
        return (r2 * s);
    }
}


/*** Allocate 1d array of unsinged long long int ***/
unsigned long long int *alloc_1d_ullint(int n){
    
    unsigned long long int   *new;
    new = (unsigned long long int *) malloc ((unsigned) (n * sizeof (unsigned long long)));
    if (new == NULL) {
        printf("ALLOC_1D_LLU: Couldn't allocate array of unsigned long long\n");
        return (NULL);
    }
    return (new);
}


/*** Allocate 1d array of chars ***/
char *alloc_1d_char(int n){
    
    char *new;
    new = (char *) malloc ((unsigned) (n * sizeof (char)));
    if (new == NULL) {
        printf("ALLOC_1D_CHAR: Couldn't allocate array of chars\n");
        return (NULL);
    }
    return (new);
}


/*** Allocate 1d array of ints ***/
int *alloc_1d_int(int n){
    
    int *new;
    new = (int *) malloc ((unsigned) (n * sizeof (int)));
    if (new == NULL) {
        printf("ALLOC_1D_INT: Couldn't allocate array of ints\n");
        return (NULL);
    }
    return (new);
}


/*** Allocate 2d array of int`s ***/
int **alloc_2d_int(int m, int n){
    
    int i;
    int **new;
    new = (int **) malloc ((unsigned) (m * sizeof (int *)));
    if (new == NULL) {
        printf("ALLOC_2D_INT: Couldn't allocate array of int ptrs\n");
        return (NULL);
    }
    
    for (i = 0; i < m; i++) {
        new[i] = alloc_1d_int(n);
    }
    return (new);
}


/*** Allocate 1d array of doubles ***/
double *alloc_1d_dbl(int n){
    
    double *new;
    new = (double *) malloc ((unsigned) (n * sizeof (double)));
    if (new == NULL) {
        printf("ALLOC_1D_DBL: Couldn't allocate array of doubles\n");
        return (NULL);
    }
    return (new);
}


/*** Allocate 2d array of doubles ***/
double **alloc_2d_dbl(int m, int n){
    
    int i;
    double **new;
    new = (double **) malloc ((unsigned) (m * sizeof (double *)));
    if (new == NULL) {
        printf("ALLOC_2D_DBL: Couldn't allocate array of dbl ptrs\n");
        return (NULL);
    }
    
    for (i = 0; i < m; i++) {
        new[i] = alloc_1d_dbl(n);
    }
    
    return (new);
}
