#include <iostream>
#include <cstdlib>
#include <cstring>
#include <limits>

int get_int(std::string prompt) {
    using namespace std;
    char str[20]; // original user input as a string
    long longNum; // number converted from user input
    bool validNumber = true;
    char *end_ptr;
    do {
        if (!validNumber) cout << "You must enter an integer. ";
        cout << prompt;
        cin >> str;
        longNum = strtol(str, &end_ptr, 0);
        if (end_ptr != (str + strlen(str)))
            validNumber = false;
        else if (longNum < numeric_limits<int>::min() || // Ensure number is within int size
                 longNum > numeric_limits<int>::max())
            validNumber = false;
        else
            validNumber = true;
    } while (!validNumber);
    return longNum; // type conversion to int
}

double get_double(std::string prompt) {
    using namespace std;
    char str[20]; // original user input as a string
    double num; // number converted from user input
    bool validNumber = true;
    char *end_ptr;
    do {
        if (!validNumber) cout << "You must enter a number. ";
        cout << prompt;
        cin >> str;
        num = strtod(str, &end_ptr);
        if (end_ptr != (str + strlen(str)))
            validNumber = false;
        else
            validNumber = true;
    } while (!validNumber);
    return num;
}

long get_long(std::string prompt) {
    using namespace std;
    char str[20]; // original user input as a string
    long num; // number converted from user input
    bool validNumber = true;
    char *end_ptr;
    do {
        if (!validNumber) cout << "You must enter a long integer. ";
        cout << prompt;
        cin >> str;
        num = strtol(str, &end_ptr, 0);
        if (end_ptr != (str + strlen(str)))
            validNumber = false;
        else
            validNumber = true;
    } while (!validNumber);
    return num;
}