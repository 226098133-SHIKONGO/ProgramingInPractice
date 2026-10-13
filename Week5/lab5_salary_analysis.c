#include <stdio.h>

#define NUM_EMPLOYEES 50

int main() {
    float salary;
    float total = 0;
    float highest = 0;
    float lowest = 0;
    float average;

    printf("=== Municipal Employee Salary Analysis (Week 5) ===\n");

    for (int i = 1; i <= NUM_EMPLOYEES; i++) {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

        total = total + salary;

       
        if (i == 1) {
            highest = salary;
            lowest = salary;
        } else {
            if (salary > highest) {
                highest = salary;
            }
            if (salary < lowest) {
                lowest = salary;
            }
        }
    }

    average = total / NUM_EMPLOYEES;

    printf("\n--- Salary Report ---\n");
    printf("Total Salary Expenditure: %.2f\n", total);
    printf("Average Salary:           %.2f\n", average);
    printf("Highest Salary:           %.2f\n", highest);
    printf("Lowest Salary:            %.2f\n", lowest);

    return 0;
}