#include <iostream>
using namespace std;


int main() {
    int employeeID, hoursWorked, hourlyRate, taxRate;
//1. Print welcome message
cout << "Welcome to my Weekly Payroll program!!" << endl;
//2. Read employee ID from user
cout << "Enter your employee ID number (numbers only): ";
cin >> employeeID;
//3. Read number of worked from the user
cout << "Enter the hourly rate:";
cin >> hourlyRate;
//4. Read the hourly rate from the user
//5. Read the federal withholding rate
cout << "Enter the federal withholding rate: ";
cin >> taxRate;
//6. Calculate total gross pay
int grossPay = hoursWorked *hourlyRate;
//7. Calculate total federal tax withholding
int taxWithholding = (grossPay*taxRate);
//8. Calculate net pay;
int netPay = (grossPay-taxWithholding);
//9. Output the Payroll Summary (Gross, Tax, Net)
cout << endl << "Your Payroll Summary:" << endl;
cout << "Total Gross Pay: $" << grossPay << endl;
cout << "Federal Tax WithHolding: $" << taxWithholding << endl;
cout << "Net Pay: $" << netPay << endl << endl;
//10. Print goodbye message
cout << "Thank you for using my Weekly Payroll program!!" << endl;
return 0;
}