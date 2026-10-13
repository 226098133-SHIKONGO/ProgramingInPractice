#include <stdio.h>
#include "budget.h"

void manageBudget(void) {
    float revenue, expenses, balance;
    printf("Enter Municipal Revenue: ");
    scanf("%f", &revenue);
    printf("Enter Municipal Expenses: ");
    scanf("%f", &expenses);

    balance = revenue - expenses;
    printf("Budget Balance: %.2f -> Status: ", balance);
    if (balance > 0) {
        printf("SURPLUS\n");
    } else if (balance < 0) {
        printf("DEFICIT\n");
    } else {
        printf("BALANCED\n");
    }
}