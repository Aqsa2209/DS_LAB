#include <iostream>
using namespace std;

class BankAccount{
	private:
		double balance;
	public:
		//1. default Constructor
		BankAccount(){
			balance=0.0;
		}
		//2. Parameterized Constructor
		BankAccount(double initial_balance){
			balance= initial_balance;
		}
		//3. Copy Constructor
		BankAccount(const BankAccount &other){
			balance=other.balance;
		}
		// Function to withdraw money
		void withdraw(double amount){
			if(amount<=balance){
				balance -= amount;
			}else{
				cout << "Insufficient balance!" << endl;
			}
		}
		// Function to display balance
		void displayBalance() const {
		cout << "Balance: $" << balance << endl;
		}	
};
int main(){
	// Default constructor called
	BankAccount acc1;
	cout << "Account_1: ";
	acc1.displayBalance();
	
	// Parameterized Constructor called
	BankAccount acc2(2000);
	cout << "Account_2: ";
	acc2.displayBalance();
	
	//Copy Constructor called
	BankAccount acc3(acc2);
	acc3.withdraw(500);
	cout <<"Account3 after withdrawing $500: ";
	acc3.displayBalance();
	return 0;
}
