/*
  mn_bm006.c
*/

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() */
#include <math.h>   /* for sqrt(), log(), M_PI */

/* Data Structure */

#define N_NEURONS 3
#define RAND_SEED 20160633

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

void set_w_random(){

  int i,j;
  int n = N_NEURONS+1;
  
  for (i=0; i<n; i++) {
    for (j=i+1; j<n; j++) {
      w[i][j] = 10.0*drand48() -5.0;
      w[j][i] = w[i][j];
    }
    w[i][i]=0.0;
  }
  
}

void set_w_x3_x6(){

  int i,j;
  int n = N_NEURONS+1;

  // 6ヶ所なので，手で書く．


  w[0][1] = 0.0;
  w[0][2] = 2.0;
  w[0][3] = 0.0;

  w[1][2] = 0.0;
  w[1][3] = -2.0;
  w[2][3] = 0.0;
  
  for (i=0; i<n; i++) {
    for (j=i+1; j<n; j++) {
      w[j][i] = w[i][j];
    }
    w[i][i]=0.0;
  }
  
}



void compute_pE_distibution(){

  int i,j,k;
  int x1,x2,x3;
  int n = N_NEURONS+1;
  double d, e;
  
    k = 0;
    d = 0.0;
    for (x3=0; x3<2; x3++) {
      for (x2=0; x2<2; x2++) {
	for (x1=0; x1<2; x1++) {
	  x[1]=x1;
	  x[2]=x2;
	  x[3]=x3;
	  
	  e = 0.0;
	  for (i=0; i<n; i++) {
	    for (j=i+1; j<n; j++) {
	      e += -w[i][j]*(double)x[i]*(double)x[j];
	    }
	  }
	  p[k] = exp(-e);
	  d += p[k];
	  k++;
	}
      }
    }

    for (i=0; i<8; i++) {
      printf("%.5lf ", (double)p[i]/(double)d);
    }
    printf("\n");
    
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

  int k;

  k = x[1] + 2*x[2] + 4*x[3];
  s[k]++;

}

void print_p_distibution(int m){

  int i;

  for (i=0; i<8; i++){
    printf("%.5lf ", (double)s[i]/(double)m);
  }    
  printf("\n");
  
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

    int n_iter = 1000000;
    int i, k;

    srand48(RAND_SEED);

    set_s_zero();

    set_w_zero();
    compute_pE_distibution();
    set_x_zero();  //  except x[0]=1;

    for (i=0; i< n_iter; i++) {
        k = choose_unit_randomly(); // k should be 1,2...,N_NEURONS
        update_a_unit(k);
        add_a_count();
    }

    print_p_distibution(n_iter);

}

void project31b(){


    int n_iter = 1000000;
    int i, k;


    set_s_zero();

    set_w_random();

    set_x_zero();  //  except x[0]=1;

    for (i=0; i< n_iter; i++) {
        k = choose_unit_randomly(); // k should be 1,2...,N_NEURONS
        update_a_unit(k);
        add_a_count();
    }

    print_p_distibution(n_iter);
    compute_pE_distibution();
}

void project31c(){

    int n_iter = 1000000;
    int i, k;

    set_s_zero();

    set_w_x3_x6();

    set_x_zero();  //  except x[0]=1;

    for (i=0; i< n_iter; i++) {
        k = choose_unit_randomly(); // k should be 1,2...,N_NEURONS
        update_a_unit(k);
        add_a_count();
    }

    print_p_distibution(n_iter);
    compute_pE_distibution();
}

int main ( int argc , char * argv []){ 

  int i;
  int seed = RAND_SEED;
  
  for (i=1; i<argc; i++) {
    switch (*(argv[i]+1)) {
    case 'r':
      seed = atoi(argv[++i]);
      break;
    default:
      fprintf(stderr, "Usage : %s\n",argv[0]);
      fprintf(stderr, "\t-r : random-seed(%d)\n",seed) ;
      exit(0);
      break;
    }
  }
  
  srand48(seed);
  
  //  project31a();
  //  project31b();
  project31c();
  
  return 0;
  
}

