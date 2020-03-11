//////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Paige Champagne
// Email:            paigechamp@gmail.com
// Label:            Program 2
// Title:            Sequences and Summations
// Course:           CMPS 2433
// Semester:         Spring 2020
//
// Description:
//       This program reads in lines from a file and converts each line into a
//          sequence and a summation based on the data
//       
// Files:            SeqSum1.dat (given input file)
//                      SeqSum1Out.dat (output file for SeqSum1.dat)
//                   input.txt   (input file I created)
//                      output.dat  (output file for input.txt)  
// 
//////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

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

/**
 * Public: geometric
 * 
 * Description:
 *      generates a geometric sequence if the flag is G
 * 
 * Params:
 *      - int seq[]
 *          - the (pointer) array the sequence will go in
 *      - int numterms
 *          - the number of terms in the sequence (for loop control)
 *      - int a
 *          - the value of the first number in the sequence
 *      - int r
 *          - the number to be multiplied by the previous term
 * 
 * Returns:
 *      - int* seq
 *          - the finished sequence
 */
int* geometric(int seq[], int numterms, int a, int r);

/**
 * Public: arithmetic
 * 
 * Description:
 *      generates an arithmetic sequence if the flag is A
 * 
 * Params:
 *      - int seq[]
 *          - the (pointer) array the sequence will go in
 *      - int numterms
 *          - the number of terms in the sequence (for loop control)
 *      - int a
 *          - the value of the first number in the sequence
 *      - int r
 *          - the number to be added to the previous term
 * 
 * Returns:
 *      - int* seq
 *          - the finished sequence
 */
int* arithmetic(int seq[], int numterms, int a, int r);

/**
 * Public: sum
 * 
 * Description:
 *      calculates the sum of a sequence from the lower to upper limits
 * 
 * Params:
 *      - int seq[]
 *          - the (pointer) array that holds the sequence used for the sum
 *      - int lLimit
 *          - lower limit that the sum starts at
 *      - int uLimit
 *          - upper limit where the sum ends

 * 
 * Returns:
 *      - int summ
 *          - the sum of all values from lLimit to uLimit
 */
int sum(int seq[], int lLimit, int uLimit);

/**
 * Public: print
 * 
 * Description:
 *      prints the sequence and summation to the outfile
 * 
 * Params:
 *      - int seq[]
 *          - the (pointer) array that is printed
 *      - int numterms
 *          - the number of terms in the sequence (for loop control)
 *      - int s
 *          - the summation to be printed
 *      - char type
 *          - the type of sequence being printed
 * 
 * Returns:
 *      - void
 */
void print(int seq[], int numterms, int s, char type, 
            ofstream &outfile, int lLimit, int uLimit);



int main()
{
    ifstream infile;     //infile variable for openFiles to use
    ofstream outfile;    //outfile variable for openFiles to use
    char type; //type of summation, 1st item read in from line
    int a; //starting number, 2nd item read in from line
    int r; //number to be added/multiplied with a, 3rd item read in from line
    int numterms; //number of terms to be generated, 4th item read in from line
    int lLimit; //lower limit for summation, 5th item read in from line
    int uLimit; //upper limit for summation, 6th item
    int *sequence; //pointer int for an array we will dynamically size later
    int summ; //the value of the summation

    openFiles(infile, outfile); //call openFiles
    outfile << "Paige Champagne\n" << endl;

    if(infile){
     while(!infile.eof()){
        infile >> type >> a >> r >> numterms >> lLimit >> uLimit;
        if((1 <= numterms <= 40) & (1 <= lLimit <= 40) & (1 <= uLimit <= 40)){
        sequence = new int[numterms];
        if(type == 'A'){
            arithmetic(sequence, numterms, a, r);
        } else if(type == 'G'){
            geometric(sequence, numterms, a, r);
        }
        
        summ = sum(sequence, lLimit, uLimit);
        
        print(sequence, numterms, summ, type, outfile, lLimit, uLimit);
        }else{
            cout << "Error in data\n";
        }
        }
    }else{
        cout << "File not found\n";
    }



return 0;
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

int* geometric(int seq[], int numterms, int a, int r){
    for(int i = 0; i < numterms; i++){
       
       if(i != 0){
        seq[i] = seq[i-1] * r;
       }else if(i == 0){
        seq[i] = a;
       } 
    }
return seq;
}

int* arithmetic(int seq[], int numterms, int a, int r){
    for(int i = 0; i < numterms; i++){
       
       if(i != 0){
        seq[i] = seq[i-1] + r;
       }else if(i == 0){
        seq[i] = a;
       } 
    }
return seq;
}

int sum(int seq[],  int lLimit, int uLimit){
   int summ = 0;
    for(int i = lLimit-1; i < uLimit; i++){
        summ += seq[i];
    }
return summ;
}

void print(int seq[], int numterms, int s, char type, 
            ofstream &outfile, int lLimit, int uLimit){
    if(type == 'A'){
        outfile << "Arithmetic sequence: ";
    } else if(type == 'G'){
        outfile << "Geometric sequence: ";
    }

    for(int i = 0; i < numterms; i++){
        outfile << seq[i] << "    ";
    }

    outfile << "\nSum of sequence from " << lLimit << " to " << uLimit 
            << " term is " << s << endl <<endl;
}