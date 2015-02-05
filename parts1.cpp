// File Name: parts1.cpp
// Author: your Derek Pauly
// Student ID: s829f376
// Assignment Number: 1
// Last Changed: February 5, 2015

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "parts1.hpp"
#include "utils.hpp"

using namespace std; // Allows all Standard Library items to be used

//Questions: TODO
//    add functions: parts_heavier parts_ligher parts_equal

int main() {

    Part partList[ARRAY_SIZE]; // Part array to hold parts read from file
    double weight; // User input weight to use for comparison
    int numRecords; // Holds the amount of Part Records store in Part array
    int userSelection; // user input to be used for comparison type
    ifstream inFile(IN_FILENAME); // input file
    ofstream outFile(OUT_FILENAME); // output file

    // Ensure files opened successfully, exit otherwise
    if (!(inFile.is_open() && outFile.is_open())) {
        cout << "Error opening file\n" << "Goodbye" << endl;
        exit(EXIT_FAILURE);
    }

    // Store part information from file into partArray, exit otherwise
    numRecords = get_part_data_from_file(inFile, partList);
    if (numRecords == 0) { // Ensure data was read from file exit program otherwise
        cout << "No parts loaded from file, GoodyBye." << endl;
        exit(EXIT_FAILURE);
    }


    // Begin running program if data loaded from file successfully
    cout << PROGRAM_INFO << endl;
    do {
        weight = get_double("Enter the weight to use for comparing with the parts’ weights:");
        if (weight <= 0) {
            cout << "Weight must be positive!" << endl;
        }
    } while (weight <= 0);

    cout << INSTRUCTIONS << endl;
    do {
        userSelection = get_int("Enter the comparison type to use: ");
        if (userSelection < 1 || userSelection > 3) // ensure selection is valid
            cout << "You must enter comparison type 1, 2, or 3!" << endl;
    } while (userSelection < 1 || userSelection > 3);

    int recordsWrote = send_part_data_to_file // number of records wrote to file
            (outFile, partList, numRecords, userSelection, weight);

    cout << "\nA list of " << recordsWrote
         << " parts matching your selection has been saved in the file "
         << OUT_FILENAME << "." << endl;

    // Close files
    outFile.close();
    inFile.close();

    return EXIT_SUCCESS;

} // End main

// Read part file and stores Part structure data into a Part array
int get_part_data_from_file(ifstream &inFile, Part partArray[]) {
    int numRecords = 0; // Number of parts stored in partArray
    string line; // Line from part text file

    while (!inFile.eof()) { // stop when end of file (EOF) is reached
        getline(inFile, line);
        if (line.length() > 0) { // ensure something was read into the line
            partArray[numRecords] = read_part_record(line);
            numRecords++;
        }
    }
    return numRecords;
}

// Sends string parameter line to a Stringstream
// Extracts  and stores Part structure data from Stringstream
// Returns Part structure
Part read_part_record(std::string line) {
    Part part; // Part to be filled and returned
    stringstream ss; // Stringstream to hold line from part_data.txt
    string partName; // Part name to be trimmed of whitespaces

    ss << line; // Insert line into Stringstream
    partName = read_from_string_stream(ss, NAME_LENGTH);
    rtrim(partName); // Remove whitespace characters

    // Assign values to part to be returned
    part.pname = partName;
    ss >> part.pnumber >> part.weight >> part.supplier1 >> part.supplier2 >> part.inStock;
    return part;
}

// Reads a certain amount of characters (length) from the stringstream
// returns string of the characters read
string read_from_string_stream(stringstream &fromStr, int length) {
    char tmp[LINE_LENGTH] = ""; // Temporary C_String
    fromStr.read(tmp, length);
    string returnStr(tmp); // convert tmp C_String to string for return
    return returnStr;
}

// remove whitespaces from end of string
void rtrim(string &s) {
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
}

// Sends part data to file based on user selection and weight
int send_part_data_to_file
        (std::ofstream &outFile, Part partArray[], int records, int selection, double weight) {
    int numRecords = 0; // number of records wrote to file
    if (1 == selection) {
        for (int i = 0; i < records; ++i) {
            if (partArray[i].weight < weight) {
                print_part(outFile, partArray[i]); // send data to output file
                numRecords++;
            }
        }
    } else if (2 == selection) {
        for (int i = 0; i < records; ++i) {
            if (partArray[i].weight == weight) {
                print_part(outFile, partArray[i]); // send data to output file
                numRecords++;
            }
        }
    } else {
        for (int i = 0; i < records; ++i) {
            if (partArray[i].weight > weight) {
                print_part(outFile, partArray[i]); // send data to output file
                numRecords++;
            }
        }
    }
    return numRecords;
}

// Prints data items of part structure to output stream
void print_part(std::ostream &os, Part &part) {
    // Set precision
    os.setf(ios::fixed);
    os.setf(ios::showpoint);
    os.precision(2);

    // Send part out output stream
    os << part.pname << " "
            << part.pnumber << ", "
            << part.weight << ", "
            << part.inStock << " "
            << "in stock" << endl;
}

//    add functions: parts_heavier parts_ligher parts_equal