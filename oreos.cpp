// ---------------------- File Header -----------------------------
// Author: Jared Hillaire
// Assignment: Assignment 2 - How many calories?
// Date: October 22, 2026
// Citations: OpenAI ChatGPT and Google Gemini
// AI assistance covered writing, understanding, and testing the code,
// including terminology and explanations.
// I typed the code myself with AI assistance and explanations.

#include <iostream>
#include <iomanip>

using namespace std;

// Read the number of Oreos eaten, calculate servings and calories,
// and display the results with one decimal place.
int main() {
    const int COOKIES_PER_SERVING = 5;
    const int CALORIES_PER_SERVING = 160;

    int cookiesEaten = 0;
    double servingsEaten = 0.0;
    double caloriesConsumed = 0.0;

    cout << "Welcome to the Oreo Calculator!\n\n";
    cout << "Enter the number of Oreos eaten: ";
    cin >> cookiesEaten;
    cout << endl;
    servingsEaten = static_cast<double> (cookiesEaten) / COOKIES_PER_SERVING;
    caloriesConsumed = servingsEaten * CALORIES_PER_SERVING;
    cout << fixed << setprecision (1);
    cout << cookiesEaten << " Oreos equals " << servingsEaten
         << " servings!" << endl;
    cout << "You consumed " << caloriesConsumed << " calories." << endl;

    cout << endl << "Keep eating Oreos!" << endl;

    return 0;
}
    // ------------- DESIGN ------------- 
    /* 
    // Program Name:
    Oreo Calculator

    //Program Description:
    //Calculate servings and calories from the number of Oreos eaten.

    //Design:
    //A. INPUT
    //cookiesEaten: int - the number of whole cookies eaten.

    //B. OUTPUT
    //servingsEaten: double - the number of servings eaten.
    //caloriesConsumed: double - the total calories consumed.
    //Both results are displayed with one decimal place.

    //C. Calculations
    //COOKIES_PER_SERVING = 5
    //CALORIES_PER_SERVING =160

    //ServingsEaten = cookie count converted to double / COOKIES_PER_SERVING
    //caloriesConsumed = servingsEaten * CALORIES_PER_SERVING

    //D. LOGIC and ALGORITHMS
    //Set cookies per serving to 5.
    //Set calories per serving to 160
    //Display a welcome message.
    //Ask for and read the number of whole cookies eaten.
    //Convert the cookie count to double and divide by cookies per serving.
    //Store the result as servings eaten.
    //Multiply servings eaten by calories per serving.
    //Store results as calories consumed.
    //Display servings and calories with one decimal place
    //Display a goodbye message.

    //SAMPLE RUNS

    Sample 1:
    Welcome to the Oreo Calculator!

    Enter the number of Oreos eaten: 12

    12 Oreos equals 2.4 servings!
    You consumed 384.0 calories.

    Keep eating Oreos!

    Sample 2:
    Welcome to the Oreo Calculator!

    Enter the number of Oreos eaten: 3

    3 Oreos equals 0.6 servings!
    You consumed 96.0 calories.

    Keep eating Oreos!

    Sample 3: 
    Welcome to the Oreo Calculator!

    Enter the number of Oreos eaten: 0

    0 Oreos equals 0.0 servings!
    You consumed 0.0 calories.

    Keep eating Oreos!
*/