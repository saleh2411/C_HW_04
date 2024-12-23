#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for Student
typedef struct Student {
    int ID;
    char name[50];
    int age;
    float GPA;
    struct Student* next;  // Pointer to the next student in the list
} Student;

// Function to create a new student
Student* createStudent(int ID, const char* name, int age, float GPA) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    if (!newStudent) {
        perror("Failed to allocate memory for new student");
        exit(EXIT_FAILURE);
    }
    newStudent->ID = ID;
    strncpy(newStudent->name, name, sizeof(newStudent->name) - 1);
    newStudent->name[sizeof(newStudent->name) - 1] = '\0';
    newStudent->age = age;
    newStudent->GPA = GPA;
    newStudent->next = NULL;
    return newStudent
}


// Function to create a linked list of students
Student* createStudentList() {

}

// Function to find the student with the highest GPA
Student* findTopStudent(Student* head) {
}

// Function to delete the student with the lowest GPA
Student* deleteLowestGPA(Student* head) {
}

// Function to print all students
void printAllStudents(Student* head) {
}

// Function to free the memory of the entire student list
void freeStudentList(Student* head) {
}

int main() {
    // Create the student list
    Student* head = createStudentList();

    // Print all students
    printf("\nAll Students:\n");
    printAllStudents(head);

    // Find and print the top student with the highest GPA
    Student* topStudent = findTopStudent(head);
    if (topStudent != NULL) {
        printf("\nTop Student:\n");
        printStudent(topStudent);
    }

    // Delete the student with the lowest GPA and print the updated list
    head = deleteLowestGPA(head);
    printf("\nAfter deleting the student with the lowest GPA:\n");
    printAllStudents(head);

    // Free the memory of the student list
    freeStudentList(head);

    return 0;
}
