#include <stdio.h>
#include <string.h>

int main() 
{ 
    char supplierName[50]; 
    float price; 
    float budget; 
    int registered; 
    int documentsComplete; 

    
    printf("Enter supplier name: "); 
    fgets(supplierName, sizeof(supplierName), stdin);
    
    supplierName[strcspn(supplierName, "\n")] = 0;

    printf("Enter tender price: "); 
    scanf("%f", &price); 

    printf("Enter available budget: "); 
    scanf("%f", &budget); 

    printf("Is supplier registered? (1=Yes, 0=No): "); 
    scanf("%d", &registered); 

    printf("Are all documents complete? (1=Yes, 0=No): "); 
    scanf("%d", &documentsComplete); 

    printf("\n----------------------------------------\n");
    printf("TENDER EVALUATION RESULTS\n");
    printf("----------------------------------------\n");
    printf("Supplier Name : %s\n", supplierName); 

    if (registered == 0 || documentsComplete == 0) 
    { 
        printf("Status        : Disqualified (Missing registration or documents)\n"); 
    } 
    else if (price > budget) 
    { 
        printf("Status        : Disqualified (Price exceeds budget)\n"); 
    } 
    else 
    { 
        printf("Status        : Qualified\n"); 
    } 

    return 0; 
}