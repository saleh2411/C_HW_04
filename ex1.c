#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS


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
     Student* head = NULL;
    Student* tail = NULL;
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int ID, age;
        float GPA;
        char name[50];

        printf("\nEnter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &ID);
        printf("Name: ");
        scanf("%s", name);
        printf("Age: ");
        scanf("%d", &age);
        printf("GPA: ");
        scanf("%f", &GPA);

        Student* newStudent = createStudent(ID, name, age, GPA);

        if (!head) {
            head = newStudent;
            tail = newStudent;
        } else {
            tail->next = newStudent;
            tail = newStudent;
        }
    }

    return head;
}

// Function to find the student with the highest GPA
Student* findTopStudent(Student* head) {
      if (!head) return NULL;

    Student* topStudent = head;
    for (Student* curr = head->next; curr != NULL; curr = curr->next) {
        if (curr->GPA > topStudent->GPA) {
            topStudent = curr;
        }
    }
    return topStudent;
}

// Function to delete the student with the lowest GPA
Student* deleteLowestGPA(Student* head) {
     if (!head) return NULL;

    Student* temp = head;
    Student* prev = NULL;
    Student* lowest = head;
    Student* lowestPrev = NULL;

    while (temp) {
        if (temp->GPA < lowest->GPA) {
            lowest = temp;
            lowestPrev = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!lowestPrev) {
        head = lowest->next;  // Lowest is the head
    } else {
        lowestPrev->next = lowest->next;
    }
    free(lowest);
    return head;
}

// Function to print all students
void printAllStudents(Student* head) {
    for (Student* curr = head; curr != NULL; curr = curr->next) {
        printf("ID: %d, Name: %s, Age: %d, GPA: %.2f\n", curr->ID, curr->name, curr->age, curr->GPA);
    }
}

// Function to free the memory of the entire student list
void freeStudentList(Student* head) {
     while (head) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }
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
