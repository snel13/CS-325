/*
algos.h
Created by Rosa Tung on 1.20.16
*/

#ifndef ALGOS_H
#define ALGOS_H

#include <vector>
using namespace std;

const signed int SMALL = -32767;
const signed int LARGE = 32767;

int enumeration(int arr[], int array_length, int &leftIdx, int &rightIdx); //algorithm 1
int better_enum(int arr[], int arr_length, int &leftIdx, int &rightIdx); //algorithm 2

/***algorithm 3***/
int crossingSum(int a[], int beg, int mid, int end);
int maxSum(int a[], int beg, int end);
int maximumTwo(int numOne, int numTwo);
int maximumThree(int numOne, int numTwo, int numThree);

int mSSLinear(vector<int> const &paArray, int &rightIdx); //algorithm 4

#endif // ALGOS_H_INCLUDED
