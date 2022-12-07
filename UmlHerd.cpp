
#include <iostream>
#include <iomanip>

using namespace std;
 
class Platte {
    private:
	  int watt;
    public:
	void setWatt(int watt1)
    {
        watt = watt1;
    }
    int getWatt()
    {
        return watt;
    }       
};
class Blech {
    private:
	  double groesse;
    public:
	Blech (double groesse1)
    {
        groesse = groesse1;
    }
    double getGroesse()
    {
        return groesse;
    }
};

class Backofen {
    private:
	  int watt;
      Blech *blech[];
    
    public:
	Backofen(){
        int i;
        
        for (i=0; i<4; i++)
        {
            blech[i] = NULL;
        }
    }
    
    void setWatt(int watt1){
        watt = watt1;
    }
    int getWatt(){
        return watt;
    }
    Blech *getBlech(int i){
        if (i>=0 && i <=3)
        {
            return blech[i];
        }
        return NULL;
    }
    
    void addBlech(Blech *blech1){
        int i=0;
        for (i=0;i<4;i++)
        {
            if (blech[i] == NULL)
            {
                blech[i] = blech1;
                return;
            }          
        }
        cout << "Kein Platz mehr frei" << endl;
    }
};

class Herd {
    private:
	  string typ;
      Platte platte[4];
      Backofen backofen;
    public:
		Herd(string typ1){
	        typ = typ1;
	    }
	    Platte *getPlatte(int i) {
	    	if (i>=0 && i<4)
	            return &platte[i];
	        cout << "Falscher Parameter" << endl;
	        return NULL;
	    }
	    void setWattPlatten(){
	        int i;
	        for (i=0;i<4;i++)
	        {   
	            platte[i].setWatt((i+1)*50);
	        }
	    }
	    void setWattBackofen(int watt1){
	        backofen.setWatt(watt1);
	    }
	    Backofen *getBackofen(){
	        return &backofen;
	    }
	    void anzeige(){
	        int i;
	        cout << "Typ:" << typ << endl;
	        for (i=0;i<4;i++)
	        {
	            cout << "Plattenleistung von platte " << (i+1) << ":" << platte[i].getWatt() << endl;
	        }
	        cout <<"Backofenleistung:" << backofen.getWatt() << endl;
	        for (i=0;i<4;i++)
	        {
	            if (backofen.getBlech(i) == NULL)
	            {
	                break;
	            }
	            cout << "Groesse Blech" << (i+1) << ":" << backofen.getBlech(i)->getGroesse() << endl;
	            
	        }  
	    }
};
 



int main() {
      
        int i;
        string typ="AEG";
        Herd herd(typ);

        Blech blech1(200.9);
        Blech blech2(150.0);

        herd.getBackofen()->addBlech(&blech1);
        herd.getBackofen()->addBlech(&blech2);
    
        herd.setWattPlatten();

        herd.setWattBackofen(800);
        
        for (i=0;i<4;i++)
        {
                 cout << "Plattenleistung von platte " << (i+1) << ":" 
                         << herd.getPlatte(i)->getWatt() << endl;
        }
        cout <<"Backofenleistung:" << herd.getBackofen()->getWatt() << endl;
        for (i=0;i<4;i++)
        {
            if (herd.getBackofen()->getBlech(i)!= NULL)
            {
                cout << "Groesse Blech" << (i+1) << ":" 
                        << herd.getBackofen()->getBlech(i)->getGroesse() << endl;
            
             }  
        }
    }



