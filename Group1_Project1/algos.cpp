#include "algos.h"

#include <iostream>

/*****************************************************************************************
* Algorithm 1: enumeration ()
* Parameters: array and the array length
* Description: A function that demonstrates the enumeration implementation of the maximum
* subarray problem. The function traverses through each pair of indices to find the maximum
* sum of the given array. The maximum sum and indices of the subarray are stored.
******************************************************************************************/
int enumeration(int arr[], int array_length, int &leftIdx, int &rightIdx){
	int sum, maxSum = 0, low = 0, high = 0;
	// iterate over indices i and j
	for (int i = 0; i < array_length; i++) {
		for (int j = i; j < array_length; j++) {
			sum = 0;
			for (int k = i; k <= j; k++) {
				// compute the sum
				sum += arr[k];
			}
			// store the best sum 
			// track the low and high indices that make the subarray
			if (sum > maxSum) {
				maxSum = sum;
				low = i;
				high = j;

			}
		}
	}

	leftIdx = low;
	rightIdx = high;
	return maxSum;
}

/*****************************************************************************************
* Algorithm 2: better_enum ()
* Parameters: array and the array length
* Description: A function that demonstrates the better enumeration implementation of the
* maximum subarray problem. The function traverses through the array i to find the maximum
* sum of the given array. The maximum sum and indices of the subarray are stored.
******************************************************************************************/
int better_enum(int arr[], int arr_length, int &leftIdx, int &rightIdx){
	int sum, maxSum = 0, low = 0, high = 0;
	// iterate only through i 
	for (int i = 0; i < arr_length; i++) {
		sum = 0;
		for (int j = i; j < arr_length; j++) {
			sum += arr[j];
			// store the best sum 
			// track the low and high indices that make the subarray
			if (sum > maxSum) {
				maxSum = sum;
				low = i;
				high = j;
			}
		}
	}																					//cout << "going throuhg algo 2" << endl;
	leftIdx = low;
	rightIdx = high; 
	return maxSum;
}

/********************************************************************
 * Algorithm 3: maxSum() 
 * Parameters: array and array length
 * Description: A collection of functions that recursively solve the 
 * maximum sum subarray problem.
 * ******************************************************************/


/************************************************
*FUNCTION: crossingSum()			*
*Params:an array 'a', start of array int, 	*
*end of array int, and a midpoint on 'a' int 	*
*Description: will look over the mid portion	*
*for continous positive sum and return that #	*
*specificially, this function will add both of *
*the left sum and right sum after finding both *
*maximum sums from left and right of center 	*
*going to the outside example shown below	*
***********************************************/

/************************************************
* VISUAL EXAMPLE OF FUNCTION BELOW:  		*
* a[] = {1,-5,7,2,-5,2,1}			*
* mid=7/2...3rd element; 			*
* leftSum: count=mid;count>=beg;end=6th;x-- 	*
* start:sum=2;sum>leftSum;leftSum=2		*
* sum=9;sum>leftSum;leftSum=9			*
* sum=4;sum>leftSum-NO;leftSum=9		*
* sum=5;sum>leftSum-NO;leftSum=9		*
*						*
* rightSum:count=mid+1;count<=end;x++		*
* start:sum=-5;sum>rightSum;rightSum=-5	*
* sum=-3;sum>rightSum;rightSum=-3		*
* sum=-2;sum>rightSum;rightSum=-2		*
*						*
* midSum=rightSum+leftSum = 7			*
* *********************************************/
int crossingSum(int a[], int beg, int mid, int end)
{
	//left of mid sum
	int sum = 0;
	int leftSum = SMALL;
	int subArrayStart = -5;
	int subArrayEnd = LARGE;
	for (int x = mid; x >= beg; x--)
	{
		//		cout<<"x on the left side is: "<<x<<endl;
		sum += a[x];
		if (sum>leftSum)
		{
			leftSum = sum;
			//			subArrayStart=x;
			//			cout<<"the start of the cross sub Array is: "<<subArrayStart<<endl;
		}
	}

	//right of mid sum
	//0 out sum from left of mid calculations and recycle
	sum = 0;
	int rightSum = SMALL;
	for (int y = mid + 1; y <= end; y++)
	{
		sum += a[y];
		if (sum>rightSum)
		{
			rightSum = sum;
			//			subArrayEnd=y;
			//			cout<<"the end of the cross sub Array is: "<<subArrayEnd<<endl;
		}
	}
	return leftSum + rightSum;
}//end int crossingSum(int a[], int beg, int mid, int end)

/************************************************
*FUNCTION: maxSum()				*
*Params:an array 'a', an int beg, and int end 	*
*Description:Main function, drives everything  *
*returns max sum regardless if its		*
*on the left, right, or mid side through use 	*
*of the helper functions maximumThree() and 	*
*maximumTwo() above				*
*						*
*function will first check to see if it is a 	*
*single element array and thus the element is 	*
*the max					*
***********************************************/

/************************************************
* Example for function below is too long to 	*
* include as a comment but essentially this 	*
* function will break the array down until 	*
* it hits the if statement			*
***********************************************/
int maxSum(int a[], int beg, int end)
{
	//if beg is the same as end then we have hit the base and can't break it down further 
	if (beg == end)
	{
		return a[beg];
	}
	//determines middle for later functions...this will eventually lead to 1 element and trigger the if() above.
	int mid = ((beg + end) / 2);

	//return statement will envoke another function that will determine that maximum of the left, right, and middle
	//through the use of another function that will directly check two and then return the higher one to maximumThree
	//which will then return the higher of the two numbers.
	//maximumThree will be fed three function calls, 2 calls to this function and 1 to the crossing function as shown below.
	return maximumThree(maxSum(a, beg, mid), maxSum(a, mid + 1, end), crossingSum(a, beg, mid, end));
}//end int maxSum(int a[], int beg, int end)

//HELPER FUNCTIONS BELOW
/************************************************
*FUNCTION: maximumTwo()			*
*Params: two int numbers			*
*Description: Simple if statement returns 	*
*larger of two numbers like the max L and R	*
***********************************************/
int maximumTwo(int numOne, int numTwo)
{
	if (numOne > numTwo)
		return numOne;
	else
		return numTwo;
}//end int maximumTwo(int numOne, int numTwo)

/************************************************
*FUNCTION: maximumThree()			*
*Params: three int numbers			*
*Description: Simple if statement returns 	*
*larger of three numbers with the help of a 	*
*check on two numbers from external func	*
***********************************************/
int maximumThree(int numOne, int numTwo, int numThree)
{
	if (maximumTwo(numOne, numTwo) > numThree)
		return maximumTwo(numOne, numTwo);
	else
		return numThree;
}//end int maximumThree(int numOne, int numTwo, int numThree)

/****************************************************************************
 * Algorithm 4: mSSLinear
 * Parameters: array and var to store right index
 * Description: A function that implements the dynamic progamming solution 
 * of the maximum sum subarray. This function solves the problem by starting 
 * on the left end of the array and solves for subproblems, storing the best
 * solutions as it traverses the array (one time only).
****************************************************************************/

int mSSLinear(vector<int> const &paArray, int &rightIdx){
	rightIdx = 0;
	int bestMax = 0;
	int curMax = 0;

	for (int place = 0; place<paArray.size(); place++){
		curMax = curMax + paArray[place];
		if (curMax < 0){ //the smallest value a subarray can be is the empty set 0
			curMax = 0; //set it back to zero
		}
		if (bestMax < curMax){
			bestMax = curMax; //new biggest subarray
			rightIdx = place;
		}
	}
	/*cout << "index: " << rightIdx << endl;
	cout << " bestMax: " << bestMax << endl;*/
	return bestMax;
}
