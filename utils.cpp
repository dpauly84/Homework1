// File Name: utils.cpp
// Author: Derek Pauly
// Student ID: s829f376
// Assignment Number: 1
// Last Changed: February 5, 2015

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits>

// outputs string prompt
// reads input as string and converts it to type int
// repeats if conversion is not valid
int get_int(std::string prompt) {
    using namespace std;
    char str[20]; // original user input as a string
    long longNum; // number converted from user input
    bool isValidNumber = true; // conversion status
    char *end_ptr; // used to check validity of conversion
    do {
        if (!isValidNumber) cout << "You must enter an integer. ";
        cout << prompt;
        cin >> str;
        longNum = strtol(str, &end_ptr, 0);
        if (end_ptr != (str + strlen(str)))
            isValidNumber = false;
        else if (longNum < numeric_limits<int>::min() || // Ensure number is within int size
                 longNum > numeric_limits<int>::max())
            isValidNumber = false;
        else
            isValidNumber = true;
    } while (!isValidNumber);
    return longNum; // type conversion to int
}

// outputs string prompt
// reads input as string and converts it to type double
// repeats if conversion is not valid
double get_double(std::string prompt) {
    using namespace std;
    char str[20]; // original user input as a string
    double num; // number converted from user input
    bool isValidNumber = true; // conversion status
    char *end_ptr; // used to check validity of conversion
    do {
        if (!isValidNumber) cout << "You must enter a number. ";
        cout << prompt;
        cin >> str;
        num = strtod(str, &end_ptr);
        if (end_ptr != (str + strlen(str)))
            isValidNumber = false;
        else
            isValidNumber = true;
    } while (!isValidNumber);
    return num;
}

// outputs string prompt
// reads input as string and converts it to type long
// repeats if conversion is not valid
long get_long(std::string prompt) {
    using namespace std;
    char str[20]; // original user input as a string
    long num; // number converted from user input
    bool isValidNumber = true; // conversion status
    char *end_ptr; // used to check validity of conversion
    do {
        if (!isValidNumber) cout << "You must enter a long integer. ";
        cout << prompt;
        cin >> str;
        num = strtol(str, &end_ptr, 0);
        if (end_ptr != (str + strlen(str)))
            isValidNumber = false;
        else
            isValidNumber = true;
    } while (!isValidNumber);
    return num;
}

// outputs string prompt
// reads input as string and converts it to type double
// repeats if conversion is not valid
float get_float(std::string prompt) {
    using namespace std;
    char str[20]; // original user input as a string
    float num; // number converted from user input
    bool isValidNumber = true; // conversion status
    char *end_ptr; // used to check validity of conversion
    do {
        if (!isValidNumber) cout << "You must enter a number. ";
        cout << prompt;
        cin >> str;
        num = strtof(str, &end_ptr);
        if (end_ptr != (str + strlen(str)))
            isValidNumber = false;
        else
            isValidNumber = true;
    } while (!isValidNumber);
    return num;
}