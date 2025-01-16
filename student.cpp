#include <stdio.h>
#include <string.h>

struct Student {
    int studentID;
    char name[50];
    int age;
    char grade[5];
};

void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void updateStudent(struct Student students[], int count);

int main() {
    struct Student students[100];
    int choice, studentCount = 0;
    
    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Update Student Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume the newline character
        
        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                updateStudent(students, studentCount);
                break;
            case 5:
                printf("Exiting program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void addStudent(struct Student students[], int *count) {
    struct Student newStudent;
    
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.studentID);
    getchar();
    printf("Enter Name: ");
    fgets(newStudent.name, 50, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';  // Remove newline character
    printf("Enter Age: ");
    scanf("%d", &newStudent.age);
    getchar();
    printf("Enter Grade: ");
    fgets(newStudent.grade, 5, stdin);
    newStudent.grade[strcspn(newStudent.grade, "\n")] = '\0';  // Remove newline character
    
    students[*count] = newStudent;  // Add new student to the array
    (*count)++;
    
    printf("Student added successfully!\n");
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students available to display.\n");
        return;
    }
    
    printf("\nStudent Details:\n");
    printf("ID    | Name                | Age | Grade\n");
    printf("---------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-6d | %-20s | %-3d | %-5s\n", students[i].studentID, students[i].name, students[i].age, students[i].grade);
    }
}

void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to search.\n");
        return;
    }

    int searchID, found = 0;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < count; i++) {
        if (students[i].studentID == searchID) {
            printf("\nStudent Found!\n");
            printf("ID: %d\n", students[i].studentID);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Grade: %s\n", students[i].grade);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found.\n", searchID);
    }
}

void updateStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to update.\n");
        return;
    }
    
    int searchID, found = 0;
    printf("Enter Student ID to update: ");
    scanf("%d", &searchID);
    
    for (int i = 0; i < count; i++) {
        if (students[i].studentID == searchID) {
            printf("\nStudent Found! Enter new details.\n");
            
            printf("Enter Name: ");
            getchar();  // To consume the leftover newline
            fgets(students[i].name, 50, stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';
            
            printf("Enter Age: ");
            scanf("%d", &students[i].age);
            
            printf("Enter Grade: ");
            getchar();  // To consume the leftover newline
            fgets(students[i].grade, 5, stdin);
            students[i].grade[strcspn(students[i].grade, "\n")] = '\0';
            
            printf("Student details updated successfully!\n");
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Student with ID %d not found.\n", searchID);
    }
}
