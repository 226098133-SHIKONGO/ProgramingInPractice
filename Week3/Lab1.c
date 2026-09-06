#include <stdio.h>

int main() 
{ 
    float basicSalary; 
    float housing; 
    float transport; 
    float tax; 
    float grossSalary; 
    float netSalary; 

    // Read inputs from user
    printf("Enter basic salary: "); 
    scanf("%f", &basicSalary); 

    printf("Enter housing allowance: "); 
    scanf("%f", &housing); 

    printf("Enter transport allowance: "); 
    scanf("%f", &transport); 

    printf("Enter tax: "); 
    scanf("%f", &tax); 

    // Perform calculations
    grossSalary = basicSalary + housing + transport; 
    netSalary = grossSalary - tax; 

    // Output results formatted to 2 decimal places
    printf("\nGross Salary: %.2f\n", grossSalary); 
    printf("Net Salary: %.2f\n", netSalary); 

    return 0; 
}
