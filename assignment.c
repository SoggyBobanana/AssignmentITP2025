#include <stdio.h>

int main(){
    double cost = 0, charge = 0, discount = 0, total = 0;
    char name[50], additional;
    int type, device;

    printf("Welcome to QuickFix Mobile Repair Centre!\n");

    // Customer name (with spaces)
    printf("Customer name : ");
    scanf(" %49[^\n]", name);

    // Main service (validated)
    do {
        printf("\nService type?\n");
        printf("1. Screen Replacement (RM80.00)\n");
        printf("2. Battery Replacement (RM50.00)\n");
        printf("3. Software Repair (RM30.00)\n");
        printf("4. Diagnostics (RM10.00)\n");
        printf("Choose: ");
        scanf("%d", &type);

        if(type < 1 || type > 4){
            printf("Invalid choice. Please enter 1–4 only.\n");
        }

    } while(type < 1 || type > 4);

    // Assign cost
    switch(type){
        case 1: cost = 80; break;
        case 2: cost = 50; break;
        case 3: cost = 30; break;
        case 4: cost = 10; break;
    }

    // Number of devices (validated)
    do {
        printf("Number of devices: ");
        scanf("%d", &device);

        if(device <= 0){
            printf("Must be at least 1 device.\n");
        }

    } while(device <= 0);

    // Additional services
    printf("Add additional service? (Y/N): ");
    scanf(" %c", &additional);

    if(additional == 'Y' || additional == 'y'){
        do{
            // Validate service choice
            do {
                printf("\nChoose additional service (1–4): ");
                scanf("%d", &type);

                if(type < 1 || type > 4){
                    printf("Invalid choice. Try again.\n");
                }

            } while(type < 1 || type > 4);

            // Add to additional charge ONLY
            switch(type){
                case 1: charge += 80; break;
                case 2: charge += 50; break;
                case 3: charge += 30; break;
                case 4: charge += 10; break;
            }

            printf("Add more? (Y/N): ");
            scanf(" %c", &additional);

        } while(additional == 'Y' || additional == 'y');
    }

    // Calculation
    total = (cost * device) + charge;
    discount = total * 0.05;
    total -= discount;

    // Output
    printf("\n===== RECEIPT =====\n");
    printf("Customer: %s\n", name);
    printf("Devices repaired: %d\n", device);
    printf("Main service cost: RM %.2lf\n", cost * device);
    printf("Additional charges: RM %.2lf\n", charge);
    printf("Discount (5%%): RM %.2lf\n", discount);
    printf("Total payment: RM %.2lf\n", total);

    return 0;
}