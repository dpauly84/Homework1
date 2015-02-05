// File Name: parts1.hpp
// Author: your Derek Pauly
// Student ID: s829f376
// Assignment Number: 1
// Last Changed: February 5, 2015

#ifndef _PART1_HPP_
#define _PART1_HPP_

struct Part // TODO
{
    std::string pname; // part name
    std::string pnumber; // part number format DDDD-DD where D is a digit
    double weight; // part weight
    std::string supplier1; // part suppllier1 format CDDD where C is a character
    std::string supplier2; // part supplier2 format CDDD
    int inStock; // Quantity of parts in stock
};

// CONSTANT VARIABLES
const int LINE_LENGTH = 45; // length of line from part file
const int NAME_LENGTH = 17; // Max length of part name (pname) in part file
const int ARRAY_SIZE = 100; // Max number of parts held in Part array

const char *IN_FILENAME = // name of part input file to be read from
        "part_data.txt";
const char *OUT_FILENAME = // name of part output file to be wrote to
        "part_matches.txt";
const std::string PROGRAM_INFO = // Program Info displayed when ran
        "This program will find parts in the inventory based on a weight. You will have\n"
        "a choice to get parts whose weight is less than, greater than, or equal to the\n"
        "weight you enter.\n";
const std::string INSTRUCTIONS =
        "Comparison type:\n"
                "\t1 - Find parts with weights LESS THAN your entered weight\n"
                "\t2 - Find parts with weights EQUAL TO your entered weight\n"
                "\t3 - Find parts with weights GREATER THAN your entered weight\n";

// Read part file and stores Part structure data into a Part array
int get_part_data_from_file(std::ifstream &inFile, Part partArray[]);

// Sends string parameter line to a Stringstream
// Extracts  and stores Part structure data from Stringstream
// Returns Part structure
Part read_part_record(std::string line);

// Reads a certain amount of characters (length) from the stringstream
// returns string of the characters read
std::string read_from_string_stream(std::stringstream &from_str, int length);

// remove whitespaces from end of string
void rtrim(std::string &s);

// Sends part data to file based on user selection and weight
int send_part_data_to_file
        (std::ofstream &outFile, Part partArray[], int records, int selection, double weight);

// Prints data items of part structure to output stream
void print_part(std::ostream &os, Part &part);

#endif
