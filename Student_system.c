#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "students.txt"

// Structure to hold Student Records
typedef struct {
    int id;
    char name[50];
    char course[50];
    float gpa;
} Student;

// Function Prototypes
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main() {
    int choice;

    while (1) {
        printf("\n=====================================\n");
        printf("   Student Management System (Task 3) \n");
        printf("=====================================\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6:
                printf("\nExiting Student Management System. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select an option between 1 and 6.\n");
        }
    }
    return 0;
}

// 1. Function to Add a Student Record (Append to File)
void addStudent() {
    FILE *fp = fopen(FILE_NAME, "ab"); // Open in append-binary mode
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    Student s;
    printf("\nEnter Student ID (Integer): ");
    scanf("%d", &s.id);
    getchar(); // Clear newline buffer

    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Course: ");
    fgets(s.course, sizeof(s.course), stdin);
    s.course[strcspn(s.course, "\n")] = 0; 

    printf("Enter GPA: ");
    scanf("%f", &s.gpa);

    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);

    printf("\nRecord Added Successfully!\n");
}

// 2. Function to Display All Student Records
void displayStudents() {
    FILE *fp = fopen(FILE_NAME, "rb"); // Open in read-binary mode
    if (fp == NULL) {
        printf("\nNo student records found. File is empty.\n");
        return;
    }

    Student s;
    printf("\n%-10s %-25s %-20s %-5s\n", "ID", "Name", "Course", "GPA");
    printf("------------------------------------------------------------------\n");

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        printf("%-10d %-25s %-20s %-.2f\n", s.id, s.name, s.course, s.gpa);
    }
    fclose(fp);
}

// 3. Function to Search a Record by ID
void searchStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found to search.\n");
        return;
    }

    int searchId, found = 0;
    Student s;

    printf("\nEnter Student ID to search: ");
    scanf("%d", &searchId);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == searchId) {
            found = 1;
            printf("\n--- Record Found ---\n");
            printf("ID: %d\nName: %s\nCourse: %s\nGPA: %.2f\n", s.id, s.name, s.course, s.gpa);
            break;
        }
    }

    if (!found) {
        printf("\nStudent with ID %d not found.\n", searchId);
    }
    fclose(fp);
}

// 4. Function to Update a Record
void updateStudent() {
    FILE *fp = fopen(FILE_NAME, "rb+"); // Open for reading and writing
    if (fp == NULL) {
        printf("\nNo records found to update.\n");
        return;
    }

    int updateId, found = 0;
    Student s;

    printf("\nEnter Student ID to update: ");
    scanf("%d", &updateId);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == updateId) {
            found = 1;
            getchar(); // Clear buffer

            printf("\nEnter New Name: ");
            fgets(s.name, sizeof(s.name), stdin);
            s.name[strcspn(s.name, "\n")] = 0;

            printf("Enter New Course: ");
            fgets(s.course, sizeof(s.course), stdin);
            s.course[strcspn(s.course, "\n")] = 0;

            printf("Enter New GPA: ");
            scanf("%f", &s.gpa);

            // Move the file pointer back to the start of this specific record
            fseek(fp, -sizeof(Student), SEEK_CUR);
            fwrite(&s, sizeof(Student), 1, fp);
            printf("\nRecord Updated Successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nStudent with ID %d not found.\n", updateId);
    }
    fclose(fp);
}

// 5. Function to Delete a Record
void deleteStudent() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) {
        printf("\nNo records found to delete.\n");
        return;
    }

    FILE *tempFp = fopen("temp.txt", "wb"); // Temporary file to store records we keep
    if (tempFp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    int deleteId, found = 0;
    Student s;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &deleteId);

    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        if (s.id == deleteId) {
            found = 1; // Skip writing this record to temp file
        } else {
            fwrite(&s, sizeof(Student), 1, tempFp);
        }
    }

    fclose(fp);
    fclose(tempFp);

    // Remove old file and rename temporary file to original database name
    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("\nRecord Deleted Successfully!\n");
    } else {
        printf("\nStudent with ID %d not found.\n", deleteId);
    }
}