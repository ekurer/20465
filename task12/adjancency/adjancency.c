#include "data.h"

/* a program that takes a matrix from the user and checks if there's a path between two given nodes */
int main()
{
    adjmat mat;
    print_mat(mat);
    get_numbers(mat);
    return 0;
}

/* a function that will print out the matrix based on the numbers the user gave */
void print_mat(adjmat mat)
{
    int i = 0, j = 0;
    printf("Please enter %d numbers to create an adjacency matrix, representing a tree:\n", N * N);
    for(; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            scanf("%d", &mat[i][j]);
            printf("%d ", mat[i][j]);
        }
        fputc('\n', stdout);
    }
}

/* a function that asks for two numbers, until user will insert -1,-1 */
void get_numbers(adjmat mat)
{
    int u, v;
    printf("Please enter two numbers to check if there's a path between the two:\n");
    while(scanf("%d %d", &u, &v) == 2 && (u != -1 || v != -1))
    {
        printf("There *is%s a path between nodes %d and %d\n", (path(mat, u, v)) ? "*" : "n\'t*", u, v);
        printf("Please enter two numbers to check if there's a path between the two:\n");
    }
}

/* a short verification that the numbers are within the matrix range */
int in_range(int i) { return i >= 0 && i < N; }

/* a recursive function that checks whether there's a path between two nodes */
int path(adjmat mat, int u, int v)
{
    int i = 0;
    if(!in_range(u) || !in_range(v))
        return FALSE;
    if(u == v)
        return TRUE;
    for(; i < N; i++)
    {
        if(u != i && mat[u][i] && path(mat, i, v))
            return TRUE;
    }
    return FALSE;
}
