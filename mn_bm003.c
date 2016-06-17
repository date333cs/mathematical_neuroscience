/*
  mn_bm003.c
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

    int i;
    int m = (int)(pow(2.0, N_NEURONS));

    for (i=0; i<m; i++) {
        s[i] = 0;
    }

}

void set_w_zero(){

    int i,j;
    int n = N_NEURONS+1;

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            w[i][j] = 0.0;
        }
    }

}

void compute_p_distibution(){

}

void set_x_zero(){

    int i;
    int n = N_NEURONS+1;

    for (i=1; i<n; i++) {
        x[i] = 0;
    }
    x[0] = 1;

}

int choose_unit_randomly(){

    int k;

    k = (int)( drand48()*(double)N_NEURONS ) + 1;
/*  k should be 1,2...,N_NEURONS */

    return k;
}

void update_a_unit(int i){

  int j;
  int n = N_NEURONS+1;
  double u = 0.0;

  for (j=0; j<n; j++){
    u += w[i][j]*x[j];
  }    

  if ( drand48() < 1/(1.0 + exp(-u)) ){
    x[i] = 1;
  }
  else{
    x[i] = 0;
  }

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
    set_x_zero();  //  except x[0]=1;

    for (i=0; i< n_iter; i++) {
        k = choose_unit_randomly(); // k should be 1,2...,N_NEURONS
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

