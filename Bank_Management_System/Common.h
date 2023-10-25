#ifndef COMMON_H
#define COMMON_H


struct Account{
    long int AC_No;
    char acc_type[20];
    double Acc_Bal;
};
struct user{
    char Name[20];
    int Phone_No;
    char Addresss[20];
    long long int AdharCard_No;

    struct Account acc1;
};

struct bank{
//    char m_Bank_Name[20];
//    char m_Bank_IFSC[20];
//    char m_Bank_Branch[30];

    struct user u[10];
};


#endif // COMMON_H
