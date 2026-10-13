#include <stdio.h>
#include <string.h>
#include "employees.h"

#define MAX_EMP 50

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

static Employee employees[MAX_EMP];
static int empCount = 0;

void addEmployee(void) {
    if (empCount >= MAX_EMP) {
        printf("Employee database is full.\n");
        return;
    }
    printf("Enter Employee ID: ");
    scanf("%d", &employees[empCount].id);
    getchar(); // Clear newline buffer
    
    printf("Enter Employee Name: ");
    fgets(employees[empCount].name, sizeof(employees[empCount].name), stdin);
    employees[empCount].name[strcspn(employees[empCount].name, "\n")] = '\0';
    
    printf("Enter Employee Salary: ");
    scanf("%lf", &employees[empCount].salary);

    empCount++;
    printf("Employee added successfully!\n");
}

void listEmployees(void) {
    if (empCount == 0) {
        printf("No employees recorded in memory.\n");
        return;
    }
    printf("\n--- EMPLOYEE LIST ---\n");
    for (int i = 0; i < empCount; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
}

void searchEmployeeModule(void) {
    int searchId;
    int found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);
    
    for (int i = 0; i < empCount; i++) {
        if (employees[i].id == searchId) {
            printf("Found -> ID: %d | Name: %s | Salary: %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Employee ID %d not found.\n", searchId);
    }
}

void saveEmployeesToFile(void) {
    FILE *fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        perror("Error opening employees.txt for writing");
        return;
    }
    for (int i = 0; i < empCount; i++) {
        fprintf(fp, "%d|%s|%.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    fclose(fp);
    printf("Employees saved to employees.txt successfully!\n");
}

void loadEmployeesFromFile(void) {
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        perror("Error opening employees.txt for reading");
        return;
    }
    empCount = 0;
    while (fscanf(fp, "%d|%49[^|]|%lf\n", &employees[empCount].id, employees[empCount].name, &employees[empCount].salary) == 3) {
        empCount++;
        if (empCount >= MAX_EMP) break;
    }
    fclose(fp);
    printf("Loaded %d employees from file successfully!\n", empCount);
}