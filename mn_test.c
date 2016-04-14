/*  gcc mn_test.c irl_utility.c -lm   */

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() ,malloc() */
#include <math.h>   /* for sqrt(), log(), M_PI */

int
main ( int argc , char * argv [])
{

    int i;
    int n,h;
    double *x, *y, **w;
    
    n = 10000;
    h = 10000;
    
    x = (double *) alloc_1d_dbl(n); 
    y = (double *) alloc_1d_dbl(h); 
    w = (double **) alloc_2d_dbl(h, n); 
    
/*  
  use x[], y[] and w[][] here.
*/

    free( (char *) x);
    free( (char *) y);
    for (i = 0; i< h; i++) {
        free( (char *) w[i]);
    }
    free( (char *) w);

    return 0;
}
