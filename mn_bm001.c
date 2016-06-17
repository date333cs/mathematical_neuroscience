/*
  mn_bm001.c
*/

#include <stdio.h>
#include <stdlib.h> /* for srand48(), drand48() */
#include <math.h>   /* for sqrt(), log(), M_PI */

int x[5];
double w[5][5];

void set_connection_zero_weights(){

  int i,j;

  for (i=0; i<4; i++){
    for (j=0; j<4; j++){
      w[i][j]=0.0;
    }
  }

}

void init_zero_x(){

  x[0]=1;
  x[1]=0;
  x[2]=0;
  x[3]=0;
  
}

void update_sate_x(int i){

  int j;
  double u;

  //  printf("%d ",k);

  u = 0.0;
  for (j=0; j<4; j++){
    u += w[i][j]*x[j];
  }    

  if ( drand48() < 1/(1.0 + exp(-u)) ){
    x[i] = 1;
  }
  else{
    x[i] = 0;
  }

}

void do1a(){

  int iter = 100;
  int i, k;
  double d;
  
  set_connection_zero_weights();

  init_zero_x();

  for (i=0; i<iter; i++){
    // 1から3の乱数を発生させる．それを k とする．
    d = drand48();
    if ( d < 0.333 ){
      k = 1;
    }
    else if ( d < 0.666 ){
      k = 2;
    }
    else{
      k=3;
    }
    update_sate_x(k);
  }
  
}
  

int main ( int argc , char * argv [])
{ 

  do1a();
  
  //


  return 0; 
	
}

