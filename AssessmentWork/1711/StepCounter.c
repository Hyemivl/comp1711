#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

// number of characters which will be read per line
int buffer_size = 50;
// a string to hold each line making it the same size as the buffer size
char line_buffer[50];
// a multi purpose counter used in the switch statement
int counter = 0;
// a variable to hold the output of some functions
FITNESS_DATA output;
// hold temp variables to store tokenised values
char date[10];
char time[10];
char steps[10];
// Define array to output structs at the end
FITNESS_DATA data[500];

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }

void menu()
{
    printf("Menu options:\nA: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter option:");
}

int FileExists(FILE *file,char filename[])
{
    if(!(file = fopen(filename,"r")))
    {
        printf("Error: Could not find or open the file.\n");
        return 1;
    }
    fclose(file);
    return 0;
}


// Complete the main function
int main() 
{
    FILE *file;
    char input;
    char filename[100] = " ";

    while(1)
    {
        menu();
        input = getchar();        
        while (getchar() != '\n');
        switch (input)
        {
        case 'a':
        case 'A':
            printf("Input Filename: ");
            scanf("%s",filename);
            file = fopen(filename,"r");
            if (file == NULL)
            {
                printf("Error opening file\n");
                return 1;
            }
            while (getchar() != '\n');
            break;
        case 'b':
        case 'B':
            if(FileExists(file,filename) == 0)
            {
                file = fopen(filename,"r");
                {
                    // Reads file
                    while (fgets(line_buffer, buffer_size, file) != NULL) {
                    // keep track of how many lines there are
                    counter++;
                    }
                fclose(file);
                }
                printf("%d\n",counter);
                counter = 0;
            }
            else
            {
                printf("No valid filename selected.\n");
            }
            break;
        case 'c':
        case 'C':
            if(FileExists(file,filename) == 0)
            {
                file = fopen(filename,"r");
                {
                    // Counter set to high value so that every value will be below it to find the minimum
                    counter = 10000;
                    // Reads file
                    while (fgets(line_buffer, buffer_size, file) != NULL)
                    {
                        tokeniseRecord(line_buffer,",",date,time,steps);
                        if(counter > atoi(steps))
                        {
                            counter = atoi(steps);
                            strcpy(output.date,date);
                            strcpy(output.time,time);
                            output.steps = atoi(steps);
                        }
                    }
                fclose(file);
                }
                printf("Fewest steps: %s %s\n",output.date,output.time);
                counter = 0;
            }
            else
            {
                printf("No valid filename selected.\n");
            }
            break;
        case 'd':
        case 'D':
            if(FileExists(file,filename) == 0)
            {
                file = fopen(filename,"r");
                {
                    // Reads file
                    while (fgets(line_buffer, buffer_size, file) != NULL)
                    {
                        tokeniseRecord(line_buffer,",",date,time,steps);
                        if(counter < atoi(steps))
                        {
                            counter = atoi(steps);
                            strcpy(output.date,date);
                            strcpy(output.time,time);
                            output.steps = atoi(steps);
                        }
                    }
                fclose(file);
                }
                printf("Largest steps: %s %s\n",output.date,output.time);
                counter = 0;
            }
            else
            {
                printf("No valid filename selected.\n");
            }
            break;
        case 'e':
        case 'E':
            if(FileExists(file,filename) == 0)
            {
                double mean = 0;
                file = fopen(filename,"r");
                {
                    // Reads file
                    while (fgets(line_buffer, buffer_size, file) != NULL)
                    {
                        tokeniseRecord(line_buffer,",",date,time,steps);
                        counter++;
                        mean += atoi(steps);
                    }
                fclose(file);
                }
                mean =  (mean / counter);
                printf("Mean step count: %.0f\n",mean);
                counter = 0;
            }
            else
            {
                printf("No valid filename selected.\n");
            }
            break;
        case 'f':
        case 'F':
            if(FileExists(file,filename) == 0)
            {
                FITNESS_DATA start;
                FITNESS_DATA end;
                int length = 0;
                int maxlength = 0;
                counter = 0;
                file = fopen(filename,"r");
                {
                    // Reads file
                    while (fgets(line_buffer, buffer_size, file) != NULL)
                    {
                        tokeniseRecord(line_buffer,",",date,time,steps);
                        strcpy(data[counter].date,date);
                        strcpy(data[counter].time,time);
                        data[counter].steps = atoi(steps);
                        counter++;
                    }
                fclose(file);
                }
                for (int i = 0; i < counter; i++)
                {
                    if (data[i].steps > 500)
                    {
                        length++;
                    }
                    else
                    {
                        length = 0;
                    }
                    if(length > maxlength)
                    {
                        maxlength = length;
                    }
                }
                for (size_t i = 0; i < counter; i++)
                {
                    if(data[i].steps > 500 && length > 0)
                    {
                        end = data[i];
                        length ++;
                    }
                    else if(data[i].steps > 500)
                    {
                        start = data[i];
                        length = 1;
                    }
                    else
                    {
                        length = 0;
                    }
                    if (length == maxlength)
                    {
                        printf("Longest period start: %s %s\n",start.date,start.time);
                        printf("Longest period end: %s %s\n",end.date,end.time);
                    }
                }
                
                counter = 0;
            }
            else
            {
                printf("No valid filename selected.\n");
            }
            break;
        case 'q':
        case 'Q':
            return 0;
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }
    
}










