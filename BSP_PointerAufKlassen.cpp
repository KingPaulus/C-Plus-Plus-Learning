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

class K2{
	public:
		int zahl;
};

class K3{
	private:
		K2 ok2;
		K1 *pk1[3];
	
	public:	
		K1 *getPk1(int i){
			return pk1[i];
		}
		void setPk1(K1 *pk11, int i){
			pk1[i] = pk11;
		}
		
		K2 *getOk2(){
			return &ok2;
		}		
};

int main()
{
	K1 ok1(89);
	K3 ok3;
	
	ok3.setPk1(&ok1, 0);
	cout << ok3.getPk1(0)->getZ() << endl;
	
	ok3.getOk2()->zahl = 47;
	cout << ok3.getOk2()->zahl << endl;
	
return 0;
}
