#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5

int main() {
    
    char supplierNames[MAX_SUPPLIERS][100];
    char emails[MAX_SUPPLIERS][100];
    char phones[MAX_SUPPLIERS][30];
    char towns[MAX_SUPPLIERS][50];
    int count = 0;
    int choice;

    do {
        printf("\n================================================\n");
        printf("   MFMS - SUPPLIER MANAGEMENT MODULE    \n");
        printf("================================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers & Name Lengths\n");
        printf("3. Search Supplier by Name\n");
        printf("4. Copy Supplier Name (strcpy demo)\n");
        printf("5. Construct Supplier Description (strcat demo)\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                if (count < MAX_SUPPLIERS) {
                    printf("\n--- Entering Details for Supplier %d ---\n", count + 1);
                    
                    printf("Enter supplier name: ");
                    fgets(supplierNames[count], sizeof(supplierNames[count]), stdin);
                    supplierNames[count][strcspn(supplierNames[count], "\n")] = '\0';

                    printf("Enter email: ");
                    fgets(emails[count], sizeof(emails[count]), stdin);
                    emails[count][strcspn(emails[count], "\n")] = '\0';

                    printf("Enter phone number: ");
                    fgets(phones[count], sizeof(phones[count]), stdin);
                    phones[count][strcspn(phones[count], "\n")] = '\0';

                    printf("Enter town: ");
                    fgets(towns[count], sizeof(towns[count]), stdin);
                    towns[count][strcspn(towns[count], "\n")] = '\0';

                    count++;
                    printf("Supplier added successfully!\n");
                } else {
                    printf("Supplier database is full (Max %d).\n", MAX_SUPPLIERS);
                }
                break;

            case 2:
                if (count == 0) {
                    printf("\nNo suppliers recorded yet.\n");
                } else {
                    printf("\n--- SUPPLIER DETAILS & STRING LENGTHS ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("\nSupplier %d:\n", i + 1);
                        printf("  Name  : %s (Length: %zu)\n", supplierNames[i], strlen(supplierNames[i]));
                        printf("  Email : %s (Length: %zu)\n", emails[i], strlen(emails[i]));
                        printf("  Phone : %s\n", phones[i]);
                        printf("  Town  : %s (Length: %zu)\n", towns[i], strlen(towns[i]));
                    }
                }
                break;

            case 3: {
                if (count == 0) {
                    printf("\nNo suppliers to search.\n");
                    break;
                }
                char searchName[100];
                int found = 0;
                printf("\nEnter supplier name to search: ");
                fgets(searchName, sizeof(searchName), stdin);
                searchName[strcspn(searchName, "\n")] = '\0';

                for (int i = 0; i < count; i++) {
                    if (strcmp(supplierNames[i], searchName) == 0) {
                        printf("Supplier found!\n");
                        printf("  Name: %s\n  Email: %s\n  Phone: %s\n  Town: %s\n", 
                               supplierNames[i], emails[i], phones[i], towns[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Supplier not found.\n");
                }
                break;
            }

            case 4: {
                if (count == 0) {
                    printf("\nNo suppliers available to copy.\n");
                    break;
                }
                char backup[100];
                strcpy(backup, supplierNames[0]);
                printf("\n[strcpy Demo] Copied first supplier name '%s' into backup variable.\n", backup);
                break;
            }

            case 5: {
                if (count == 0) {
                    printf("\nNo suppliers available to construct description.\n");
                    break;
                }
                char description[200];
                strcpy(description, supplierNames[0]);
                strcat(description, " operates in ");
                strcat(description, towns[0]);
                strcat(description, ".");
                printf("\n[strcat Demo] Constructed Sentence:\n%s\n", description);
                break;
            }

            case 6:
                printf("Exiting Week 7 Supplier Module.\n");
                break;

            default:
                printf("Invalid choice. Enter a number between 1 and 6.\n");
        }

    } while (choice != 6);

    return 0;
}