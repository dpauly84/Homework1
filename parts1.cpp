#include <iostream>     // Provides cout & cin
#include <fstream>      // Provides ofstream & istream
#include <sstream>      // Provides stringstream
#include <cstdlib>      // Provides EXIT_SUCCESS & EXIT_FAILURE
#include "parts1.hpp"
#include "utils.hpp"

using namespace std;    // Allows all Standard Library items to be used

//Questions: TODO
//    const char and const string in .hpp or .cpp?
//    declare variables before use or all at top?
//    comment functions in .hpp .cpp or both?
//    add functions: parts_heavier parts_ligher parts_equal
//    implement float function in utils.cpp

int main() {

    Part partList[ARRAY_SIZE]; // Part array to hold parts read from file

    ifstream inFile(IN_FILENAME); // input file
    ofstream outFile(OUT_FILENAME); // output file
    test_file_open(inFile); // Ensure file opens successfully - close program if not
    test_file_open(outFile);

    int numRecords; // Holds the amount of Part Records store in Part array
    numRecords = get_part_data_from_file(inFile, partList);
    if (numRecords <= 0) { // Ensure data was read from file exit program otherwise
        cout << "No parts loaded from file, GoodyBye." << endl;
        exit(EXIT_FAILURE);
    }


// Begin running program if data loaded from file successfully
    cout << PROGRAM_INFO << endl;
    double weight; // User input weight to use for comparison
    weight = get_double("Enter the weight to use for comparing with the parts’ weights:");

    cout << INSTRUCTIONS << endl;

    int userSelection; // user input to be used for comparison type
    do {
        userSelection = get_int("Enter the comparison type to use: ");
        if (userSelection < 1 || userSelection > 3)
            cout << "You must enter comparison type 1, 2, or 3!" << endl;
    } while (userSelection < 1 || userSelection > 3);

    int recordsWrote = send_part_data_to_file // number of records wrote to file
            (outFile, partList, weight, userSelection, numRecords);

    cout << "A list of " << recordsWrote <<
            " parts matching your selection has been saved in the file " <<
            OUT_FILENAME << "." << endl;


// Close files
    outFile.close();
    inFile.close();
    return EXIT_SUCCESS;

} // End main

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
//    cout << part.pname << endl; // print for debugging
    return part;
}

string read_from_string_stream(stringstream &fromStr, int length) {
    char tmp[LINE_LENGTH] = ""; // Temporary C_String
    fromStr.read(tmp, length);
    string returnStr(tmp); // convert tmp C_String to string for return
    return returnStr;
}

void rtrim(string &s) {
    s.erase(s.find_last_not_of(" \n\r\t") + 1);
}

void print_part(std::ostream &os, Part &part) {
    // TODO set precision
    os << part.pname << " "
            << part.pnumber << ", "
            << part.weight << ", "
            << part.inStock << " "
            << "in stock" << endl;
}

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

int send_part_data_to_file
        (ofstream &outFile, Part partArray[], double weight, int selection, int records) {
    int numRecords = 0;
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

void test_file_open(std::ifstream &fs) {
    if (!fs.is_open()) { // Make sure file opened successfully, exit otherwise
        cout << "Error opening file " << IN_FILENAME << "\nGoodbye!" << endl;
        exit(EXIT_FAILURE);
    }
}

void test_file_open(std::ofstream &fs) {
    if (!fs.is_open()) { // Make sure file opened successfully, exit otherwise
        cout << "Error opening file " << IN_FILENAME << "\nGoodbye!" << endl;
        exit(EXIT_FAILURE);
    }
}
