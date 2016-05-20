/*
  mn_som101.c
*/

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() */
#include <math.h>   /* for sqrt(), log(), M_PI */

#define DIM_X 2
#define SIGMA 5
#define N_UNITS 100
#define RAND_SEED 20160520
#define N_LEARNING 10000

double x[DIM_X];
double m[N_UNITS][DIM_X];

void init_ref_vec(){

  int i;
  for(i=0; i<N_UNITS; i++){     
    m[i][0] = drand48();
    m[i][1] = drand48();
  }

}

void generate_a_input(){

  x[0] = drand48();
  x[1] = drand48();

}


int compute_winner(){

  int i,j;
  int c;
  double d, dmin;

  d = 0.0;
  for(j=0; j<DIM_X; j++){     
    d+=(x[j] - m[0][j])*(x[j] - m[0][j]);
  }
  dmin =d;
  c=0;

  for(i=1; i<N_UNITS; i++){     
    d = 0.0;
    for(j=0; j<DIM_X; j++){     
      d+=(x[j] - m[i][j])*(x[j] - m[i][j]);
    }
    if ( d < dmin ){
      dmin = d;
      c = i;
    }
  }

  return c;
  
}

void learning(int c){

  int i,j;
  double h;
  double sigma = (double)SIGMA;
  double mu = 0.01;
  
  for(i=0; i<N_UNITS; i++){     
    h = -(c-i)*(c-i)/(2.0*sigma*sigma);
    h = exp(h);
    for(j=0; j<DIM_X; j++){     
      m[i][j] = m[i][j] + mu*h*(x[j]-m[i][j]);
    }
  }

}

void write_results(){

  int i,j;
  for(i=0; i<N_UNITS; i++){     
    printf("%.5lf %.5lf\n", m[i][0],m[i][1]);
  }
  printf("\n");
  
}



int main (int argc, char *argv[] ){
  
  int i;
  int c;
  int seed = RAND_SEED;
  
  srand48(123);
 
  // 0. make a circuit
  //  1. initialize reference vector (connection weights)
  init_ref_vec();
  
  write_results();

  for(i=0; i<N_LEARNING; i++){     
  
  //  2. generate an input x
    generate_a_input();

  //   3. compute the winner unit
    c = compute_winner();

    //   4. do neiborhood learning for all units
    learning(c);
    
    //   5. repeat from 2.
  }

  write_results();

  return 0;
  
}
