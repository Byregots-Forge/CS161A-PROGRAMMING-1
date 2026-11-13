// ------------- FILE HEADER -------------
// Author: Jared Hillaire
// Assignment:Assignment 5 - Pizza Party
// Date: November 12-13, 2026
// Citations: Assignment 5 instructions and instructor-provided templet.
// ChatGPT helped with pseudocode and checked calculations


// ------------- CODE -------------
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function prototypes (if any)
// None needed.


// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
int main() {
    // Constants: Values that stay the same throughout the program.

    const int SLICES_PER_PIZZA = 8;
    const double TAX_RATE = 0.07;
    const double DELIVERY_RATE = 0.20;

    // Input variables for one party.
    int people = 0;
    double slicesPerPerson = 0.0;
    double pizzaPrice = 0.0;
    char enterMore = 'n';

    // Calculated Values for one party.
    int pizzasNeeded = 0;
    double pizzaCost = 0.0;
    double tax = 0.0;
    double delivery = 0.0;
    double partyTotal = 0.0;

    // Accumulators: running totals for all parties.
    int enteryCount = 0;
    int totalPizzas = 0;

    // Track combined costs as requested in the assignment's purpose.
    // the samples final summary does not display this combined cost.
    double totalCostAllParties = 0.0;

    // Summary Statistics/
    double averagePizzas = 0.0;
    int maxPeople = 0;
    double maxPartyCost = 0.0;

    // Welcome message.
    cout << "Welcome to my Pizza Party Statistics program!" << endl;
    cout << endl;

    // Display money with two digits after the decimal point.
    cout << fixed << setprecision(2);

    // a do-while loop processes at least one party.
    do {
        //read all three calues from the same input prompt.
        cout << "Enter the number of people, average number of slices per person, "
             << "and the cost of a pizza separated by a space: ";

        cin >> people >> slicesPerPerson >> pizzaPrice;
        cout << endl;

        // Calculate pizzas and round up to a whole pizza.
        // static_cast<int> converts the rounded result to an integer.
        pizzasNeeded = static_cast<int>(
            ceil(people * slicesPerPerson / SLICES_PER_PIZZA));
        
        // Calculate charges without rounding intermediate values.
        pizzaCost = pizzasNeeded * pizzaPrice;
        tax = pizzaCost * TAX_RATE;
        delivery = (pizzaCost + tax) * DELIVERY_RATE;
        partyTotal = pizzaCost + tax + delivery;

        // Add this party's inforation to the running totals.
        enteryCount = enteryCount + 1;
        totalPizzas = totalPizzas + pizzasNeeded;
        totalCostAllParties = totalCostAllParties + partyTotal;

        // Update the largest attendance seen so far.
        if (people > maxPeople) {
            maxPeople = people;
        }

        // Update the largest party cost seen so far.
        if (partyTotal > maxPartyCost) {
            maxPartyCost = partyTotal;
        }

        // Display this party's results.
        cout << "Number of pizzas: " << pizzasNeeded << endl;
        cout << "Cost of pizzas:  $" << pizzaCost << endl;
        cout << "Tax:             $" << tax << endl;
        cout << "Delivery:        $" << delivery << endl;
        cout << "Total Cost:      $" << partyTotal << endl;
        cout << endl;

        // Ask whether to process another party.
        cout << "Do you want to enter more (y/n): ";
        cin >> enterMore;
        cout << endl;

    } while (enterMore == 'y' || enterMore == 'Y');

    // Convert to double before division to preserve the decimal part.
    averagePizzas = static_cast<double>(totalPizzas) / enteryCount;

    // Display the final statistics.
    cout << "Number of entries: " << enteryCount << endl;
    cout << "Total number of pizzas: " << totalPizzas << endl;

    cout << "Average number of pizzas: "
         << setprecision(1) << averagePizzas << endl;

    cout << "Maximum number of people: " << maxPeople << endl;

    // Switch back to two decimal places for money.
    cout << "Maximum cost of pizzas: $"
         << setprecision(2) << maxPartyCost << endl;
         
    cout << endl;
    cout << "Thank you for using my program!" << endl;


    return 0;
}

// Function implementations (if any)
// None Needed


// ------------- DESIGN -------------
/* 
Program Name: Pizza Party Statistics

Program Description:
This program calculates the pizzas and charges for one or more
pizza parties. Each party has a number of people, an average number
of slices per person, and a price per pizza.

The program rounds up the number of pizzas, calculates sales tax
and delivery, and displays the total cost for each party.

After the user finishes, the program displays the number of entries,
total pizzas, average pizzas per party, maximum attendance, and
maximum total cost for a single party.

The program assumes valid, nonnegative numeric input and a y/n
response when asked whether to continue.


A. INPUT

people
  Data type: int
  Number of people attending the current party.

slicesPerPerson
  Data type: double
  Average number of slices each person will eat.

pizzaPrice
  Data type: double
  Price of one pizza.

enterMore
  Data type: char
  User's answer about entering another party.
  Either 'y' or 'Y' continues the loop.


B. OUTPUT

Per-party output:

pizzasNeeded
  Data type: int
  Number of whole pizzas needed for the current party.

pizzaCost
  Data type: double
  Cost of the pizzas before tax and delivery.

tax
  Data type: double
  Sales tax for the current party.

delivery
  Data type: double
  Delivery charge based on pizza cost plus tax.

partyTotal
  Data type: double
  Total cost including pizzas, tax, and delivery.

Final statistics:

entryCount
  Data type: int
  Number of parties entered.

totalPizzas
  Data type: int
  Total number of pizzas for all parties.

averagePizzas
  Data type: double
  Average number of pizzas per party.

maxPeople
  Data type: int
  Largest number of people entered for a single party.

maxPartyCost
  Data type: double
  Largest total cost, including tax and delivery, for a single party.

Money displays two decimal places.
The average number of pizzas displays one decimal place.

The program also displays a welcome message, input prompts,
a continuation prompt, and a goodbye message.


C. CALCULATIONS

Constants:

SLICES_PER_PIZZA = 8
TAX_RATE = 0.07
DELIVERY_RATE = 0.20

Per-party calculations:

1. Total slices needed:
   people * slicesPerPerson

2. Whole pizzas needed:
   pizzasNeeded =
     integer conversion of ceil(total slices needed / SLICES_PER_PIZZA)

3. Pizza cost:
   pizzaCost = pizzasNeeded * pizzaPrice

4. Sales tax:
   tax = pizzaCost * TAX_RATE

5. Delivery:
   delivery = (pizzaCost + tax) * DELIVERY_RATE

6. Total party cost:
   partyTotal = pizzaCost + tax + delivery

Running totals:

7. Count each party:
   entryCount = entryCount + 1

8. Add pizzas to the accumulator:
   totalPizzas = totalPizzas + pizzasNeeded

9. Add party cost to the cost accumulator:
   totalCostAllParties = totalCostAllParties + partyTotal

   totalCostAllParties is a double.
   It tracks combined costs internally.
   It is not displayed because the required sample summary does
   not include a combined cost for all parties.

Maximum values:

10. If people is greater than maxPeople:
    Replace maxPeople with people.

11. If partyTotal is greater than maxPartyCost:
    Replace maxPartyCost with partyTotal.

Final average:

12. averagePizzas =
      totalPizzas converted to double / entryCount

Do not round intermediate monetary calculations.
Format monetary values to two decimal places when displaying them.


D. LOGIC AND ALGORITHMS

BEGIN

  Define constants for slices per pizza, tax rate, and delivery rate.

  Initialize input and calculated numeric variables to zero.
  Initialize the continuation response to 'n'.

  Initialize entry count, total pizzas, and combined party costs to zero.
  Initialize maximum people and maximum party cost to zero.

  Display the welcome message.
  Set decimal output formatting to two decimal places.

  DO

    Prompt for people, average slices per person, and price per pizza.
    Read the three values separated by spaces.

    Calculate total slices needed.
    Divide total slices by slices per pizza.
    Round the result upward and convert it to an integer.

    Calculate pizza cost.
    Calculate sales tax.
    Calculate delivery from pizza cost plus tax.
    Calculate total party cost.

    Increase the entry count by one.
    Add this party's pizzas to the total pizza accumulator.
    Add this party's total cost to the combined cost accumulator.

    IF this party's attendance is greater than the maximum attendance
      Replace the maximum attendance with this party's attendance.
    END IF

    IF this party's total cost is greater than the maximum party cost
      Replace the maximum party cost with this party's total cost.
    END IF

    Display pizzas needed.
    Display pizza cost, tax, delivery, and total party cost.

    Ask whether the user wants to enter another party.
    Read the user's response.

  WHILE the response is 'y' OR 'Y'

  Calculate average pizzas using decimal division.

  Display the number of entries.
  Display the total number of pizzas.
  Display the average number of pizzas with one decimal place.
  Display maximum attendance.
  Display maximum party cost with two decimal places.

  Display the goodbye message.

END


SAMPLE RUNS

The following is the EXPECTED sample supplied in the assignment.
It is not a recorded execution of this program.
User input is shown after each prompt.

Welcome to my Pizza Party Statistics program!

Enter the number of people, average number of slices per person, and the cost of a pizza separated by a space: 10  2.6  10.50

Number of pizzas: 4
Cost of pizzas:  $42.00
Tax:             $2.94
Delivery:        $8.99
Total Cost:      $53.93

Do you want to enter more (y/n): y

Enter the number of people, average number of slices per person, and the cost of a pizza separated by a space: 9   2.5   10.95

Number of pizzas: 3
Cost of pizzas:  $32.85
Tax:             $2.30
Delivery:        $7.03
Total Cost:      $42.18

Do you want to enter more (y/n): y

Enter the number of people, average number of slices per person, and the cost of a pizza separated by a space: 14   3.2   14.95

Number of pizzas: 6
Cost of pizzas:  $89.70
Tax:             $6.28
Delivery:        $19.20
Total Cost:      $115.17

Do you want to enter more (y/n): n

Number of entries: 3
Total number of pizzas: 13
Average number of pizzas: 4.3
Maximum number of people: 14
Maximum cost of pizzas: $115.17

Thank you for using my program!


ADDITIONAL PLANNED TESTS

These are expected results, not recorded program runs.

Test 1: Exactly one pizza and one party.

Input:
4 2.0 10.00
n

Expected party results:
Number of pizzas: 1
Cost of pizzas:  $10.00
Tax:             $0.70
Delivery:        $2.14
Total Cost:      $12.84

Expected summary:
Number of entries: 1
Total number of pizzas: 1
Average number of pizzas: 1.0
Maximum number of people: 4
Maximum cost of pizzas: $12.84


Test 2: Slightly more than one pizza is needed.

Input:
4 2.1 10.00
n

Expected party results:
Number of pizzas: 2
Cost of pizzas:  $20.00
Tax:             $1.40
Delivery:        $4.28
Total Cost:      $25.68

Expected summary:
Number of entries: 1
Total number of pizzas: 2
Average number of pizzas: 2.0
Maximum number of people: 4
Maximum cost of pizzas: $25.68


Test 3: Maximum attendance and maximum cost occur at different parties.

Input:
20 1.0 5.00
y
2 4.0 30.00
n

Expected first party:
Number of pizzas: 3
Cost of pizzas:  $15.00
Tax:             $1.05
Delivery:        $3.21
Total Cost:      $19.26

Expected second party:
Number of pizzas: 1
Cost of pizzas:  $30.00
Tax:             $2.10
Delivery:        $6.42
Total Cost:      $38.52

Expected summary:
Number of entries: 2
Total number of pizzas: 4
Average number of pizzas: 2.0
Maximum number of people: 20
Maximum cost of pizzas: $38.52

*/