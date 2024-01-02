#include <stdio.h>
#include <conio.h> // Note: Conio.h is non-standard and may not be available in all compilers.
#define SIZE 10

// Define a structure named 'Student' to hold information about a student
struct Student {
    char name[SIZE];
    int id;
    char gender[SIZE];
};

// Entry point of the program
void main() {
    int n;

    // Prompt the user to enter the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Declare an array of 'Student' structures based on user input
    struct Student S[n];

    // Prompt the user to enter details for each student
    printf("\nEnter the details of the student");
    for (int i = 0; i < n; i++) {
        printf("\n\tEnter student name: ");
        scanf("%s", &S[i].name);
        printf("\tEnter student id: ");
        scanf("%d", &S[i].id);
        printf("\tEnter student gender: ");
        scanf("%s", &S[i].gender);
    }

    // Display the details of all students
    printf("\n\nStudent Details are: ");
    for (int i = 0; i < n; i++) {
        printf("\n\tStudent %d Name: %s", i + 1, S[i].name);
        printf("\tStudent %d ID: %d", i + 1, S[i].id);
        printf("\tStudent %d Gender: %s", i + 1, S[i].gender);
    }
}