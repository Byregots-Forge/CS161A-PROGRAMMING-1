// --------------------- File Header ---------------------------------
// Author : Jared Hillaire
// Assignment : Assignment 3 - Conditional Branching
// Date : October 22, 2026
// Citations : OpenAI ChatGPT - tutoring and code explanation.
// All code is writen by me, AI is only used for resource and understanding.

// ----------------------- Code ---------------------------------------




// ------------------------ Design ------------------------------------
/* 
    Program name:
        Washington State Ferries Fare Calculator

    Program Description:
        Calculate a group's ferry fare and check whether the group
        qualifies for a free adult ticket on its next trip.

    Design:
    A. INPUT
        vehicleAnswer: char - whether the user brings a vehicle (Y/N).
        adultCount: int - adults, excluding the vehicle's driver.
        seniorCount: int - seniors, excluding the vehicle's driver.
        youthCount: int - youths.
        bikeCount: int - bicycles; ask only when there is no vehicle.

    B. OUTPUT
        totalCharge: double - the group's total fare.
        amounthNeeded: double - extra spending needed to reach $100.
        Display money with a dollar sign and two decimal places
        Display an error message for invalid input.
        Display whether the group earns a free adult ticket

*/