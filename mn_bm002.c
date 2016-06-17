/*
  mn_bm002.c
*/

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() */
#include <math.h>   /* for sqrt(), log(), M_PI */

/* Data Structure */

#define N_NEURONS 3
#define RAND_SEED 20160610

double w[N_NEURONS+1][N_NEURONS+1];  /* 20 should be more than (N_NEURONS+1) */
double x[20];
int s[2050];  /* for a counter. #states; more than 2**(N_NEURONS+1) */
double p[2050]; 
double q[2050];

double f[N_NEURONS+1][N_NEURONS+1];
double g[N_NEURONS+1][N_NEURONS+1];


void set_s_zero(){

}

void set_w_zero(){

}

void compute_p_distibution(){

}

void set_x_zero(){

}

int choose_unit_randomly(){

    int k;

    return k;
}

void update_a_unit(int k){

}

void add_a_count(){

}

void print_p_distibution(){

}


void project31a(){

/* 
   Experimental Procedure:

   1. init weight connections
   2. compute stationary p(x;w) distibution
   3. set x zero
   4. choose a unit romdomly, and update its value. 
   5. print how many times each state appeared.
*/

    int n_iter = 1000;
    int i, k;

    srand48(RAND_SEED);

    set_s_zero();

    set_w_zero();
    compute_p_distibution();
    set_x_zero();

    for (i=0; i< n_iter; i++) {
        k = choose_unit_randomly();
        update_a_unit(k);
        add_a_count();
    }

    print_p_distibution();

}


int main ( int argc , char * argv [])
{ 

    
    project31a();

    return 0;
	
}

