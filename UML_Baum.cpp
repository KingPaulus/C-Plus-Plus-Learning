
#include <iostream>
#include <iomanip>

using namespace std;

class Gartenbank;

class Blatt {

    private:
	  string farbe;

    public:
	  Blatt(string farbe1) {
        farbe = farbe1;
      }
      string getFarbe() { return farbe; }
};

class Baum {

    private:
	  string name;
      Blatt *blaetter[1000];
	  Gartenbank *bank;

    public:
     Baum(){
     	for (int i=0; i<1000; i++){
     		blaetter[i] = NULL;
		 }
		 bank = NULL;
	 }
	 void addBlatt(Blatt *blatt) {
	 	int i;
        for (i=0; i<1000; i++){
        	if (blaetter[i] == NULL){
        		blaetter[i] = blatt;
        		return;
			}	
		}
		cout << "Kein Platz mehr!" << i <<endl;
    }

    void addGartenbank(Gartenbank *b) {
        bank = b;
    }
    Gartenbank *getGartenbank() {
        return bank;
    }
 
 	void setName (string name1){
 		int i, qs;
 		name = "";
 
 	    if (name1.length() != 6){
 	    	cout << "Falsche Laenge" << endl;
 	    	return;
		 } 
 
  		if (name1[0] != 'B') {
 			cout << "Falscher Anfangsbuchstabe" << endl;
 			return;
		 }
 
 		qs = 0;
 		for (i=1; i<5; i++)		
 		{
 			if (name1[i] < '0' || name1[i] > '9') {
 				cout << "Buchstabe statt Ziffer" << endl;
 				return;
			 }
			 qs = qs + (int) (name1[i] - '0');
		 }
 	//	cout << qs << "##" << name1[5] << endl;
 		 qs = qs%10;
 		 if (qs != name1[5] - '0') {
 		 	 cout << "falsche Pruefziffer" << endl;
 		 	 return;
		  }
		  name = name1;
 		
	 }
 
    string getName() { return name;}
 
    Blatt *getBlatt(int i) { 
		if (i>= 0 && i < 1000){
			return blaetter[i];
		}
		cout << "Falscher Parameter" << endl;
		return NULL;
	}
};

class Gartenbank {

    private:
	  int sitze;
      Baum *baum;
      
    public:
	  Gartenbank(int sitze1) {
        sitze = sitze1;
      }
      int getSitze() { return sitze;}

      void setBaum(Baum *baum1){
      	 baum = baum1;
	  }
	  Baum *getBaum() {
	  	return baum;
	  }
};

int main() {

         int i, k;
         string farbe[100];
         int    anz[100];
         string name="B44446";
         
         Baum b1;
         Blatt *blt;
         Gartenbank gb(4);
         b1.addGartenbank(&gb);
         b1.setName(name);
         
         for (i=0; i < 12; i++) b1.addBlatt(new Blatt("gruen"));
         for (i=0; i < 23; i++) b1.addBlatt(new Blatt("rot"));
         for (i=0; i < 44; i++) b1.addBlatt(new Blatt("gelb"));
         
         for (i=0; i<100; i++)   farbe[i] = "";
         for (i=0; i<100; i++)   anz[i] = 0;
         
         for (int i=0; i<1000; i++)
         {
			 blt = b1.getBlatt(i);
			 if (blt == NULL) continue;
             for (k=0; k<100;k++)
             {
                 if (blt->getFarbe() == farbe[k] && farbe[k] != "")
                 {
                     anz[k]++;
                     break;
                 }
                 else if (farbe[k] == "")
                 {
                     farbe[k] = blt->getFarbe();
                     anz[k] = 1;
                     break;
                 }
             }
         }
         
         for (i=0; i < 3; i++) 
         {
             cout << farbe[i] << "         : " << anz[i] << endl;
         }
		 cout << endl << "Anzahl Sitze der Parkbank: " << b1.getGartenbank()->getSitze() << endl;
         cout << "Baumname: " << b1.getName() << endl;
         
    return 0;
};


