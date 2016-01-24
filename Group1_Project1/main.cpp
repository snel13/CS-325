/*
Author: Rosa Tung
Date Created: 1.19.16
Date modified: 1.19.16
Overview:
Read in input file of format [x, ...z] on each line and output max sub array into MSS_Results.txt
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include <ctime>
#include <iomanip>
using namespace std;
using namespace std::chrono;

#include "filter.h"
#include "algos.h"

int main(){
	ifstream readFile;
	ofstream writeFile;
	string fileName;

	vector <string> myArrays;
	vector <int> paArray;
	int *paDynArray = new int[0]; //dynamic array

	int maxSS;
	vector <int> rights;
	vector <int> lefts;
	int rightIdx;
	int leftIdx;

	//get filename
	cout << "Enter txt filename, don't put extension." << endl;
	cin >> fileName;

	//extract parent arrays from file
	extractLines(readFile, fileName, myArrays);

	/**make result file**/
	writeFile.open("MSS_TestResults.txt");

	/****Algorithm 1****/ 
	writeFile << "Algorithm 1" << endl;								//cout << "number of arrays: " << myArrays.size();
	for (int place = 0; place<myArrays.size(); place++){
		extractInts(myArrays, place, paArray);

		//convert vectors to arrays if needed
		int *paDynArray = new int[paArray.size()];
		convertVector(paArray, paDynArray);
		//************************************
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
		// call enumeration and pass in the array and array size
		// left index and right index will keep track of the subarray indeces
		maxSS = enumeration(paDynArray, paArray.size(), leftIdx, rightIdx);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
			cout << "alg 1 time " << time_span1.count() <<  endl;
		lefts.push_back(leftIdx); //1, 5, 7....
		rights.push_back(rightIdx); //same thing
		outputFile(myArrays, place, paArray, lefts[place], rights[place], writeFile);
		writeFile << maxSS << endl;
		writeFile << endl;

		delete[] paDynArray;
		paArray.clear();
	}

		cout << "" << endl;
	/****Algorithm 2****/
	writeFile << "Algorithm 2" << endl;
	for (int place = 0; place<myArrays.size(); place++){
		extractInts(myArrays, place, paArray);

		//convert vectors to arrays if needed
		int *paDynArray = new int[paArray.size()];
		convertVector(paArray, paDynArray);
		//************************************
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
		// call better_enum and pass in the array and array index
		// left index and right index will keep track of the subarray indeces
		maxSS = better_enum(paDynArray, paArray.size(), leftIdx, rightIdx);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
			cout << "alg 2 time " << time_span1.count() <<  endl;
		//lefts.push_back(leftIdx);
		//rights.push_back(rightIdx);
		outputFile(myArrays, place, paArray, lefts[place], rights[place], writeFile);
		writeFile << maxSS << endl;
		writeFile << endl;

		delete[] paDynArray;
		paArray.clear();
	}
		cout << "" << endl;

	/****Algorithm 3****/
	writeFile << "Algorithm 3" << endl;
	for (int place = 0; place<myArrays.size(); place++){
		extractInts(myArrays, place, paArray);

		//convert vectors to arrays if needed
		int *paDynArray = new int[paArray.size()];
		convertVector(paArray, paDynArray);
		//************************************
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
		// call maxSum (recursive alg) and pass in the array and array size
		maxSS = maxSum(paDynArray, 0, paArray.size() - 1);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
			cout << "alg 3 time " << time_span1.count() <<  endl;
		
		outputFile(myArrays, place, paArray, lefts[place], rights[place], writeFile);
		writeFile << maxSS << endl;
		writeFile << endl;

		delete[] paDynArray;
		paArray.clear();
	}
		cout << "" << endl;

	/****algorithm 4****/
	writeFile << "Algorithm 4" << endl;
	//extract integers from arrays, pass through function and write to output file
	for (int place = 0; place<myArrays.size(); place++){
		extractInts(myArrays, place, paArray);
			high_resolution_clock::time_point t1 = high_resolution_clock::now();
		// call mSSLinear and pass in the array and the right index
		// the right index will track the beginning of the subarray
		maxSS = mSSLinear(paArray, rightIdx);
			high_resolution_clock::time_point t2 = high_resolution_clock::now();
			duration<double> time_span1 = duration_cast<duration<double>>(t2 - t1);
			cout << "alg 4 time " << time_span1.count() <<  endl;
		outputFile(myArrays, place, paArray, lefts[place], rights[place], writeFile);
		writeFile << maxSS << endl;
		writeFile << endl;
		paArray.clear();
	}
	/**close result file**/
	writeFile.close();

	

	return 0;
}
