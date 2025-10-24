#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MIN 5 
#define MAX 15
int stock_exit=0;
float price_gf= 4.0;
float price_lc= 3.5;
float price_s= 2.5; //The price of each item
int Stock_GF = 5, Stock_LC = 5, Stock_S = 5;  //The total number of each item
bool a_GF=1, a_LC=1, a_S=1; //Availability of each item (Yes=1/No=0)
int Internal_Choice;
int mode;
int Final;
float coins = 0.0;
int Password=12345;
int I_Password;
bool breaker=true;
float total_amount=0.0;
float balance = 0.0;
void consumer_mode ();
void payment_mode(int y){ //All Processes of Payment
    const float EPS = 0.0001f;
    // Unified payment flow: decrement stock at start, set balance to price,
    // loop prompting for coins (accept 1 or 0.5), subtract, handle exact success.
    switch (y){
    case 1: {
        /* Galaxy Flutes */
        Stock_GF -= 1;               /* reserve item */
        balance = price_gf;         /* reset balance to product price */
        while (1){
            if (balance > EPS){
                 
                printf("To Pay: %-8.2f", balance);
                printf("Enter Coins(1/0.5):");
                if (scanf("%f", &coins) != 1){
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) { }
                    printf("Invalid input. Please enter 1 or 0.5.\n");
                     
                    continue;
                }
                if (fabsf(coins - 1.0f) < EPS || fabsf(coins - 0.5f) < EPS){
                    balance -= coins;
                    if (balance > EPS) continue;
                    if (fabsf(balance) < EPS){
                        /* success */
                        printf("Item successfully paid for, Dropping Galaxy Flutes into Chute.\n");
                         
                        printf("Collect Item from chute\n");
                        total_amount += price_gf;
                        printf("Returning to Item List\n");
                         
                         
                        break;
                    }
                    /* overpay (negative balance) */
                } else {
                    printf("Invalid coin. Only 1 or 0.5 accepted.\n");
                     
                    continue;
                }
            }
            /* If we reach here, balance is negative (overpay) - ask user to try again or cancel */
            printf("Invalid Coin Entry\n");
            printf("Would you like to cancel selection or return the coin and try again?(Try Again=1/Cancel Selection=-1)");
            if (scanf("%d", &Internal_Choice) != 1){
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) { }
                continue;
            }
            if (Internal_Choice == 1){
                printf("Returning Coins\n");
                balance += coins; /* return last coin */
                 
                continue;
            } else if (Internal_Choice == -1){
                Stock_GF += 1; /* restore reserved item */
                printf("Cancelling Selection\n");
                printf("Returning to Item List\n");
                 
                 
                break;
            } else {
                printf("Invalid Selection\n");
            }
        }
        break;
    }
    case 2: {
        /* Lays Chilli */
        Stock_LC -= 1;
        balance = price_lc;
        while (1){
            if (balance > EPS){
                 
                printf("To Pay: %-8.2f", balance);
                printf("Enter Coins(1/0.5):");
                if (scanf("%f", &coins) != 1){
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) { }
                    printf("Invalid input. Please enter 1 or 0.5.\n");
                     
                    continue;
                }
                if (fabsf(coins - 1.0f) < EPS || fabsf(coins - 0.5f) < EPS){
                    balance -= coins;
                    if (balance > EPS) continue;
                    if (fabsf(balance) < EPS){
                        printf("Item successfully paid for, Dropping Lays Chilli into Chute.\n");
                         
                        printf("Collect Item from chute\n");
                        total_amount += price_lc;
                        printf("Returning to Item List\n");
                         
                         
                        break;
                    }
                } else {
                    printf("Invalid coin. Only 1 or 0.5 accepted.\n");
                     
                    continue;
                }
            }
            printf("Invalid Coin Entry\n");
            printf("Would you like to cancel selection or return the coin and try again?(Try Again=1/Cancel Selection=-1)");
            if (scanf("%d", &Internal_Choice) != 1){
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) { }
                continue;
            }
            if (Internal_Choice == 1){
                printf("Returning Coins\n");
                balance += coins;
                 
                continue;
            } else if (Internal_Choice == -1){
                Stock_LC += 1;
                printf("Cancelling Selection\n");
                printf("Returning to Item List\n");
                 
                 
                break;
            } else {
                printf("Invalid Selection\n");
            }
        }
        break;
    }
    case 3: {
        /* Sprite */
        Stock_S -= 1;
        balance = price_s;
        while (1){
            if (balance > EPS){
                 
                printf("To Pay: %-8.2f", balance);
                printf("Enter Coins(1/0.5):");
                if (scanf("%f", &coins) != 1){
                    int ch;
                    while ((ch = getchar()) != '\n' && ch != EOF) { }
                    printf("Invalid input. Please enter 1 or 0.5.\n");
                     
                    continue;
                }
                if (fabsf(coins - 1.0f) < EPS || fabsf(coins - 0.5f) < EPS){
                    balance -= coins;
                    if (balance > EPS) continue;
                    if (fabsf(balance) < EPS){
                        printf("Item successfully paid for, Dropping Sprite into Chute.\n");
                         
                        printf("Collect Item from chute\n");
                        total_amount += price_s;
                        printf("Returning to Item List\n");
                         
                         
                        break;
                    }
                } else {
                    printf("Invalid coin. Only 1 or 0.5 accepted.\n");
                     
                    continue;
                }
            }
            printf("Invalid Coin Entry\n");
            printf("Would you like to cancel selection or return the coin and try again?(Try Again=1/Cancel Selection=-1)");
            if (scanf("%d", &Internal_Choice) != 1){
                int ch;
                while ((ch = getchar()) != '\n' && ch != EOF) { }
                continue;
            }
            if (Internal_Choice == 1){
                printf("Returning Coins\n");
                balance += coins;
                 
                continue;
            } else if (Internal_Choice == -1){
                Stock_S += 1;
                printf("Cancelling Selection\n");
                printf("Returning to Item List\n");
                 
                 
                break;
            } else {
                printf("Invalid Selection\n");
            }
        }
        break;
    }
    }
}
void stock_check(int x){ //All Instances of Checking for Stock
    switch (x){
    case 1:
    if (Stock_GF==0){
        a_GF=0;
        printf("Item Not Available\n");
        break;
    }
    else if (Stock_GF<5){
        printf("Stock is running low, inform Admin to restock\n");
        break;
    }
    else{
        printf("\n");
        break;
    }
    case 2:
    if (Stock_LC==0){
        a_LC=0;
        printf("Item Not Available\n");
        break;
    }
    else if (Stock_LC<5){
        printf("Stock is running low, inform Admin to restock\n");
        break;
    }
    else{
        printf("\n");
        break;
    }
    case 3:
    if (Stock_S==0){
        a_S=0;
        printf("Item Not Available\n");
        break;
    }
    else if (Stock_S<5){
        printf("Stock is running low, inform Admin to restock\n");
        break;
    }
    else{
        printf("\n");
        break;
    }
    }
}
void admin_mode(){//All Admin Mode Operations
    int admin_choice;
    printf("Welcome Admin\n");
    while (breaker){
         
        printf("0) Exit Admin Mode\n");
        printf("1) Replenish Stock\n");
        printf("2) Change Product Prices\n");
        printf("3)Display Total Sales Today\n");
        printf("4)Display Current Stock\n");
        printf("Make Your Selection: ");
        scanf("%d",&admin_choice);
        switch (admin_choice){
            case 0:
            int exit_status;
            printf("Confirm Exiting Admin Mode(Yes=1/No=-1) ");
            scanf("%d",&exit_status);
            if (exit_status==1){
                printf("Exiting Admin Mode\n");
                 
                 
                breaker=false;
            }
            else if (exit_status==-1){
                printf("Returning to Admin List\n");
                 
                 
            }
            break;
            case 1:
            Stock_GF = (rand()%(MAX-MIN+1)+MIN);//Replenish Stock of Item A
            Stock_LC = (rand()%(MAX-MIN+1)+MIN);//Replenish Stock of Item B
            Stock_S = (rand()%(MAX-MIN+1)+MIN);//Replenish Stock of Item C
            printf("Stock Replenished\n");
             
            printf("Returning to Admin Operations\n");
             
             
            break;
            case 2:
            int change_price;
            float temp_price;
            printf("1)Galaxy Flutes\n");
            printf("2)Lays Chilli\n");
            printf("3)Sprite\n");
            printf("Enter Item Number to change price: ");
            scanf("%d",&change_price);
            switch (change_price){
                case 1:
                printf("Current Price: %-8.2f, Enter New Price: ",price_gf);
                scanf("%f",&temp_price);
                price_gf=temp_price;
                printf("Price Updated. Current Price: %-8.2f",price_gf);
                printf("Returning to Admin Mode\n");
                 
                 
                break;
                case 2:
                printf("Current Price: %-8.2f, Enter New Price: ",price_lc);
                scanf("%f",&temp_price);
                price_lc=temp_price;
                printf("Price Updated. Current Price: %-8.2f",price_lc);
                printf("Returning to Admin Mode\n");
                 
                 
                break;
                case 3:
                printf("Current Price: %-8.2f, Enter New Price: ",price_s);
                scanf("%f",&temp_price);
                price_s=temp_price;
                printf("Price Updated. Current Price: %-8.2f",price_s);
                printf("Returning to Admin Mode\n");
                 
                 
                break;
            }
            break;
            case 3:
            printf("Total Sales Today is: %-8.2f",total_amount);
            printf("Returning to Admin Operations in 3 Seconds");
             
             
            break;
            case 4:
            printf("Number of Galaxy Flutes in Stock: %-8i\n",Stock_GF);
            printf("Number of Lays Chilli in Stock: %-8i\n",Stock_LC);
            printf("Number of Sprite in Stock: %-8i\n",Stock_S);
            printf("Enter 1 to Exit Display Stock");
            scanf("%d",&stock_exit);
            if (stock_exit==1){
                printf("Returning to Admin Operations\n");

            }
            break;
        }
        if (admin_choice<0 || admin_choice>4){
            printf("Invalid Selection\n");
            printf("Returning to Admin Operations\n");
        }

    }
}
int main (void){//Main Loop of Operations
    srand( time(NULL) ); // TO SEED THE RANDOM NUMBER GENERATOR, FOR STOCK PURPOSES
   while (breaker){
       printf("1)Consumer Mode\n2)Admin Mode\n3)Exit\nEnter respective numbers :\n"); //Iitial Choice for the Main Menu
       scanf("%d",&mode);
       switch (mode){
            case 1 :
            printf("Proceeding to Consumer Mode\n");
             
             
            consumer_mode();
            breaker=true;
            break;
            case 2 :
            printf("Enter Password: \n");
            scanf("%d",&I_Password);
            if (I_Password == Password){
                printf("Proceeding to Admin Mode\n");
                 
                 
                admin_mode();
                breaker=true;
                break;
            }
            else{
             printf("Password Incorrect, Returning to Main Menu\n");
              
              
             break;
            }
            case 3:
            printf("Confirm Exit(Doing so will reset all the information in this vending machine atm) (1=Yes/Any Number=No)");
            scanf("%d",&Final);
            if (Final==1){
                printf("Closing System.\n See you next time User )");
                 
                 
                breaker=false;
                break;
            }
            else if(Final!=0){
                printf("Returning to Main Menu\n");
                 
                 
                break;
            }
       }
   }
}
void consumer_mode(){ // All Processes inside Consumer Mode
    int finalize; // to confirm selection
   while (breaker){
       int P_Choice=0;
       printf("Select Your Operation\n");
       printf("0) Exit Consumer Mode\n");
       printf("1)Buy Galaxy Flutes\n");
       stock_check(1);                      
       printf("2)Buy Lays Chilli\n");
       stock_check(2);
       printf("3)Buy Sprite\n");
       stock_check(3);
       printf("Enter Selection: ");
       scanf("%d",&P_Choice);
       switch (P_Choice){
        case 0:
         
        printf("You are going to exit Consumer Mode. Confirm Selection(1/-1) ");
        scanf("%d",&P_Choice);
        if (P_Choice==1){
            printf("Exiting Consumer Mode\n");
             
            printf("Returning to Main Menu\n");
             
             
            breaker=false;
            break;
        }
        else if (P_Choice==-1){
            printf("Returning to Item List\n");
             
             
            break;
        }

       case 1:
        
       printf("Your Choice: Galaxy FLutes\n");
       if (a_GF==0){
        printf("Item Not Available, Please contact Admin for Restock\n");
         
         
       }
       else{
        printf("Confirm Selection (Yess=1/No=-1)");
        scanf("%d",&finalize);
        if (finalize==-1){
            printf("Selection Cancelled, Returning to Item List\n");
             
             
        }
        else{
        payment_mode(1);
        }
       }
       break;
       case 2:
        
       printf("Your Choice: Lays Chilli\n");
       if (a_LC==0){
        printf("Item not available, Please contact admin for Restock\n");
         
         
       }
       else{
        printf("Confirm Selection (Yess=1/No=-1)");
        scanf("%d",&finalize);
        if (finalize==-1){
            printf("Selection Cancelled, Returning to Item List\n");
             
             
        }
        else{
        payment_mode(2);
        }
       }
       break;
       case 3:
        
       printf("Your Choice: Sprite\n");
       if (a_S==0){
        printf("Item not available, Please contact admin for Restock\n");
         
         
       }
       else{
        printf("Confirm Selection (Yess=1/No=-1)");
        scanf("%d",&finalize);
        if (finalize==-1){
            printf("Selection Cancelled, Returning to Item List\n");
             
             
        }
        else{
        payment_mode(3);
        }
       }
       break;
       }
       if (P_Choice>3 || P_Choice<0){
        printf("Invalid Input, Returning to Item List\n");
         
         
       }
   }
}
