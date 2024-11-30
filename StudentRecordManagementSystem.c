#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    char name[50];
    int roll_number;
    float marks;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

// Function prototypes
void addStudent();
void viewStudents();
void editStudent();
void deleteStudent();
void menu();

int main() {
    menu();
    return 0;
}

// Function to display the menu
void menu() {
    int choice;
    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: editStudent(); break;
            case 4: deleteStudent(); break;
            case 5: printf("Exiting program.\n"); return;
            default: printf("Invalid choice! Please try again.\n");
        }
    }
}

// Function to add a student
void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Error: Maximum student limit reached.\n");
        return;
    }

    printf("Enter student name: ");
    getchar(); // To clear the buffer
    fgets(students[student_count].name, 50, stdin);
    students[student_count].name[strcspn(students[student_count].name, "\n")] = '\0'; // Remove newline

    printf("Enter roll number: ");
    scanf("%d", &students[student_count].roll_number);

    printf("Enter marks: ");
    scanf("%f", &students[student_count].marks);

    student_count++;
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents() {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < student_count; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll_number);
        printf("Marks: %.2f\n", students[i].marks);
        printf("-------------------\n");
    }
}

// Function to edit a student
void editStudent() {
    int roll_number, found = 0;
    printf("Enter roll number of student to edit: ");
    scanf("%d", &roll_number);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_number) {
            found = 1;
            printf("Editing student: %s\n", students[i].name);
            printf("Enter new name: ");
            getchar(); // To clear the buffer
            fgets(students[i].name, 50, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Enter new roll number: ");
            scanf("%d", &students[i].roll_number);

            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);

            printf("Student updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", roll_number);
    }
}

// Function to delete a student
void deleteStudent() {
    int roll_number, found = 0;
    printf("Enter roll number of student to delete: ");
    scanf("%d", &roll_number);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_number) {
            found = 1;
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with roll number %d not found.\n", roll_number);
    }
}