// -------------------------- FILE HEADER --------------------------------
// Author: Jared Hillaire
// Assignment: Assignment 6 - Vending Machine
// Date: November 6, 2026
// Citations: Assingment 6 instuctrions and assignment templete.

// -------------------------- CODE----------------------------------------
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Functions prototypes (if any)
// None needed.

int main() {
    // Prices and balances are stored in cents.
    const int COFFEE_PRICE = 25;
    const int TEA_PRICE = 25;

    int coin = 0;
    int quantity = 0;
    int itemPrice = 0;
    long long balance = 0;
    long long total = 0;
    char choice = ' ';
    string itemName = "";
    string extraInput = "";
    bool validInput = false;
    bool inputFailed = false;
    bool finished = false;

    cout << fixed << setprecision(2);
    cout << "Welcome to my Coffee/Tea Vending Machine!" << endl;
    cout << endl;

    while (!finished) {
        // Keep the previous balance when collecting more coins.
                do {
            validInput = false;

            while (!validInput) {
                cout << "Enter coins - 5, 10, or 25 only: ";
                cin >> coin;
                inputFailed = cin.fail();
                cin.clear();
                getline(cin, extraInput);

                // Reject letters, decimals, and extra text.
                validInput = !inputFailed
                    && extraInput.find_first_not_of(" \t\r")
                        == string::npos
                    && (coin == 0 || coin == 5
                        || coin == 10 || coin == 25);

                if (!validInput) {
                    cout << "Invalid coin! Enter 5, 10, 25, "
                         << "or 0 to finish." << endl;
                }
            }

            balance += coin;
        } while (coin != 0);

        cout << endl;
        cout << "Your balance is $" << balance / 100.0 << endl;
        cout << endl;
        cout << "Please pick an option ($0.25 each):" << endl;
        cout << "           C/c: Coffee" << endl;
        cout << "           T/t: Tea" << endl;
        cout << "           Q/q: Quit" << endl;

        validInput = false;
        while(!validInput) {
            cout << ">> ";
            cin >> choice;
            inputFailed = cin.fail();
            cin.clear();
            getline(cin, extraInput);

            validInput = !inputFailed
                && extraInput.find_first_not_of(" \t\r") == string::npos
                && (choice == 'C' || choice == 'c'
                    || choice == 'T' || choice == 't'
                    || choice == 'Q' || choice == 'q');

            if (!validInput) {
                cout << "Invalid Option! Please choose a valid option!"
                     << endl;
            }
                           }
           // Handle quitting or purchasing a drink.
        if (choice == 'Q' || choice == 'q') {
            total = 0;

            cout << endl;
            cout << "Your total is $" << total / 100.0 << endl;
            cout << "Your balance is $" << balance / 100.0 << endl;

            finished = true;
        }
        else {
            // Set the name and price of the selected drink.
            if (choice == 'C' || choice == 'c') {
                itemName = "Coffee";
                itemPrice = COFFEE_PRICE;
            }
            else {
                itemName = "Tea";
                itemPrice = TEA_PRICE;
            }

            // Read and validate the quantity.
            validInput = false;

            while (!validInput) {
                cout << "How many would you like?" << endl;
                cout << ">> ";

                cin >> quantity;
                inputFailed = cin.fail();
                cin.clear();
                getline(cin, extraInput);

                validInput = !inputFailed
                    && extraInput.find_first_not_of(" \t\r")
                        == string::npos
                    && quantity > 0;

                if (!validInput) {
                    cout << "Invalid Option!" << endl;
                }
            }

            // Calculate the total cost in cents.
            total = quantity;
            total *= itemPrice;

            cout << endl;
            cout << "You chose " << itemName << " at $"
                 << itemPrice / 100.0 << " each." << endl;
            cout << "Your total is $" << total / 100.0 << endl;

            // Complete the purchase if enough money is available.
            if (balance >= total) {
                balance -= total;

                cout << "Your balance is $"
                     << balance / 100.0 << endl;

                finished = true;
            }
            else {
                cout << "Your balance is $"
                     << balance / 100.0 << endl;
                cout << "Not enough change!! Please add more coins."
                     << endl;
                cout << endl;
            }
        }
    } // End of the outer while loop.

    cout << endl;
    cout << "Thank you for using my Vending Machine Program!" << endl;

    return 0;
} // End of main.

// ------------- DESIGN -------------
/*
Program Name:
Coffee and Tea Vending Machine

Program Description:
This program collects nickels, dimes, and quarters from the user.
It allows the user to buy coffee or tea for 25 cents per drink, or quit.
The program validates coins, menu choices, and quantities.
If there is not enough money, it keeps the deposited balance and asks
for more coins. The user then chooses a drink and quantity again.
The program ends after a successful purchase or when the user quits.

Design:

A. INPUT

coin (int): Coin value in cents; accept 5, 10, 25, or 0 to stop.
choice (char): C/c for Coffee, T/t for Tea, or Q/q to Quit.
quantity (int): A positive whole number of drinks within the int range.
extraInput (string): Characters left on the line after reading a value.

Input validation also checks inputFailed (bool) and validInput (bool).
The program rejects extra non-whitespace characters on an input line.

B. OUTPUT

Welcome message, coin prompt, menu, and quantity prompt (text).
Validation error messages when an entry is invalid (text).
itemName (string): The selected drink, Coffee or Tea.
itemPrice (int): Price in cents, displayed in dollars.
total (long long): Order cost in cents, displayed in dollars.
balance (long long): Available money in cents, displayed in dollars.
An insufficient-money message when the balance is less than the cost.
A thank-you message when the program ends.

All displayed money amounts have two digits after the decimal point.

C. CALCULATIONS

COFFEE_PRICE (const int) = 25 cents
TEA_PRICE (const int) = 25 cents

balance = previous balance + valid coin
total = quantity * itemPrice
After a successful purchase: balance = balance - total
Displayed dollars = amount in cents / 100.0

The program assigns quantity to the long long total before multiplying.
It does not subtract any money for an unsuccessful order.
On Quit, total is zero and the deposited balance is unchanged.

D. LOGIC AND ALGORITHMS

BEGIN
  SET both drink price constants to 25 cents
  INITIALIZE the coin, quantity, item price, total, and balance to zero
  INITIALIZE the menu choice to a space and both strings to empty
  SET validInput, inputFailed, and finished to false
  SET money output to fixed format with two decimal places
  DISPLAY the welcome message and a blank line

  WHILE finished is false
    DO
      SET validInput to false
      WHILE validInput is false
        PROMPT for a coin and READ coin
        SAVE whether the input operation failed
        CLEAR the input stream error flags
        READ the rest of the line into extraInput
        CHECK that the read succeeded, no unwanted text remains,
          and coin is 0, 5, 10, or 25
        STORE the result of those checks in validInput
        IF validInput is false
          DISPLAY the invalid-coin message
        END IF
      END WHILE
      ADD coin to balance
    WHILE coin is not zero

    DISPLAY balance and the Coffee, Tea, and Quit menu
    SET validInput to false
    WHILE validInput is false
      PROMPT for and READ choice
      SAVE the input failure result, CLEAR the stream error flags,
        and READ the rest of the line
      CHECK that the read succeeded, no unwanted text remains,
        and choice is C, c, T, t, Q, or q
      STORE the result in validInput
      IF validInput is false
        DISPLAY the invalid-menu message
      END IF
    END WHILE

    IF choice is Q or q
      SET total to zero
      DISPLAY total and balance
      SET finished to true
    ELSE
      IF choice is C or c
        SET itemName to Coffee and itemPrice to COFFEE_PRICE
      ELSE
        SET itemName to Tea and itemPrice to TEA_PRICE
      END IF

      SET validInput to false
      WHILE validInput is false
        PROMPT for and READ quantity
        SAVE the input failure result, CLEAR the stream error flags,
          and READ the rest of the line
        CHECK that the read succeeded, no unwanted text remains,
          and quantity is greater than zero
        STORE the result in validInput
        IF validInput is false
          DISPLAY the invalid-quantity message
        END IF
      END WHILE

      CALCULATE total as quantity times itemPrice
      DISPLAY itemName, itemPrice, and total
      IF balance is greater than or equal to total
        SUBTRACT total from balance
        DISPLAY the remaining balance
        SET finished to true
      ELSE
        DISPLAY the unchanged balance
        DISPLAY the message asking for more coins
      END IF
    END IF
  END WHILE

  DISPLAY the thank-you message
END

SAMPLE RUNS

The following sample interactions illustrate the completed test cases.

Test 1 - Required sample: invalid menu and quantity entries

Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.80

Please pick an option ($0.25 each):
           C/c: Coffee
           T/t: Tea
           Q/q: Quit
>> k
Invalid Option! Please choose a valid option!
>> 9
Invalid Option! Please choose a valid option!
>> c
How many would you like?
>> f
Invalid Option!
How many would you like?
>> 2

You chose Coffee at $0.25 each.
Your total is $0.50
Your balance is $0.30

Thank you for using my Vending Machine Program!


Test 2 - Required sample: insufficient funds and a new order

Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.30

Please pick an option ($0.25 each):
           C/c: Coffee
           T/t: Tea
           Q/q: Quit
>> c
How many would you like?
>> 2

You chose Coffee at $0.25 each.
Your total is $0.50
Your balance is $0.30
Not enough change!! Please add more coins.

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.60

Please pick an option ($0.25 each):
           C/c: Coffee
           T/t: Tea
           Q/q: Quit
>> T
How many would you like?
>> 1

You chose Tea at $0.25 each.
Your total is $0.25
Your balance is $0.35

Thank you for using my Vending Machine Program!


Test 3 - Required sample: quit and return the balance

Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.30

Please pick an option ($0.25 each):
           C/c: Coffee
           T/t: Tea
           Q/q: Quit
>> q

Your total is $0.00
Your balance is $0.30

Thank you for using my Vending Machine Program!


Test 4 - Additional test: invalid coins and exact payment

Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 1
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: 50
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: -5
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: abc
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: 5.5
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.25

Please pick an option ($0.25 each):
           C/c: Coffee
           T/t: Tea
           Q/q: Quit
>> c
How many would you like?
>> 1

You chose Coffee at $0.25 each.
Your total is $0.25
Your balance is $0.00

Thank you for using my Vending Machine Program!


Test 5 - Additional test: invalid quantities

Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.50

Please pick an option ($0.25 each):
           C/c: Coffee
           T/t: Tea
           Q/q: Quit
>> t
How many would you like?
>> 0
Invalid Option!
How many would you like?
>> -2
Invalid Option!
How many would you like?
>> 1.5
Invalid Option!
How many would you like?
>> abc
Invalid Option!
How many would you like?
>> 2

You chose Tea at $0.25 each.
Your total is $0.50
Your balance is $0.00

Thank you for using my Vending Machine Program!


Additional uppercase checks:

Test 6: Deposit 25, enter 0, select C, and enter quantity 1.
Result: Coffee, total $0.25, balance $0.00; program ends.

Test 7: Deposit 5, enter 0, and select Q.
Result: Total $0.00, balance $0.05; no quantity prompt; program ends.
*/

END OF DESIGN COMMENT

2. POST DISCUSSION 6

Copy the subject and discussion text below into Discussion 6. The two
sample runs are additional tests beyond the three assignment examples.
Do not include the C++ comment markers in the discussion post.

Subject: Discussion 6 - Additional Vending Machine Tests

For my two additional tests, I checked invalid coins and invalid
quantities. Both tests passed.

Test 1 - Invalid coins and exact payment

I entered 1, 50, -5, abc, and 5.5. The program rejected all five entries
and kept asking for a valid coin. I then deposited 25 cents, entered 0,
selected coffee with lowercase c, and requested one drink. The total
was $0.25 and the remaining balance was $0.00. This checked that invalid
coins were not added to the balance and that exact payment was accepted.

Sample run:

Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 1
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: 50
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: -5
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: abc
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: 5.5
Invalid coin! Enter 5, 10, 25, or 0 to finish.
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.25

Please pick an option ($0.25 each):
           C/c: Coffee
           T/t: Tea
           Q/q: Quit
>> c
How many would you like?
>> 1

You chose Coffee at $0.25 each.
Your total is $0.25
Your balance is $0.00

Thank you for using my Vending Machine Program!

Test 2 - Invalid quantities

I deposited two quarters, entered 0, and selected tea with lowercase t.
For the quantity, I entered 0, -2, 1.5, and abc. The program rejected
each one and asked again. It accepted 2, charged $0.50, and ended with
a $0.00 balance. This checked that the quantity must be a positive
whole number and that the program can recover from letters or decimals.

Sample run:

Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.50

Please pick an option ($0.25 each):
           C/c: Coffee
           T/t: Tea
           Q/q: Quit
>> t
How many would you like?
>> 0
Invalid Option!
How many would you like?
>> -2
Invalid Option!
How many would you like?
>> 1.5
Invalid Option!
How many would you like?
>> abc
Invalid Option!
How many would you like?
>> 2

You chose Tea at $0.25 each.
Your total is $0.50
Your balance is $0.00

Thank you for using my Vending Machine Program!