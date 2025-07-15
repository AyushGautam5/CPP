/*

Encapsulation: it means bundling data (variables) and methods (functions) that operate on the data into a single unit (usually a class) and restricting direct access to some components.

-> har cheez to ko ek saath rakna (ek capsule me)
-> Important data members(variables) cannot be modified or acces directly
-> can be access through various methods(getter and setter)

*/

#include<iostream>
using namespace std;

class BankAccount{
    private:
        string accountNumber;
        double balance;

    public:
        BankAccount(string accNum, double initialBalance){
            accountNumber = accNum;
            balance = initialBalance;
            cout << "BankAccount Created constructor called" << "\n";
        }

        //getter
        double displayBalance(){
            return balance;
        }
        
        // Method to deposit Money
        void depositMoney(double amount){
            if(amount > 0){
                balance += amount;
            }
            else{
                cout << "Invalid amount" << "\n";
            }
        }

        //Method to withdrawl Money
        void withdrawlMoney(double amount){
            if((amount > 0) && (amount <= balance)){
                balance -= amount;
                cout << "Withdrawl Money : " << amount << "\n";
            }
            else{
                cout << "Invalid amount" << "\n";
            }
        }
        
};

int main(){

    BankAccount myAccount("930831", 5000);

    cout << myAccount.displayBalance() << "\n";
    myAccount.depositMoney(1000);
    cout << myAccount.displayBalance() << "\n";
    myAccount.withdrawlMoney(500);
    cout << myAccount.displayBalance() << "\n";
    myAccount.withdrawlMoney(10000);
    cout << myAccount.displayBalance() << "\n";

    return 0;
}