// Created by paul merget on 15.03.2023

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Vogel {
private:
    string name;
public:
    Vogel(string name1){
        name = name1;
    }
    virtual void anzeige() = 0;
    virtual void setRing(string ring1) = 0;
};

class Zugvogel : Vogel {
private:
    int flugdauer;
    string ring = "";
    string name;
public:
    Zugvogel(int dauer1, string name1) : Vogel(name1) {
        setFlugdauer(dauer1);
        name = name1;
    }
    void anzeige() {
        cout << "Zugvogel: " << name << " " << ring << " " << flugdauer << endl;
    }
    void setFlugdauer(int dauer1) {
        if(dauer1 > 0) {
            flugdauer = dauer1;
        } else {
            // Wert auf -1 wenn ein falscher Wert gesetzt ist
            flugdauer = -1;

            // Falscher Wert Throw exception
            string meldung = "Falscher Wert";
            throw (meldung);
        }
    }
    void setRing (string ring1) {
        if(ring1.size() == 10) {
            for (int i = 0; i < ring1.size(); i++) {

                // Prüfe nach Buchstaben von A-M
                if (ring1[i] == 'A' || ring1[i] == 'B' || ring1[i] == 'C' || ring1[i] == 'D' || ring1[i] == 'E' ||
                    ring1[i] == 'F' || ring1[i] == 'G' || ring1[i] == 'H' || ring1[i] == 'I' || ring1[i] == 'J' ||
                    ring1[i] == 'K' || ring1[i] == 'L' || ring1[i] == 'M') {

                    // Prüfe nach Doppelung
                    if (i != 0 && ring1[i] == ring1[i - 1]) {
                        string meldung = "Gleiche Buchstaben direkt hintereinander";
                        throw (meldung);
                    }
                } else {
                    string meldung = "enthaelt ungeltige Zeichen";
                    throw (meldung);
                }
            }
        } else {
            string meldung = "Laenge falsch";
            throw (meldung);
        }
        ring = ring1;
    }
};

class Standvogel : Vogel {
private:
    string nestort;
    string ring = "";
    string name;
public:
    Standvogel(string nestort1, string name1) : Vogel(name1) {
        nestort = nestort1;
        name = name1;
    }
    void anzeige() {
        cout << "Standvogel: " << name << " " << ring << " " << nestort << endl;
    }
    void setRing (string ring1) {
        if(ring1.size() == 10) {
            if(ring1[0] != 'S') {
                string meldung = "Erster Buchstabe falsch";
                throw (meldung);
            }
            // rechne Prüf summe
            int pruef = ring1[1]-ring1[2]+ring1[3]-ring1[4]+ring1[5]-ring1[6]+ring1[7]-ring1[8];

            // Wenn der Wert Negativ ist, rechne ihn ins Positive um
            if(pruef < 0) {
                pruef = pruef - pruef - pruef;
            }

            // Conventiere das Array index 9 zu einem String
            int lastZiffer = ring1[9] - '0';

            // Prüfe prüfeziffer
            if(lastZiffer != pruef) {
                string meldung = "Pruefziffer ist falsch";
                throw (meldung);
            }

        } else {
            string meldung = "Laenge falsch";
            throw (meldung);
        }
        ring = ring1;
    }
};

int main() {
    Zugvogel Z1 = *new Zugvogel( 23, "Fink");
    Zugvogel Z2 = *new Zugvogel( 23, "Amsel");
    Standvogel S1 = *new Standvogel("Baum1", "Star");
    Standvogel S2 = *new Standvogel("Baum1", "Meise");

    try {
        // Z1.setRing("CFADGCJHKN"); Fehler wegen N
        Z1.setRing("ABCDEFGHIJ");
        Z2.setRing("FDFCDFCDFC");
        S1.setRing("S123456713");
        S2.setRing("S123456722");


        Z1.anzeige();
        Z2.anzeige();
        S1.anzeige();
        S2.anzeige();

    } catch (string error) {
        cerr << error << endl;
    }
    catch(...) {
        cout << "Unbekannter Fehler" << endl;
    }
}
