#include <stdio.h>
#include <math.h>

int main()
{
    const float pi = 3.14159;
    float radius;
    printf("What is the radius of the circle: ");
    scanf("%f",&radius);
    printf("The area of the cirlce with radius %.2f is %.2f",radius,pi * radius *radius);
    return 0;
}