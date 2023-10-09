#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("The max size of int is %d\n",INT_MAX);
    printf("The max size of a float is %f\n", FLT_MAX);
    printf("The max size of a double is %lf\n", DBL_MAX);
    printf("The max size of a char is %d\n",CHAR_MAX);
    
    return 0;
}