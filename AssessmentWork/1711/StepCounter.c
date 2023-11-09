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
int counter = 0;
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
    printf("Enter option: ");
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

    do
    {
        menu();
        scanf("%c",&input);
        input |= ' '; // Convert input to lowercase
        switch (input)
        {
        case 'a':
            printf("Input Filename: ");
            scanf("%s",filename);
            if(FileExists(file,filename) == 1)
            {
                return 1;
            }
            break;
        case 'b':
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
            break;
        case 'd':
            break;
        case 'e':
            break;
        case 'f':
            break;
        case 'q':
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    } while (input != 'q');
    
}










