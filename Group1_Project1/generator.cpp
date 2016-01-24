#include <iostream> 
#include <ctime> 
// Needed for the true randomization 
#include <cstdlib> 
#include <fstream>
using namespace std; 

int main () { 

long long int num;

cout << "How many " << endl;
cin >> num;


int xRan;
ofstream writefile;
writefile.open("wasd.txt");
writefile << "[" ;


srand(time(0)); 
int i;
while (i < num) {
	// This will ensure a really randomized number by help of time. 
	xRan=(rand()%1000)-500; 
	writefile << xRan;	
	writefile << ", ";
		if (i == num-1){
			writefile << xRan;
		}
	i++;

}
writefile << "]" ;

writefile.close();
return 0; 
}
