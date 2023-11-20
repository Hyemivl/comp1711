#include <stdio.h>

void printColumn(int a[][4], int colIndex, int rows, char when) {
    switch (when) {
        case 'B':
            printf("Values in column %d before change:\n", colIndex); break;

        case 'A':
            printf("Values in column %d after change:\n", colIndex); break;

        default: 
            printf("Invalid option\n");
            return;
    }
    //iterates through column to change and outputs value
    for (int i = 0; i < rows; ++i) {
        printf("%d\n", a[i][colIndex]);
    }
}

//colIndex is used to determine which collumn is changed
void changeColumn(int a[][4], int colIndex, int rows, int newValue) {
    //iterates through each row
    for (int i = 0; i < rows; ++i) {
        //changes value at desired collumn at each row
        a[i][colIndex] = newValue;
    }
}

int main() {
    //initialises 3x4 array
    int array1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int colIndexToChange = 2; // Change the values in the third column (column at index 2)
    int newValue = 20;

    printColumn(array1, colIndexToChange, 3, 'B'); // 'B' stands for Before
    changeColumn(array1, colIndexToChange, 3, newValue); // changes values in col 3 to newValue
    printColumn(array1, colIndexToChange, 3, 'A'); // 'A' stands for After

    return 0;
}
