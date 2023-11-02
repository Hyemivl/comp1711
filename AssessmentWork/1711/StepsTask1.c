#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here

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
FITNESS_DATA data[3];
char* filename = "FitnessData_2023.csv";

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

// Complete the main function
int main() {
    // Opening the file in read mode
    FILE *file = fopen(filename, "r");
    //Error case
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Reads file
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        tokeniseRecord(line_buffer,",",date,time,steps);
        // Only stores the first 3 values in the array to output
        if(counter<3)
        {
            // Copy values into the struct
            strcpy(data[counter].date,date);
            strcpy(data[counter].time,time);
            data[counter].steps = atoi(steps);
        }
        // keep track of how many lines there are
        counter++;
    }
    fclose(file);

    printf("Number of records in file: %d\n",counter);
    // iterate for how many records need to be shown
    for (int i = 0; i < 3; i++)
    {
        // Print according to set format
        printf("%s/%s/%d\n",data[i].date,data[i].time,data[i].steps);
    }
    
    return 0;

}