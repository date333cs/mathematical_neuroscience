/*
  mn_bm001.c
*/

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() */
#include <math.h>   /* for sqrt(), log(), M_PI */

/* Data Structure */

#define N_NEURONS 3
#define RAND_SEED 20160610

double w[N_NEURONS+1][N_NEURONS+1];  /* 20 should be more than (N_NEURONS+1) */
double x[20];
int s[2050];  /* #states; more than 2**(N_NEURONS+1) */
double p[2050]; 
double q[2050];

double f[N_NEURONS+1][N_NEURONS+1];
double g[N_NEURONS+1][N_NEURONS+1];


void project31a(){

/* 
   Experimental Procedure:

   1. init weight connections
   2. compute stationary q distibution
   3. set x zero
   4. choose a unit romdomly, and update its value. 
   5. print how many times each state appeared.
*/

}


int main ( int argc , char * argv [])
{ 

    
    project31a();
    return 0;
	
}

