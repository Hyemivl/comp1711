#include <stdio.h>

int main()
{
    char *filename = "data.txt";

    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    printf("Would you like to enter strings or integers into the file (s for string i for integers)");
    char input;
    scanf("%c",&input);
    if (input == 's'||input == 'S')
    {
        char string[50];
        printf("Enter how many strings to write: ");
        int num_lines;
        scanf("%d",&num_lines);
        float mean;
        printf("Type %d strings: ", num_lines);
    
        for (int i = 0; i < num_lines; i++)
        {
           scanf("%s", string);
           fprintf(file, "%s\n", string);
        }
    }
    else if(input == 'i'|| input == 'I')
    {
        int number;
        printf("Enter how many numbers to write: ");
        int num_lines;
        scanf("%d",&num_lines);
        float mean;
        printf("Type %d numbers: ", num_lines);
    
        for (int i = 0; i < num_lines; i++)
        {
            scanf("%d", &number);
            fprintf(file, "%d\n", number);
            mean += number;
        }
        mean /= num_lines;
        fprintf(file, "%g\n",mean); 
    }
    else
    {
        printf("Option unavailable");
    }

    fclose(file);
    return 0;
}