/*
  irl_utility.h
*/

#ifndef __IRL_UTILITY_H__
#define __IRL_UTILITY_H__

double nrand();

unsigned long long int *alloc_1d_ullint(int n);

char *alloc_1d_char(int n);

int *alloc_1d_int(int n);
int **alloc_2d_int(int m, int n);

double *alloc_1d_dbl(int n);
double **alloc_2d_dbl(int m, int n);

#endif  // __IRL_UTILITY_H__
