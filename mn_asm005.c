/*
  mn_asm005.c
*/

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() */
#include <math.h>   /* for sqrt(), log(), M_PI */
#include "irl_utility.h"


void generate_memories(int **p, int n, int m){

  int i, j;

  for (j=0; j<m; j++){
    for (i=0; i<n; i++){
      if ( drand48() < 0.5 ){
	p[j][i] = 1;
      }
      else{
	p[j][i] = -1;
      }
    }
  }
      
} 


void print_memories(int **p, int n, int m){

  int i, j;

  for (j=0; j<m; j++){
    for (i=0; i<n; i++){
      printf("%3d",p[j][i]);
    }
    printf("\n");
  }
      
} 




void set_weights(double **w, int **p, int n, int m){

  int i,j,k;
  int c;
  
  for (i=0; i<n; i++){
    for (j=i+1; j<n; j++){
      c = 0;
      for (k=0; k<m; k++){
	c += p[k][i]*p[k][j];
      }
      w[i][j] = (double)c/(double)n;
      w[j][i]=w[i][j];
    }
    w[i][i]=0.0;
   }
  
}
 

void print_weights(double **w, int **p, int n, int m){

  int i,j,k;
  
  for (i=0; i<n; i++){
    for (j=0; j<n; j++){
      printf("w[%d][%d] = %.3lf\n",i,j,w[i][j]);
    }
  }
  
}




void set_initial_state(int *x){

}


void update_sates(int *x, int *ux){

}


int main ( int argc , char *argv []){

  int i, j;
  int m, n;
  int seed = 20160423;
  int *x;
  int *ux;
  int **p;
  double **w;
  
  n = 10;
  m = 80;
  
  srand48(seed);
  
  x = (int *) alloc_1d_int(n); 
  ux = (int *) alloc_1d_int(n); 
  w = (double **) alloc_2d_dbl(n, n); 
  p = (int **) alloc_2d_int(m, n); 
  
  generate_memories(p, n, m);
  //  print_memories(p, n, m);

  set_weights(w, p, n, m);
  print_weights(w, p, n, m);

  set_initial_state(x);
  
  for (i=0; i<20; i++){
    update_sates(x, ux);
  }
  
  return 0;
}
