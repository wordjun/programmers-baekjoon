#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int poly(int n, int *a);

int main()
{
    int *a, n, i;
    a = (int*)malloc(sizeof(int) * SIZE);
    printf("Enter degree of polynomial: ");
    scanf_s("%d", &n);
    printf("Enter coefficients of the polynomial: ");
    for (i = n; i >= 0; i--)
    {
        printf("Enter coefficient of x^%d: ", i);
        scanf_s("%d", &a[i]);
    }
    printf("%d", poly(n, a));

    free(a);
    return 0;
}

int poly(int n, int *a)
{
    int sum = 0;
    int i, x = 1;
    for (i = n; i > 0; i--)
    {
        sum = (sum + a[i]) * x;
    }
    sum = sum + a[0];
    return sum;
}