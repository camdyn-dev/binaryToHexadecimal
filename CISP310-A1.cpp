/*
    Student: Camdyn
    Class: CISP 310
    Assignment 1

    Purpose of Program:
        Convert binary numbers to hexadecimal.

        We achieve this by converting the user supplied binary into an array so it's easier to work with,
        convering that into a decimal integer, which is then converted into hexadecimal string.
*/

#include <iostream>
#include <string>    // for hexadecimal string
#include <algorithm> //for reverse() function
using namespace std;

int getLengthOfInt(int userInput)
{
    int length;
    for (length = 0; userInput > 0; length++)
    {
        userInput /= 10;
    } // dividing userInput by ten until it's 0; or in other words, getting the length of the supplied integer.
    return length;
}

int *convertIntToArray(int userInput, int userInputLength)
{
    // used to convert binary integer to an array so it's easier to work with
    int *intInArray = new int[userInputLength];
    for (int i = 0; i < userInputLength; i++)
    {
        intInArray[i] = userInput % 10; // grab last digit in userInput
        userInput /= 10;                // remove last digit in userInput;
    }
    return intInArray;
}

int convertBinaryArrayToDecimal(int userInput[], int userInputLength)
{
    int decimalResult = 0; // storage for result
    int binaryTrack = 1;   // binaryTrack replicates how each ascending digit of a binary number is multiplied by 2
    for (int i = 0; i < userInputLength; i++)
    {
        decimalResult += userInput[i] * binaryTrack;
        binaryTrack *= 2;
    }

    return decimalResult;
}

string convertDecimalToHexadecimal(int userInput)
{
    string hexadecimalResult = ""; // since hexadecimal uses characters, we need to define a string.

    for (int i = 0; userInput > 0; i++)
    {
        int remainder = userInput % 16; // we work off the remainder

        switch (remainder) // basically, this statement allows us to put an A, B, C, D, E or F if the remainder falls within the range, and otherwise
                           // adds the normal number in hexadecimal
        {
        case 10:
            hexadecimalResult += 'A';
            break;
        case 11:
            hexadecimalResult += 'B';
            break;
        case 12:
            hexadecimalResult += 'C';
            break;
        case 13:
            hexadecimalResult += 'D';
            break;
        case 14:
            hexadecimalResult += 'E';
            break;
        case 15:
            hexadecimalResult += 'F';
            break;
        default:
            hexadecimalResult += to_string(remainder); // if it's not one of the above, convert it to string, then add it to the result;
        }
        userInput /= 16;
    }

    reverse(hexadecimalResult.begin(), hexadecimalResult.end()); // reverse string, as we're adding items in reverse order

    return hexadecimalResult;
}

int main()
{
    int userSuppliedBinary;
    int userSuppliedLength;
    int *binaryInArray;
    int userSuppliedDecimal;
    string userSuppliedHexadecimal;
    // declaring variables

    cout << "Please enter a binary number you'd like to convert to hexadecimal: ";
    cin >> userSuppliedBinary;
    cout << endl;

    userSuppliedLength = getLengthOfInt(userSuppliedBinary); // get length of user input

    binaryInArray = convertIntToArray(userSuppliedBinary, userSuppliedLength); // convert user inputted binary to array so it's easier to work with

    userSuppliedDecimal = convertBinaryArrayToDecimal(binaryInArray, userSuppliedLength); // convert user binary array to decimal integer

    userSuppliedHexadecimal = convertDecimalToHexadecimal(userSuppliedDecimal); // convert user decimal to hexadecimal string

    cout << userSuppliedBinary << " in binary is equal to " << userSuppliedDecimal << " in decimal, which is equal to " << userSuppliedHexadecimal << " in hexadecimal." << endl;

    delete binaryInArray; // free up memory

    return 0;
}
