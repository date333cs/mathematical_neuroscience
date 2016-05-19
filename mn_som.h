/*
   mn_som.h
*/

#ifndef __SOM_H 
#define __SOM_H

typedef struct {
  int n1;  /* number of input units．入力信号の次元 */
  int n2;  /* number of units of SOM. 素子の数 */
  int dim; /* dimension of neual field (SOM array), SOM の配列（神経場）の次元 */
  double mu;
  double sigma;
  double *x; /* input vector */
  int winner;
  double **m; /* m[i][j]: refference vector of i-th units．j=0,1,2,...,(n1-1) */
  double **dm;
  double **r; /* r[i][k]  i番目の素子の神経場上の位置．k=0,..,dim-1 */
} SOM;

#define RAND_SEED 20160519

SOM* som_new(int n1, int n2, int dim);
void free_som(SOM* this);

#endif /* __SOM_H */
