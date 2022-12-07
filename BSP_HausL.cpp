#include <iostream>
#include <iomanip>

using namespace std;

class Haus;
class Kfz;

class Rad
{
	private:
	  string marke;
	public:
	  Rad(string marke1)
	  {
		  marke = marke1;
	  }
	  string getMarke(){
	  	 return marke;
	  }
};

class Kfz {
    private:
	  double kw;
	  string marke;
	  Rad *rad[4];
    public:
	  Kfz (string marke1, double kw1) {
          kw = kw1;
		  marke = marke1 ;
		  for(int i=0; i<4; i++) rad[i] = NULL;

      } 
      string getMarke(){
      	return marke;
	  }
	  void setRad(int k, Rad *rad1)
	  {
		  if (k >= 0 && k < 4)
		  {
			  rad[k] = rad1;
		  }
	  }
	  Rad *getRad(int i){
	  	if (i>=0 && i<4){
	  		if (rad[i] != NULL){
	  			return rad[i];
			}
		}
		cout << "Kein gueltige Wert oder kein Rad"  << endl;
		return NULL;
	  }
};

class Dach
{
	private:
	  double qm;
	  string typ;
	  Haus *haus;

	public:
	  Dach()
	  {
 		  qm = 0;
		  typ = "";
	  }
	  void setQm (double qm1)
	  {
	  	if (qm1>0){
		      qm = qm1;	  		
		  }
	  }
	  void setTyp (string typ1)
	  {
		   typ = typ1;
	  }
	  double getQm(){
	  	return qm;
	  }
	  string getTyp(){
	  	return typ;
	  }
	void setHaus(Haus *haus1){
		haus = haus1;
	}
};

class Fenster
{
	private:
	  string marke;
	public:
	  Fenster()
	  {
		  marke = "";
	  }
	  void setMarke (string marke1)
	  {
		   marke = marke1;
	  }
	  string getMarke(){
	  	return marke;
	  }
};

class Haus {
    private:
	  double qm;
	  string typ;
	  Dach   dach;
	  Kfz    *kfz[5];
	  Fenster fenster[4];

    public:
	  Haus () {
          qm = 100;
		  typ = "Fertighaus";
		  for(int i=0; i<5; i++) kfz[i] = NULL;
      } 
	  void setDach(double qm1, string typ1)
	  {
   	  	  dach.setQm (qm1);
	  	  dach.setTyp(typ1);
		  dach.setHaus(this);	  
	  }
	  void setFenster(string typ[] )
	  {
		  int i;
		  for (i=0; i<4; i++)
		  {
				fenster[i].setMarke(typ[i]); 
		  }
	  }

	  void setKfz(Kfz *kfz1, int k){
	  	if (k >= 0 && k < 5)
		  {
			  kfz[k] = kfz1;
		  }
	  }
	  Dach *getDach(){
	  	return &dach;
	  }
	  Fenster *getFenster(int i){
	  	 return &fenster[i]; 
	  }
	  Kfz *getKfz(int i){
	  	if (i>=0 && i<5){
	  		if (kfz[i] != NULL){
			  	return kfz[i];		
			  }	
		}
		cout << "Falscher Wert oder kein Auto" << endl;
		return NULL;
	  }
};


int main()
{
	string typ[4]={"Holz1", "Holz2", "Holz3", "Holz4"};
	string radTyp = "Dunlap";
	Haus haus;
	string automarke1= "Porsche";
	string automarke2= "Polo";
	Kfz  a1(automarke1, 390);
	Kfz  a2(automarke2, 57);

	haus.setDach(50, "Ziegeldach"); 
	haus.setFenster(typ); 
	Rad r0("Winterspezial");
	Rad r1("Winterspezial");
	Rad r2("Winterspezial");
	Rad r3("Winterspezial");

	a1.setRad(0, &r0);
	a1.setRad(1, &r1);
	a1.setRad(2, &r2);
	a1.setRad(3, &r3);
	
	Rad r4[4] {(radTyp), (radTyp),(radTyp),radTyp};
	for (int i=0; i<4; i++ ){
		a2.setRad(i, &r4[i]);
	}
	
	haus.setKfz(&a1, 0);
    haus.setKfz(&a2, 1);
	
	/********* AUSGABE ****************/
	cout << "Typ und QM des Daches: " << haus.getDach()->getTyp() << " * " << haus.getDach()->getQm() << endl;
	
	cout << endl << "Marken der Fenster: " << endl;
	for (int i=0; i<4; i++){
		cout << "Fenster " << i+1 << ": " << haus.getFenster(i)->getMarke() << endl;
	}
	cout << endl <<"Autodaten:" << endl;
	cout << "==========================" << endl;
	for (int i=0; i <5; i++){
		cout << "Auto " << i+1 << ": " << endl;
		if (haus.getKfz(i) == NULL) continue;
	
		cout << haus.getKfz(i)->getMarke() << endl;
		for (int k=0; k<4; k++){
			if (haus.getKfz(i)->getRad(k) == NULL) continue;
			cout << "     " << haus.getKfz(i)->getRad(k)->getMarke() << endl;
		}
	}
	
	
	
	/****************************************************************
	Aufgabe:
	1a) Erstelle das Klassendiagramm nur mit den Klassennamen
	1b) Erstelle das Klassendiagrammm mit Eigenschaften und Methoden der Klasse Haus 
	2) Erweitere das Programm derart, dass in der main-Funktion alle Informationen des Hauses ausgegeben werden.
	   Die Klassen müssen dafür um notwendige getter-Methoden erweitert werden.
	3) Erweitere die Methoden so, dass die Eigenschaften keine unzulaessigen Werte annehmen koennen.
	****************************************************************/

	return 0;
}

