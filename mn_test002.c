/*  gcc mn_test.c irl_utility.c -lm   */

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() ,malloc() */
#include <math.h>   /* for sqrt(), log(), M_PI */
#include "irl_utility.h"

void
test(int *x, double **w, int n, int h){

  int i, j;

  for (i = 0; i< n; i++) {
    printf("%d ",x[i]);
  }

  for (i = 0; i< n; i++) {
    for (j = 0; j< h; j++) {
      printf("w[%d][%d]=%.2lf\n",j, i, w[j][i]);
    w[j][i]= (double)(i+j);
    }
  }
  
}


int
main ( int argc , char * argv [])
{

  int i, j;
    int n,h;
    int *x;
    double *y, **w;
    
    n = 10;
    h = 5;
    
    x = (int *) alloc_1d_int(n); 
    y = (double *) alloc_1d_dbl(h); 
    w = (double **) alloc_2d_dbl(h, n); 
    
/*  
  use x[], y[] and w[][] here.
*/
    for (i = 0; i< n; i++) {
      x[i]=i;
    }
    for (i = 0; i< n; i++) {
      for (j = 0; j< h; j++) {
	w[j][i]= (double)(i+j);
      }
    }
    test(x, w, n, h);
    
      
    free( (char *) x);
    free( (char *) y);
    for (i = 0; i< h; i++) {
        free( (char *) w[i]);
    }
    free( (char *) w);

    return 0;
}
