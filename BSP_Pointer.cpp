#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	int z=5;
	int *pz;
	
	pz = &z;
	
	cout << z << " # " << pz << " # " << *pz << " # " << &z << endl;	

}
