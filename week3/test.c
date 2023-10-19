#include <stdio.h>

int stringlength(char string[])
{
    int count = 0;
    while(string[count] != '\0')
    {
        count++;
    }
    return count;
}

char * stringConcat(char string1[], char string2[])
{
    int string1Len = stringlength(string1);
    int string2Len = stringlength(string2);
    char fullString[string1Len + string2Len];
    for (int i = 0; i < string1Len; i++)
    {
        fullString[i] = string1[i];
    }
    for (int i = 0; i < string2Len; i++)
    {
        fullString[i+string1Len] = string2[i];
    }
    return fullString;
    
}

void reverseArray(int array[], int length)
{
    int reverse[length];
    for (int i = 0; i < length; i++)
    {
        reverse[i] = array[length-1-i];
    }
    for (int i = 0; i < length; i++)
    {
        array[i] = reverse[i];
    }
}

float scan()
{
    float a, b;
    char c;
    printf("Enter a calculation: ");
    scanf("%f%c%f",&a,&c,&b);
    switch (c)
    { 
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case 'x':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    default:
        printf("Invalid expression\n");
        return -1;
        break;
    }
}

int main()
{
    //printf("%g\n",scan());
  //char c[50]; 
    //printf("Enter a string: ");
   //scanf("%s",c);
   //printf("%d\n",stringlength(c));
 /*int length = 5;
   int array[length];
   for (int i = 0; i < length; i++)
   {
        scanf("%d",&array[i]);
   }
   reverseArray(array,length);
   for (int i = 0; i < length; i++)
   {
        printf("%d\n", array[i]);
   }
   */
    printf("Enter a string: ");
    char string1[50];
    scanf("%s",string1);
    printf("Enter a new string: ");
    char string2[50];
    scanf("%s",string2);
    printf("%s",stringConcat(string1,string2));
}