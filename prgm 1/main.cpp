//////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            Program 1
// Title:            Bitwise Operations
// Course:           CMPS 2433
// Semester:         Spring 2020
//
// Description:
//       This program reads in lines of offs and ons that represent a binary
//       number from an input file and translates them into an int Flag and
//       prints them in an outfile.
//       
// Files:            on_off.dat (given input file)
//                      ouput.dat (output file for on_off.dat)
//                   test.txt   (input file I created)
//                      test.dat  (output file for test.txt)  
// 
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

/**
 * Public : convertLine
 * 
 * Description:
 *      reads in a line from the file via loop and converts it into
 *      the int flag with help of functions change and modifyBit
 * 
 * Params:
 *      - ifstream &file
 *          - ifstream variable by reference to access file
 *
 * Returns:
 *      - integer flag
 **/
int convertLine(ifstream &file);

/**
 * Public : change
 * 
 * Description:
 *          Takes the string read from file by convertLine
 *          and returns the value that bit should switch to (0 or 1)
 * 
 * Params:
 *      - string op
 *          - string that is either on or off
 * 
 * Returns:
 *      - int, 1 or 0 or -1 if something went wrong
 */
int change(string op);

/**
 * Public : printFile
 * 
 * Description:
 *      prints to the output file the flag and assignment num
 * 
 * Params:
 *      - ofstream &outf
 *          - ofstream variable that allows for printing to file
 *      - int a
 *          - flag to be printed
 *      - int count
 *          - assignment counter to be used with print
 * Returns:
 *      - void
 */
void printFile(ofstream &outf, int a, int count);

/**
 * Public : modifyBit
 * 
 * Description:
 *      uses a mask to transform a specific bit of a number
 *      to a different value
 * 
 * Params:
 *      - int n
 *           - number to be transformed
 *      - int p
 *           - position of bit to be transformed
 *      - int b
 *          - value that bit will be changed to
 * 
 * Returns:
 *      - int (result of operation which is the modified int)
 */
int modifyBit(int n, int p, int b);

/**
 * Public: openFiles
 * 
 * Description:
 *      opens in and outfiles based on user input
 * 
 * Params:
 *      - ifstream &infile
 *          - ifstream variable by reference to be opened
 *      - ofstream &outfile
 *          - ofstream variable by reference to be opened
 * 
 * Returns:
 *      - void
 */
void openFiles(ifstream &infile, ofstream &outfile);


//main function
int main()
{
    ifstream infile;     //infile variable for openFiles to use
    ofstream outfile;    //outfile variable for openFiles to use
    int result;          //a flag to be printed
    int assnum = 0;      //assignment number

    openFiles(infile, outfile); //call openFiles
    outfile << "Paige Champagne\n" << endl;

   //loop until file ends
    while (!infile.eof())
    {
        assnum++;
        result = convertLine(infile);
        printFile(outfile, result, assnum);
    }

    return 0;
}

//function definitions

int convertLine(ifstream &file)
{
    int flag = 0; //variable to be flag

    for (int i = 15; i >= 0; i--)
    {
        string a;
        file >> a;
        flag = modifyBit(flag, i, change(a));
    }
    return flag;
}

int change(string op)
{   
    //returns appropriate value to switch to based on off/on
    if (op == "off")
    {
        return 0;
    }
    else if (op == "on")
    {
        return 1;
    }
    return -1;
}

void printFile(ofstream &outf, int a, int count)
{
    outf << "ASSIGNMENT #" << count << " FLAG IS " << a << endl
         << endl;
}

void openFiles(ifstream &infile, ofstream &outfile)
{
    char inFileName[40];   //essentially string to hold name user gives
    char outFileName[40];  //essentially string to hold name user gives

    cout << "Enter the input file name: ";
    cin >> inFileName;

    infile.open(inFileName); //open input file

    cout << "Enter the output file name: ";
    cin >> outFileName;

    outfile.open(outFileName); //open output file
}

int modifyBit(int n, int p, int b)
{
    int mask = 1 << p;    //masks so it only alters p
    return (n & ~mask) | ((b << p) & mask);
}