Rosa Tung                                        CS 325 Project 1                        23 Jan 2016
Sam Nelson
Kara Franco
READ ME

About
Group1MSS is a group project by Rosa Tung, Sam Nelson and Kara Franco. This project implements four solutions to the Maximum Sum Subarray problem by using the enumeration algorithm, the better-enumeration algorithm, the divide and conquer algorithm and the dynamic programming algorithm. 


A user can input a test .txt file into the program to test the four algorithms on the the given arrays in the testfile. The output from the project is the results from each algorithm, including the best sum and the subarray that makes up that sum. The results can be found in a new file created in the directory named MSS_TestRestults.txt. 


To Run
To run this project, place the following files into a directory along with the .txt file that you wish to test the algorithms against.
main.cpp                yourTextFile.txt
filter.cpp                 filter.h                        
algos.cpp                 algos.h
makefile


Next, run the makefile to compile by entering “make” (without the quotes “ “) into the flip server. 


Then write “main” (without the quotes “ “) into the flip server.


Follow the instructions that the program gives you 
** be sure to enter the filename without the .txt extension **

Results can be found in the MSS_TestResults.txt found in the directory. 

Extra
There are extra files in this project that are used for testing. The file generator.cpp generates random arrays to be fed into the four algorithms to test for accuracy, completeness and runtime. Likewise, there are files named, test1.txt, test2.txt, test3.txt and wasd.txt that were all used to test the four algorithms. You may run any of these files in the main program to see the results!