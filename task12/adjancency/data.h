#include <stdio.h>
#define N 11

enum bool{FALSE, TRUE};

typedef int adjmat[N][N];

void print_mat(adjmat);
void get_numbers(adjmat);
int path(adjmat, int, int);
