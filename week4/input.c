#include <stdio.h>
#include <stdlib.h>


int main()
{
    int ARRAYSIZE = 200;

    char* filename = "input.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int array[ARRAYSIZE];
    int counter = 0;
    int counterabove = 0;

    int buffersize = 10;
    char linebuffer[buffersize];
    while (fgets(linebuffer, buffersize, file) != NULL)
    {
        array[counter] = atoi(linebuffer);
        printf("%d\n", atoi(linebuffer));
        counter++;
        if (atoi(linebuffer) > 1000)
        {
            counterabove++;
        }
    }

    fclose(file);

    printf("There are %d numbers\n",counter);
    printf("There are %d numbers above 1000\n",counterabove);
    
    for (int i = 0; i < ARRAYSIZE; i++)
    {
        for (int j = 0; j < ARRAYSIZE; j++)
        {
            if(array[i]+array[j] == 2020)
            {
                printf("The two numbers that add to 2020 are %d and %d\n",array[i],array[j]);
                return 0;
            }
        }
        
    }
    
    return 0;
}