//
// Created by Paul Merget on 25.01.23.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class drucker {
private:
    string name;
    double preis;
public:
    drucker (string name1, double preis1){
        name = name1;
        if(preis1 > 0) {
            preis = preis1;
        } else {
            preis = 0;
        }
    }
    void anzeige() {
        cout << "Name: ";
        cout << name << endl;
        cout << "Preis: ";
        cout << preis << endl;
    }

    void serPreis(double neuPreis) {
        if(neuPreis > 0) {
            preis = neuPreis;
        } else {
            string msg;
            throw msg = "Preis Negativ";
        }
    }
};

class druckerstand : drucker {
private:
    int farbstand;
public:
    druckerstand::druckerstand(int farbstand1) : drucker(n){

    }
};

int main() {
    cout << "Geben sie ihr datum ein" << endl;
    drucker drucker1("Drucky", 25.99);
    double newPreis;
    cin >> newPreis;
    drucker1.serPreis(newPreis);
    drucker1.anzeige();

}
