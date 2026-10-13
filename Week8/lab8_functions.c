#include <stdio.h>

// Function Prototypes
void displayWelcome();
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);

int main() {
    int choice;
    displayWelcome();

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                float amount, vat;
                printf("Enter amount for VAT calculation: ");
                scanf("%f", &amount);
                vat = calculateVAT(amount);
                printf("VAT (15%): %.2f\n", vat);
                break;
            }
            case 2: {
                float basic, housing, transport, gross;
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                
                gross = calculateSalary(basic, housing, transport);
                printf("Gross Salary: %.2f\n", gross);
                break;
            }
            case 3: {
                float revenue, expenses, balance;
                printf("Enter municipal revenue: ");
                scanf("%f", &revenue);
                printf("Enter municipal expenses: ");
                scanf("%f", &expenses);
                
                balance = calculateBudget(revenue, expenses);
                printf("Budget Balance: %.2f -> Status: ", balance);
                if (balance > 0) {
                    printf("SURPLUS\n");
                } else if (balance < 0) {
                    printf("DEFICIT\n");
                } else {
                    printf("BALANCED\n");
                }
                break;
            }
            case 4: {
                int employeeIDs[] = {101, 102, 103, 104, 105};
                int size = 5;
                int searchId, position;

                printf("Enter employee ID to search: ");
                scanf("%d", &searchId);

                position = searchEmployee(searchId, employeeIDs, size);
                if (position != -1) {
                    printf("Employee found at position index %d.\n", position);
                } else {
                    printf("Employee not found (-1).\n");
                }
                break;
            }
            case 5:
                printf("Exiting MFMS Function-Based System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function Definitions
void displayWelcome() {
    printf("================================================\n");
    printf("  WELCOME TO THE MUNICIPAL FINANCIAL MANAGEMENT \n");
    printf("================================================\n");
}

void displayMenu() {
    printf("\n================================================\n");
    printf("          MUNICIPAL FINANCIAL MANAGEMENT        \n");
    printf("================================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee ID\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size) {
    for (int i = 0; i < size; i++) {
        if (ids[i] == id) {
            return i; 
        }
    }
    return -1; 
} 