#include <stdio.h>
#include <string.h>
#include <Common.h>

void Create_Acc(struct bank *bank_user,FILE *ptr){
    static int j=0,i=0;  //representing user index
    struct user m_user;

    line3:
    printf("Enter Your Name :\n");
    fflush(stdin);
    gets(m_user.Name);

    int m=0;
    for(m=0;m<strlen(m_user.Name);m++){
        if((m_user.Name[m]<97 || m_user.Name[m]>122) && (m_user.Name[m]<65 || m_user.Name[m]>92) )
        {
            printf("Invalid Name\n");
            goto  line3;
        }
    }

    line:

    printf("Enter Your Phone Number :\n");
    scanf("%d",&m_user.Phone_No);

    int ph_count =0;
    int ph_temp = m_user.Phone_No;
    while(ph_temp>0)

    {
    ph_count++;
    ph_temp /= 10;
    }

    if(ph_count<10 || ph_count>10){
        printf("Invalid Phone No.\n");
        goto line;
    }

    printf("Enter Your Address :\n");
    fflush(stdin);
    gets(m_user.Addresss);

    line1:

    printf("Enter Aadhar Card Number\n");
    scanf("%lld",&m_user.AdharCard_No);

    int Adar_count = 0;
    long long int Adar_temp = m_user.AdharCard_No;
    while(Adar_temp>0)
    {
    Adar_count++;
    Adar_temp /= 10;
    }
    if(Adar_count<12 || Adar_count>12){
        printf("Invalid Aadhar no .\n");
        goto line1;
    }
line2:

    printf("Enter Account Number:\n");
    scanf("%ld",&m_user.acc1.AC_No);

    int Ac_count = 0;
    int Ac_temp = m_user.acc1.AC_No;
    while(Ac_temp>0)
    {
    Ac_count++;
    Ac_temp /= 10;
    }
    if(Ac_count<10 || Ac_count>10)
    {
        printf("Invalid Account Number \n");
       goto line2;

    }

    rewind(ptr);
    //    while (fscanf(ptr, "%s,%d,%s,%lld,%d,%s,%lf\n",bank_user->u[0].Name,&bank_user->u[0].Phone_No,bank_user->u[0].Addresss,&bank_user->u[0].AdharCard_No,&bank_user->u[0].acc1.AC_No,bank_user->u[0].acc1.acc_type,&bank_user->u[0].acc1.Acc_Bal)!=EOF) {
    while (fscanf(ptr, "%s %d %s %lld %ld %s %lf",bank_user->u[0].Name,&bank_user->u[0].Phone_No,bank_user->u[0].Addresss,&bank_user->u[0].AdharCard_No,&bank_user->u[0].acc1.AC_No,bank_user->u[0].acc1.acc_type,&bank_user->u[0].acc1.Acc_Bal)!=EOF) {

        if(m_user.acc1.AC_No == bank_user->u[0].acc1.AC_No){
            printf("Account Number is already exsits...\n");
            return;
        }
    }
    printf("Enter Account Type:\n");
    printf("1. savings\t 2. current \n");
    int choice;
    scanf("%d",&choice);
    switch (choice) {
    case 1:
        printf("Saving\n");
        strcpy(m_user.acc1.acc_type,"Savings");
        break;
    case 2:
        printf("Current\n");
        strcpy(m_user.acc1.acc_type,"Current");
        break;
    }

    m_user.acc1.Acc_Bal=500;
    printf("Account Initial Balance :%lf\n",m_user.acc1.Acc_Bal);
    printf("\n");
    printf("Your Account is Created Successfully to Our Bank\nHapply Banking \n");
    printf("....................................................\n");
    i++;
    bank_user->u[j]=m_user;
    j++;
    //    fprintf(ptr,"%s,%d,%s,%lld,%d,%s,%lf\n",m_user.Name, m_user.Phone_No,m_user.Addresss,m_user.AdharCard_No,m_user.acc1.AC_No,m_user.acc1.acc_type, m_user.acc1.Acc_Bal);
    fprintf(ptr,"%s %d %s %lld %ld %s %lf\n",m_user.Name, m_user.Phone_No,m_user.Addresss,m_user.AdharCard_No,m_user.acc1.AC_No,m_user.acc1.acc_type, m_user.acc1.Acc_Bal);

}
void Deposit(struct bank *bank_user,FILE *ptr){
    int account_no,deposit_amt,flag=0,count=0,i=0;
    printf("Enter the account_no:\n");
    scanf("%d",&account_no);
    rewind(ptr);

    //    while (fscanf(ptr,"%s,%d,%s,%lld,%d,%s,%lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {
    while (fscanf(ptr,"%s %d %s %lld %ld %s %lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {
        count++;
    }
    struct bank user_arr[count];
    rewind(ptr);

    //    while (fscanf(ptr,"%s,%d,%s,%lld,%d,%s,%lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {
    while (fscanf(ptr,"%s %d %s %lld %ld %s %lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {

        if(account_no == bank_user->u[0].acc1.AC_No){ // No of accounts

            printf("Enter the amount to be deposited to the acc no.: %d\n",bank_user->u[0].acc1.AC_No);
            scanf("%d",&deposit_amt);
            bank_user->u[0].acc1.Acc_Bal += deposit_amt;
            printf("%dRs. Successfully Deposited\n",deposit_amt);
            printf("hi");
            flag = 1;
            strcpy(user_arr[i].u[i].Name,bank_user->u[0].Name);
            user_arr[i].u[i].Phone_No = bank_user->u[0].Phone_No;
            strcpy(user_arr[i].u[i].Addresss,bank_user->u[0].Addresss);
            user_arr[i].u[i].AdharCard_No = bank_user->u[0].AdharCard_No;
            user_arr[i].u[i].acc1.AC_No = bank_user->u[0].acc1.AC_No;
            strcpy(user_arr[i].u[i].acc1.acc_type,bank_user->u[0].acc1.acc_type);
            user_arr[i].u[i].acc1.Acc_Bal = bank_user->u[0].acc1.Acc_Bal;
//            i++;
        }
        strcpy(user_arr[i].u[i].Name,bank_user->u[0].Name);
        user_arr[i].u[i].Phone_No = bank_user->u[0].Phone_No;
        strcpy(user_arr[i].u[i].Addresss,bank_user->u[0].Addresss);
        user_arr[i].u[i].AdharCard_No = bank_user->u[0].AdharCard_No;
        user_arr[i].u[i].acc1.AC_No = bank_user->u[0].acc1.AC_No;
        strcpy(user_arr[i].u[i].acc1.acc_type,bank_user->u[0].acc1.acc_type);
        user_arr[i].u[i].acc1.Acc_Bal = bank_user->u[0].acc1.Acc_Bal;
        i++;
    flag=1;
    }
    if(flag == 0)
    {
        printf("Account not found\n");
        return;
    }
    rewind(ptr);

    for(int i=0;i<count;i++){

        printf("hello");
        //        fprintf(ptr,"%s,%d,%s,%lld,%d,%s,%lf\n" , user_arr[i].u[i].Name,user_arr[i].u[i].Phone_No, user_arr[i].u[i].Addresss, user_arr[i].u[i].AdharCard_No, user_arr[i].u[i].acc1.AC_No, user_arr[i].u[i].acc1.acc_type, user_arr[i].u[i].acc1.Acc_Bal);
        fprintf(ptr,"%s %d %s %lld %ld %s %lf\n" , user_arr[i].u[i].Name,user_arr[i].u[i].Phone_No, user_arr[i].u[i].Addresss, user_arr[i].u[i].AdharCard_No, user_arr[i].u[i].acc1.AC_No, user_arr[i].u[i].acc1.acc_type, user_arr[i].u[i].acc1.Acc_Bal);
    }
}
void Withdraw(struct bank *bank_user,FILE *ptr){
    int account_no,Withdraw_amt,flag=0,count = 0,i=0;
    printf("Enter the account_no:\n");
    scanf("%d",&account_no);
    rewind(ptr);

    //    while (fscanf(ptr,"%s,%d,%s,%lld,%d,%s,%lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {
    while (fscanf(ptr,"%s %d %s %lld %ld %s %lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {
        count++;
    }

//    printf("count %d\n",count);

    struct bank user_arr[count];

    rewind(ptr);

    //    while (fscanf(ptr,"%s,%d,%s,%lld,%d,%s,%lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {
    while (fscanf(ptr,"%s %d %s %lld %ld %s %lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {

        if(account_no == bank_user->u[0].acc1.AC_No){
            printf("Enter the amount to be Withdraw from the acc no.: %d\n",bank_user->u[0].acc1.AC_No);
            scanf("%d",&Withdraw_amt);

            if(bank_user->u[0].acc1.Acc_Bal>=Withdraw_amt)
            {
                bank_user->u[0].acc1.Acc_Bal -= Withdraw_amt;
                printf("%dRs. Successfull Withdraw\n",Withdraw_amt);
                flag = 1;
                strcpy(user_arr[i].u[i].Name,bank_user->u[0].Name);
                user_arr[i].u[i].Phone_No = bank_user->u[0].Phone_No;
                strcpy(user_arr[i].u[i].Addresss,bank_user->u[0].Addresss);
                user_arr[i].u[i].AdharCard_No = bank_user->u[0].AdharCard_No;
                user_arr[i].u[i].acc1.AC_No = bank_user->u[0].acc1.AC_No;
                strcpy(user_arr[i].u[i].acc1.acc_type,bank_user->u[0].acc1.acc_type);
                user_arr[i].u[i].acc1.Acc_Bal = bank_user->u[0].acc1.Acc_Bal;
//                i++;
            }
            else
            {
                printf("Insufficient Balance\n");
                return;
            }
            flag = 1;
        }
        strcpy(user_arr[i].u[i].Name,bank_user->u[0].Name);
        user_arr[i].u[i].Phone_No = bank_user->u[0].Phone_No;
        strcpy(user_arr[i].u[i].Addresss,bank_user->u[0].Addresss);
        user_arr[i].u[i].AdharCard_No = bank_user->u[0].AdharCard_No;
        user_arr[i].u[i].acc1.AC_No = bank_user->u[0].acc1.AC_No;
        strcpy(user_arr[i].u[i].acc1.acc_type,bank_user->u[0].acc1.acc_type);
        user_arr[i].u[i].acc1.Acc_Bal = bank_user->u[0].acc1.Acc_Bal;
//        printf("158\n");
        i++;
        flag = 1;
    }

    rewind(ptr);

    for(int i=0;i<count;i++){
        //        fprintf(ptr,"%s,%d,%s,%lld,%d,%s,%lf\n" , user_arr[i].u[i].Name,user_arr[i].u[i].Phone_No, user_arr[i].u[i].Addresss, user_arr[i].u[i].AdharCard_No, user_arr[i].u[i].acc1.AC_No, user_arr[i].u[i].acc1.acc_type, user_arr[i].u[i].acc1.Acc_Bal);
        fprintf(ptr,"%s %d %s %lld %ld %s %lf\n" , user_arr[i].u[i].Name,user_arr[i].u[i].Phone_No, user_arr[i].u[i].Addresss, user_arr[i].u[i].AdharCard_No, user_arr[i].u[i].acc1.AC_No, user_arr[i].u[i].acc1.acc_type, user_arr[i].u[i].acc1.Acc_Bal);
    }

    if(flag==0){
        printf("Account not found\n");
        //        return;
    }
}

void BalanceCheck(struct bank *bank_user,FILE *ptr){
    int account_no,flag=0;
    printf("Enter the account_no:\n");
    scanf("%d",&account_no);
    rewind(ptr);

    //    while (fscanf(ptr,"%s,%d,%s,%lld,%d,%s,%lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {
    while (fscanf(ptr,"%s %d %s %lld %ld %s %lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {

        if(account_no == bank_user->u[0].acc1.AC_No){
            //            printf("BANK NAME: %s\n",bank_user->m_Bank_Name);
            //            printf("BANK IFSC CODE : %s\n",bank_user->m_Bank_IFSC);
            //            printf("BANK BRANCH : %s\n\n",bank_user->m_Bank_Branch);

            printf("User name: %s\n",bank_user->u[0].Name);
            printf("User phno: %d\n",bank_user->u[0].Phone_No);
            printf("User Adress: %s\n",bank_user->u[0].Addresss);
            printf("User Adhar card no: %lld\n",bank_user->u[0].AdharCard_No);
            printf("User acc type: %s\n",bank_user->u[0].acc1.acc_type);
            printf("User ac no: %ld\n",bank_user->u[0].acc1.AC_No);
            printf("User acc bal: %lf\n",bank_user->u[0].acc1.Acc_Bal);

            printf("__________________________________________________\n");

            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Your Account not found\n");
    }
}


void display(struct bank *bank_user,FILE *ptr){
    rewind(ptr);
    printf("Your Details\n");
    printf("____________________________________________________\n");


    //    char line[100];
    //    char *field;
    //    char fields[7][100];

    //    while (fgets(line, 100, ptr) != NULL) {

    //        field = strtok(line, ",");
    //        int i = 0;
    //        while (field != NULL && i < 7) {
    //            strncpy(fields[i], field, 100 - 1);
    //            field = strtok(NULL, ",");
    //            i++;
    //        }
    //        int phno = atoi(field[1]);
    //        int Adhar_No = atoi(field[3]);
    //        int Ac_No = atoi(field[5]);
    //        int Acc_Bal = atoi(field[6]);


    //    while (fscanf(ptr,"%s,%d,%s,%lld,%d,%s,%lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {

    while (fscanf(ptr,"%s %d %s %lld %ld %s %lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {
        //        printf("BANK NAME: %s\n",bank_user->m_Bank_Name);
        //        printf("BANK IFSC CODE : %s\n",bank_user->m_Bank_IFSC);
        //        printf("BANK BRANCH : %s\n",bank_user->m_Bank_Branch);

        //        printf("\n");

        printf("User name:%s\n",bank_user->u[0].Name);
        printf("User phno:%d\n",bank_user->u[0].Phone_No);
        printf("User Adress:%s\n",bank_user->u[0].Addresss);
        printf("User Adhar card no:%lld\n",bank_user->u[0].AdharCard_No);
        printf("User acc type:%s\n",bank_user->u[0].acc1.acc_type);
        printf("User ac no:%ld\n",bank_user->u[0].acc1.AC_No);
        printf("User acc bal:%lf\n",bank_user->u[0].acc1.Acc_Bal);

        //        printf("User name:%s\n",fields[0]);
        //        printf("User phno:%d\n",phno);
        //        printf("User Adress:%s\n",fields[2]);
        //        printf("User Adhar card no:%lld\n",Adhar_No);
        //        printf("User acc type:%s\n",fields[4]);
        //        printf("User ac no:%d\n",Ac_No);
        //        printf("User acc bal:%lf\n",Acc_Bal);

        printf("____________________________________________________\n");
    }
}


//void DeleteAccount(struct bank *bank_user,FILE *ptr){
//int count=0;
//  int User_AccNo;
//  printf("Enter a Account Number ");
//  scanf("%d", &User_AccNo);

//  rewind(ptr);

//   while (fscanf(ptr,"%s %d %s %lld %d %s %lf" , bank_user->u[0].Name,&bank_user->u[0].Phone_No, bank_user->u[0].Addresss, &bank_user->u[0].AdharCard_No, &bank_user->u[0].acc1.AC_No, bank_user->u[0].acc1.acc_type, &bank_user->u[0].acc1.Acc_Bal)!=EOF) {
//count++;
//  if(User_AccNo!=bank_user->u[0].acc1.AC_No){

//      printf("Deleted account Successfully");
//  }
//   }
// }



