// Copyright (c) 2023 Zak Goneau All rights reserved.
//
// Created by: Zak Goneau
// Date Created: Dec. 4, 2023
// This program is a calculator that does basic operations. It cannot mod decimals.

#include <iostream>
#include <iomanip>
#include <string>

double Calculator(float numOne, float numTwo, char sign) {
    // declare answer variable
    double answer;
    int numOneInt, numTwoInt;

    // check all levels then return value
    if (sign == '+') {
        answer = numOne + numTwo;
        return answer;
    } else if (sign == '-') {
        answer = numOne - numTwo;
        return answer;
    } else if (sign == '/') {
        answer = numOne / numTwo;
        return answer;
    } else if (sign == '*') {
        answer = numOne * numTwo;
        return answer;
    } else {
        // cast both inputs to integers
        numOneInt = static_cast<int>(numOne);
        numTwoInt = static_cast<int>(numTwo);
        answer = numOneInt % numTwoInt;
        return answer;
    }
}

int main() {
    // declare variables
    std::string userNumOne, userNumTwo;
    float numOneFloat, numTwoFloat;
    int numOneInt, numTwoInt;
    char userSign;

    // introduce program to user
    std::cout << "Hello, this program is a calculator";
    std::cout << "and uses the basic operations " << std::endl;

        // get two numbers from user and sign
        std::cout
        << "Please enter a number: ";
    std::cin >> userNumOne;
    std::cout << "Please enter another number: ";
    std::cin >> userNumTwo;
    std::cout << "Please enter a sign (+, -, *, /, %): ";
    std::cin >> userSign;

    // try casting first input to a float
    try {
        numOneFloat = std::stof(userNumOne);

        // try casting second input to a float
        try {
            numTwoFloat = std::stof(userNumTwo);

            // check if sign is valid
            if (userSign == '+' || '-' || '/' || '%' || '*') {

                // check if user inputs mod sign
                if (userSign == '%') {

                    // cast both inputs to integers
                    numOneInt = static_cast<int>(numOneFloat);
                    numTwoInt = static_cast<int>(numTwoFloat);

                    // check for decimals
                    if (numOneInt == numOneFloat && numTwoInt == numTwoFloat) {

                        // call function
                        double calcAnswer = Calculator(numOneFloat, numTwoFloat, userSign);

                        // display answer
                        std::cout << "" << numOneFloat << " " << userSign << " " << numTwoFloat << " = " << std::fixed << std::setprecision(2) << calcAnswer << std::endl;
                    } else {

                        // tell user can't mod decimals
                        std::cout << "You cannot mod decimals." << std::endl;
                    }
                } else {
                    // call function
                    double calcAnswer = Calculator(numOneFloat, numTwoFloat, userSign);

                    // display answer
                    std::cout << "" << numOneFloat << " " << userSign << " " << numTwoFloat << " = " << std::fixed << std::setprecision(2) << calcAnswer << std::endl;
                }
            } else {

                // tell user if invalid sign input
                std::cout << "" << userSign << " is an invalid sign." << std::endl;
                }

        // catch invalid inputs
        } catch (std::invalid_argument) {
            std::cout << "" << userNumTwo << " is not a valid number" << std::endl;
        }

    // catch invalid inputs
    } catch (std::invalid_argument) {
        std::cout << "" << userNumOne << " is not a valid number." << std::endl;
        }
}
