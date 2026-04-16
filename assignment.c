#include <stdio.h>

int main(){
    double cost, charge, discount, total;
    char name[50], additional, next; // can store up to 49 chars + 0 
    int type, device; 
    printf("Welcome to QuickFix Mobile Repair Centre!\n");
    
    // ask names, services, number services, additional service requirements

    printf("Customer name : ");
    scanf("%s", name); // ask customer name
 
    printf("\nService type? :\n1. Screen Replacement (RM80.00)\n2. Battery Replacement (RM50.00)\n3. Software repair (RM30.00)\n4. Diagnostics (RM10.00)\nChoose : "); // ask service type
    scanf("%d", &type);
    
    switch(type){
        case 1: cost = 80; break;
        case 2 : cost = 50; break;
        case 3 : cost = 30; break;
        case 4 : cost = 10 ; break;
        default : cost = 0; break;
        
    }
    
    // additional charge
    charge += cost;
    printf("\nNumber of services? : \n"); 
    scanf("%d", &device);
    
    printf("Add additional service? (Y/N)\n");
    scanf(" %c", &additional);
    
    // switch case for additional repairs requirement
    
    switch(additional){
        case 'Y':
        case 'y':
        do{
            printf("\nService type? :\n1. Screen Replacement (RM80.00)\n2. Battery Replacement (RM50.00)\n3. Software repair (RM30.00)\n4. Diagnostics (RM10.00)\nChoose : "); // ask service type
            scanf("%d", &type);
            
            printf("Add additional service? (Y/N)\n");
            
            scanf(" %c", &additional);
            
            
        } while (additional=='y' || additional == 'Y');
        
        break;
        
        case 'N':
        case 'n':
        
        // Discount (5%)
        discount = total * 0.5;
        
        // Total payment
        total = (cost * device) + charge - discount;
        
        printf("Additional Charges : %lf\n", &charge);
        printf("Discount (5%) : %lf\n", &discount);
        printf("Total Payment : %lf\n", &total);
        

        printf("\nDaily Summary\n");
        printf("=================\n");
        printf("Customer name : %s\n",&name);
        printf("Total Devices repaired : %d\n",&device);
        printf("Total Repair fees : %lf\n", &total);
        
        default : printf("Invalid");
        
    }
    
}


