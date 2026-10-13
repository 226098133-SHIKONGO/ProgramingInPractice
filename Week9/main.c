#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "reports.h"
#include "utilities.h"

int main(void) {
    int choice;
    do {
        printf("\n========================================\n");
        printf("  MUNICIPAL FINANCIAL MANAGEMENT SYSTEM  \n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. List Employees\n");
        printf("3. Search Employee\n");
        printf("4. Save Employees to File\n");
        printf("5. Load Employees from File\n");
        printf("6. Manage Budget\n");
        printf("7. Generate Summary Report\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: listEmployees(); break;
            case 3: searchEmployeeModule(); break;
            case 4: saveEmployeesToFile(); break;
            case 5: loadEmployeesFromFile(); break;
            case 6: manageBudget(); break;
            case 7: generateSummaryReport(); break;
            case 8: printf("Exiting system. Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 8);

    return 0;
}