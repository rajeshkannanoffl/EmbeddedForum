#include <stdio.h>
#include <conio.h>
#define SIZE 10

struct Student{
    char name[SIZE];
    int id;
    char gender[SIZE];
};

void main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct Student S[n];
    printf("\nEnter the details of the student");
    for(int i=0; i<n; i++){
        printf("\n\tEnter student name: ");
        scanf("%s", &S[i].name);
        printf("\tEnter student id: ");
        scanf("%d", &S[i].id);
        printf("\tEnter student gender: ");
        scanf("%s", &S[i].gender);
    }
    printf("\n\nStudent Details are: ");
    for(int i=0; i<n; i++){
        printf("\n\tStudent %d Name: %s", i+1, S[i].name);
        printf("\tStudent %d ID: %d", i+1, S[i].id);
        printf("\tStudent %d Gender: %s", i+1, S[i].gender);
    }
}