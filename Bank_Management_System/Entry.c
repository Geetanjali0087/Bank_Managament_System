#include <stdio.h>
#include <stdlib.h>
#include "Common.h"


void Create_Acc(struct bank *bank,FILE *);
void display(struct bank *bank,FILE *);
void BalanceCheck(struct bank *bank,FILE *);
void Deposit(struct bank *bank,FILE *);
void Withdraw(struct bank *bank,FILE *);
//void DeleteAccount(struct bank *bank,FILE *);

enum name{
    Create_Account=1, Display_All_Acc_Details, Balance_Check, Deposit_Money,Withdraw_Money, exits
};

void start()
{
    printf("\t\t\t ..........WELCOME TO THE BANK...........\n");

    struct bank Bank1;
//   strcpy(Bank1.m_Bank_Name,"Jai Shree Ram Bank");
//   strcpy(Bank1.m_Bank_IFSC,"JSR0004289");
//   strcpy(Bank1.m_Bank_Branch,"RR Nagar");

    FILE *ptr;
    ptr=fopen("bank.txt","r+");


//        ptr=fopen("C:\\Users\\LENOVO\\Desktop\\Bank.csv","w+");

    if(ptr==NULL){
        printf("File is not present");
    }

    while (1)
    {
        int choice;
        printf("\tOPTIONS.\n\n");
        printf(" 1. Create An Account \n 2. Display all acc Details \n 3. Balance Check  \n 4. Deposit \n 5. Withdraw \n 6. Exit \n");
        printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("Enter Your Choice :");
        scanf("%d", &choice);

        switch (choice) {
        case Create_Account:
            Create_Acc(&Bank1,ptr); //write
            break;
        case Display_All_Acc_Details:
            display(&Bank1,ptr);
            break;
        case Balance_Check:
            BalanceCheck(&Bank1,ptr);
            break;
        case Deposit_Money:
            Deposit(&Bank1,ptr);
            break;
        case Withdraw_Money:
            Withdraw(&Bank1,ptr);
            break;
        case exits:
            fclose(ptr);
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
}

