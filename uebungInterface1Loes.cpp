#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;


class Iban {
public:
    virtual void pruefeIban(string ib) = 0;
    virtual string getIb() = 0;
};

class Iban2 : public Iban {

private:
    string ib;

public:
    void setIb(string ib1) {
        ib = ib1;
    }

    string getIb() {
        return ib;
    }
};

class Fidschi : public Iban2 {

public:
    void pruefeIban(string ib1)  {
        int i, k, wert;
        string meldung;

        if (ib1.length() != 18) {
            meldung = "Falsche Laenge";
            throw (meldung);
        }
        for (i = 2; i < 18; i++) {
            if (ib1[i] < '0' || ib1[i] > '9') {
                throw ("Ziffernfehler");
            }
        }

        if (ib1[0] != 'F' || ib1[1] != 'I') {
            meldung = "Falsche Buchstaben";
            throw (meldung);
        }
        for (i = 2; i < 18; i = i + 4) {
            wert = 0;

            for (k = 3; k >= 0; k--) {
                wert = wert * 10 + ib1[i + k] - '0';
            }
            if (wert % 3 > 0) {
                meldung = "Nicht durch 3 teilbar";
                throw (meldung);
            }
        }
        setIb(ib1);
    }

    string getIb(string ib) {
        return Iban2::getIb();
    }
};

class Caiman : public Iban2 {

public:
    void pruefeIban(string ib1)   {

        int i, k, wert;
        string meldung;

        if (ib1.length() != 18) {
            meldung = "Falsche Laenge";
            throw (meldung);
        }
        for (i = 2; i < 18; i++) {
            if (ib1[i] < '0' || ib1[i] > '9') {
                meldung = "Ziffernfehler";
                throw (meldung);

            }
        }

        if (ib1[0] != 'C' || ib1[1] != 'A') {
            meldung = "Falsche Buchstaben";
            throw (meldung);
        }
        wert = 0;
        for (i = 2; i < 17; i++) {
            wert = wert + ib1[i] - '0';
        }
        if (wert % 10 != ib1[17] - '0') {
            meldung = "Falsche Pruefziffer";
            throw (meldung);
        }
        setIb(ib1);
    }

    string getIb() {
        return Iban2::getIb();
    }

};


int main() {
    Iban *al[10];

    al[0] = new Fidschi();;
    al[1] = new Caiman();
    //       al[0]->setIb("hh");                      // Warum funktioniert dies nicht?

    try {
        al[0]->pruefeIban("FI3363123644432223");
        al[1]->pruefeIban("CA1234123412341236");
        cout << al[0]->getIb() << endl;
        cout << al[1]->getIb() << endl;
    } catch (string e) {
        cout << e << endl;
    }
    catch(...) {
        cout << "unknown error" << endl;
    }
}



