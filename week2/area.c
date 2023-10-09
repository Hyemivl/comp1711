#include <stdio.h>

int main()
{
    int height;
    int width;
    printf("Enter the height of the rectangle: ");
    scanf("%d",&height);
    printf("Enter the width of the rectangle: ");
    scanf("%d",&width);
    printf("The area of the rectangle is %d\n", height * width);
    return 0;    
}