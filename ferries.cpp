// --------------------- File Header ---------------------------------
// Author : Jared Hillaire
// Assignment : Assignment 3 - Conditional Branching
// Date : October 22, 2026 - November 4th, 2026
// Citations : OpenAI ChatGPT - tutoring and code explanation.
// All code is writen by me, AI is only used for resource and understanding.

// ----------------------- Code ---------------------------------------

#include <iostream>
#include <iomanip>
#include <cctype>




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

    C. Calculations
        constraints:
            VEHICLE_FARE = 57.90
            ADULT_FARE = 14.95
            SENIOR_FARE = 7.40
            YOUTH_FARE = 5.55
            BIKE_FARE = 4.00
            FREE_TICKET_THRESHOLD = 100
            MAX_GROUP_SIZE = 20

        Passanger total:
            totalCharge = totalCharge + VEHICLE_FARE
            the vehicle fare includes the driver and bicycles.

        Otherwise:
            totalCharge = totalCharge + bikeCount * BIKE_FARE

        when totalCharge is at or below the threshold:
            amountNeeded = FREE_TICKET_THRESHOLD - totalCharge

        D. LOGIC AND ALGORITHMS
            BEGIN
                DECLARE fare constrants and the spending threshold.
                DECLARE the maximum group size constant.

                DECLARE vehicleAnswer as a character.
                DECLARE passanger and bicycle counts as integars.
                DECLARE totalCharge and amountNeeded as doubles.
                DECLARE inputValid as a Boolean.

                SET counts and money variables to zero
                SET inputValid to true.

                DISPLAY the welcome message.
                DISPLAY the fare menu.

                DISPLAY "Are you riding a vehicle on the ferry (Y/N):"
                READ vehicleAnswer

                IF input failed or the answer is not Y, y, N, or n
                SET inputValid to false.
            ELSE IF the answer has extra non-whitespace characters
                SET inputValid to false.
            END IF

            IF inputValid
                DISPLAY "How many adults? "
                READ adultCount.

                IF input failed, is negative, or is not a whole number
                    SET inputValid to false.
                END IF
            END IF

            IF inputValid
                DISPLAY "How many seniors? "
                READ seniorCount.

                IF input failed, is negative, or is not a whole number
                    SET inputValid to false.
                END IF
            END IF

            IF inputValid
                DISPLAY "How many youths? "
                READ youthCount.

                IF input failed, is negative, or is not a whole number
                    SET inputValid to false.
                END IF
            END IF

            IF inputValid AND vehicleAnswer is N or n
                DISPLAY "How many bikes? "
                READ bikeCount.

                IF input failed, is negative, or is not a whole number
                    SET inputValid to false.
                END IF
            END IF

            IF inputValid is false
                DISPLAY the invalid-answer message.
            ELSE IF any passenger count exceeds the maximum
                    OR the combined passenger count exceeds the maximum
                DISPLAY the too-many-people message.
            ELSE
                CALCULATE the passenger total.

                IF vehicleAnswer is Y or y
                    ADD the vehicle fare to totalCharge.
                ELSE
                    ADD the bicycle charges to totalCharge.
                END IF

                DISPLAY totalCharge with a dollar sign
                    and two decimal places.

                IF totalCharge is greater than the spending threshold
                    DISPLAY the free adult ticket message.
                ELSE
                    CALCULATE amountNeeded.
                    DISPLAY the additional spending needed.
                END IF
            END IF

            DISPLAY the goodbye message.
        END

    SAMPLE RUNS / TEST PLAN
        These are expected results.
        Add actual sample runs after testing.

        Test 1:
            Vehicle: y
            Adults: 2
            Seniors: 1
            Youths: 0
            Expected: no bicycle question.
            Expected total: $95.20
            Expected amount needed: $4.80

        Test 2:
            Vehicle: a
            Expected: invalid-answer message and goodbye.
            No further input questions or fare calculation.

        Test 3:
            Vehicle: n
            Adults: 2
            Seniors: 1
            Youths: 1
            Bikes: 2
            Expected total: $50.85
            Expected amount needed: $49.15

        Test 4:
            Vehicle: n
            Adults: -7
            Expected: invalid-answer message and goodbye.
            No further input questions or fare calculation.

        Test 5:
            Vehicle: n
            Adults: 12
            Seniors: 4
            Youths: 5
            Bikes: 2
            Expected: too-many-people message and goodbye.
            No fare calculation.

        Test 6:
            Vehicle: N
            Adults: 7
            Seniors: 0
            Youths: 0
            Bikes: 0
            Expected total: $104.65
            Expected: free adult ticket message.

        Test 7:
            Vehicle: Y
            Adults: 2
            Seniors: 1
            Youths: 0
            Expected: same results as Test 1.

        Test 8:
            Vehicle: n
            Adults: 20
            Seniors: 0
            Youths: 0
            Bikes: 0
            Expected total: $299.00
            Expected: free adult ticket message.

        Test 9:
            Vehicle: n
            Adults: 0
            Seniors: 0
            Youths: 0
            Bikes: -1
            Expected: invalid-answer message and goodbye.

        Test 10:
            Vehicle: n
            Adults: 2.5
            Expected: invalid-answer message and goodbye.

        Test 11:
            Vehicle: n
            Adults: abc
            Expected: invalid-answer message and goodbye.

*/
