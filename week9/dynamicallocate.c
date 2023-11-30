#include <stdlib.h>
#include <stdio.h>

int main()
{
    char* address = malloc(200 * sizeof(char));
    int* data = malloc(70 * sizeof(int));
    int input;
    printf("Enter the size of samples: ");
    scanf("%d",&input);
    double* samples = malloc(input * sizeof(double));
}