#include <stdio.h>

struct student {
    char name [20];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student new_student;
    printf("Enter your name: ");
    scanf("%[^\n]",new_student.name);
    printf("Enter your student id: ");
    scanf("%s",new_student.student_id);
    printf("Enter your mark: ");
    scanf("%d",&new_student.mark);
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);
    return 0;
}