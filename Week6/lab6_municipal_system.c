#include <stdio.h>
#include <string.h>

int main() {
    int choice;

    do {
        printf("\n=========================================\n");
        printf("  MUNICIPAL INFORMATION MANAGEMENT SYSTEM  \n");
        printf("=========================================\n");
        printf("1. Manage Employee Salaries (50 Employees)\n");
        printf("2. Manage Department Budgets (10 Budgets)\n");
        printf("3. Manage Vehicle Registrations (20 Vehicles)\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                #define NUM_EMP 5
                // Note: Change NUM_EMP to 50 for the full lab requirement
                float salaries[NUM_EMP];
                float total = 0, average, highest, lowest;
                int found = 0;
                float searchVal;

                printf("\n--- A. Employee Salaries ---\n");
                for (int i = 0; i < NUM_EMP; i++) {
                    printf("Enter salary for employee %d: ", i + 1);
                    scanf("%f", &salaries[i]);
                    total += salaries[i];

                    if (i == 0) {
                        highest = salaries[i];
                        lowest = salaries[i];
                    } else {
                        if (salaries[i] > highest) highest = salaries[i];
                        if (salaries[i] < lowest) lowest = salaries[i];
                    }
                }

                average = total / NUM_EMP;

                printf("\nAll Salaries:\n");
                for (int i = 0; i < NUM_EMP; i++) {
                    printf("Employee %d: %.2f\n", i + 1, salaries[i]);
                }

                printf("Average Salary: %.2f\n", average);
                printf("Highest Salary: %.2f\n", highest);
                printf("Lowest Salary:  %.2f\n", lowest);

                // Search for a salary
                printf("\nEnter a salary to search for: ");
                scanf("%f", &searchVal);
                for (int i = 0; i < NUM_EMP; i++) {
                    if (salaries[i] == searchVal) {
                        printf("Salary %.2f found at position %d (Employee %d).\n", searchVal, i, i + 1);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Salary not found in records.\n");
                }
                break;
            }

            case 2: {
                #define NUM_BUDGETS 5
              
                float budgets[NUM_BUDGETS];
                float totalBudgets = 0, avgBudget;
                float temp;

                printf("\n--- B. Department Budgets ---\n");
                for (int i = 0; i < NUM_BUDGETS; i++) {
                    printf("Enter budget for department %d: ", i + 1);
                    scanf("%f", &budgets[i]);
                    totalBudgets += budgets[i];
                }

                avgBudget = totalBudgets / NUM_BUDGETS;

                // Bubble Sort (Ascending Order)
                for (int i = 0; i < NUM_BUDGETS - 1; i++) {
                    for (int j = 0; j < NUM_BUDGETS - i - 1; j++) {
                        if (budgets[j] > budgets[j + 1]) {
                            temp = budgets[j];
                            budgets[j] = budgets[j + 1];
                            budgets[j + 1] = temp;
                        }
                    }
                }

                printf("\nTotal Budget:   %.2f\n", totalBudgets);
                printf("Average Budget: %.2f\n", avgBudget);
                printf("Budgets Sorted (Lowest to Highest):\n");
                for (int i = 0; i < NUM_BUDGETS; i++) {
                    printf("%.2f\n", budgets[i]);
                }
                break;
            }

            case 3: {
                #define NUM_VEHICLES 3
                
                char registrations[NUM_VEHICLES][20];
                char searchReg[20];
                int found = 0;

                printf("\n--- C. Vehicle Registration Numbers ---\n");
                for (int i = 0; i < NUM_VEHICLES; i++) {
                    printf("Enter vehicle registration %d: ", i + 1);
                    scanf("%19s", registrations[i]);
                }

                printf("\nRegistered Vehicles:\n");
                for (int i = 0; i < NUM_VEHICLES; i++) {
                    printf("- %s\n", registrations[i]);
                }

                // Search for registration
                printf("\nEnter registration number to search: ");
                scanf("%19s", searchReg);
                for (int i = 0; i < NUM_VEHICLES; i++) {
                    if (strcmp(registrations[i], searchReg) == 0) {
                        printf("Registration '%s' found at index %d.\n", searchReg, i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Registration number not found.\n");
                }
                break;
            }

            case 4:
                printf("Exiting system. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }

    } while (choice != 4);

    return 0;
}