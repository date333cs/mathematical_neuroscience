/*
  mn_som002.c
*/

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() */
#include <math.h>   /* for sqrt(), log(), M_PI */
#include "irl_utility.h"
#include "mn_som.h"


void som_new(int n1, int n2, int dim_som){

}


int main (int argc, char *argv[] ){
    
  int i;
  int seed = RAND_SEED;

  SOM *som;
  int dim_som = 2; // dimension of neural fields (SOM array), SOM の配列（神経場）の次元 
  int n1 = 2; // dimension of input x[0]...x[(n1-1)]
  int n2 = 64; // number of units in the neural field, SOM の素子数
  
  for (i=1; i<argc; i++) {
    switch (*(argv[i]+1)) {
    case 'r':
      seed = atoi(argv[++i]);
      break;
    default:
      fprintf(stderr, "Usage : %s\n",argv[0]);
      fprintf(stderr, "\t-r : random seed(%d)\n",seed);
      exit(0);
      break;
    }
  }
  srand48(seed);
  

  // 0. make a circuit
  som = som_new(n1, n2, dim_som);

  //  1. initialize reference vector (connection weights)
  som_init_m(som, n1, n2);

  //  2. generate an input 
  //   3. compute the winner unit
  //   4. do neiborhood learning for all units
  //   5. repeat from 2.
  
  return 0;
  
}
