/*
filter.h
Created by Rosa Tung on 1.19.16
*/

#ifndef FILTER_H
#define FILTER_H

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int openFile(ifstream& readFile, string fileName);
void extractLines(ifstream& readFile, string fileName, vector<string> &myArrays);
void extractInts(vector<string> &myArrays, int row, vector<int> &paArray);
void outputFile(vector<string> const &myArrays, int const row, vector<int> const &paArray, int const &leftIdx, int const &rightIdx, ofstream& writeFile);
void convertVector(vector<int> const &paArrat, int* paDynArray); //get array and array size, array passed in by reference

#endif // FILTER_H_INCLUDED
