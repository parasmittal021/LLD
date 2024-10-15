#include<iostream>
#include<string>
using namespace std;    

class BankAccount {
    public:
        virtual void checkBalance() = 0;
        virtual void modifyBalance(int amount) = 0;
        virtual ~BankAccount() {}
};

class RealAccount: public BankAccount {
    int balance;
    public:
        RealAccount(int balance) {
            this->balance = balance;
        }
    protected:
        void checkBalance() {
            cout <<"Checking balance: "<<balance<<endl;
        }
        void modifyBalance(int amount) {
            cout<<"Modifying balance by "<<amount<<endl;
        }
};

class AccountProxy: public BankAccount  {
    private:
        BankAccount* account;
        string role;
    public:
        AccountProxy(BankAccount* account, string role) {
            this->account = account;
            this->role = role;
        }
        void checkBalance() {
            account->checkBalance();
        }
        void modifyBalance(int amount) {
            if(role == "Admin") {
               account->modifyBalance(amount);
            } else {
                 cout<<"Access denied"<<endl;
            }
        } 
};

int main() {
    BankAccount* realAccount = new RealAccount(50);
    BankAccount* accountWithUserRole = new AccountProxy(realAccount, "User");
    BankAccount* accountWithAdminRole = new AccountProxy(realAccount, "Admin");
    accountWithUserRole->checkBalance();
    accountWithUserRole->modifyBalance(20);
    accountWithAdminRole->checkBalance();
    accountWithAdminRole->modifyBalance(20);
    return 0;
}