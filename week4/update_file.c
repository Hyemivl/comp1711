#include "utils.h"

int main()
{
    char* filename = "numbers.dat";
    FILE *file = open_file(filename, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];
    float mean=0;
    int counter =0;
    
    while (fgets(line_buffer, buffer_size, file) != NULL)
    {
        mean += atof(line_buffer);
        counter++;
    }
    mean /= counter;
    fclose(file);
    file = open_file(filename, "a+");
    if(fgets(line_buffer,buffer_size,file) != "");
    {
        fprintf(file,"\n");
    }
    fprintf(file,"%g",mean);
}