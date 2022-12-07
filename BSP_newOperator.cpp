#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class K1{
	private:
		int z;
	public:
		K1(int z1){ 
			z = z1;
		}
		int getZ(){
			return z;
		}
};

int main()
{
	K1 obj1(5);
	K1 *p1, *p2;
	
	cout << obj1.getZ() << endl;
	
	// new Operator: erstellt ein neues Objekt und liefert die Adresse zurueck
	p1 = new K1(6);
	
	cout << p1->getZ() << endl;
	
	p2 = p1;
	
	cout << p2->getZ() << endl;	
	
	// Arrays:
	K1 arr[4]{(1),2,3,4};
	K1 *pa1;
	
	pa1 = arr;
	cout << pa1[0].getZ() << endl;
	cout << (pa1+1)->getZ() << endl;
	
return 0;
}
