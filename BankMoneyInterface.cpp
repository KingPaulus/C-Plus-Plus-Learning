//
// Created by Paul Merget on 15.02.23.
//
#include <iostream>
#include <string>
#include <exception>
using namespace std;

// Definition des Interfaces Iban
class Iban {
public:
    virtual void pruefeIban(string ib) = 0;
    // Weitere Methoden können hier hinzugefügt werden.
};

// Definition der abstrakten Klasse Iban2, die das Interface Iban implementiert
class Iban2 : public Iban {
protected:
    string iban;

public:
    void setIban(string ib1) {
        iban = ib1;
    }
    string getIban() {
        return iban;
    }
    // Weitere Methoden können hier hinzugefügt werden.
};

// Definition der Klasse Fidschi, die von Iban2 erbt
class Fidschi : public Iban2 {
public:
    void pruefeIban(string ib1) {
        if (ib1.length() != 18 || ib1.substr(0, 2) != "FI") {
            throw runtime_error("Ungültige IBAN: falsche Länge oder falsche Buchstaben");
        }
        for (int i = 2; i < 18; i++) {
            if (!isdigit(ib1[i])) {
                throw runtime_error("Ungültige IBAN: falsche Zeichen");
            }
        }
        int sum = 0;
        for (int i = 0; i < 16; i += 4) {
            int num = stoi(ib1.substr(2 + i, 4));
            if (num % 3 != 0) {
                throw runtime_error("Ungültige IBAN: erstes Quartett nicht durch 3 teilbar");
            }
            sum += num;
        }
        if ((sum % 10) != stoi(ib1.substr(16, 1))) {
            throw runtime_error("Ungültige IBAN: falsche Prüfziffer");
        }
        setIban(ib1);
    }
    // Weitere Methoden können hier hinzugefügt werden.
};

// Definition der Klasse Caiman, die von Iban2 erbt
class Caiman : public Iban2 {
public:
    void pruefeIban(string ib1) {
        if (ib1.length() != 18 || ib1.substr(0, 2) != "CA") {
            throw runtime_error("Ungültige IBAN: falsche Länge oder falsche Buchstaben");
        }
        for (int i = 2; i < 18; i++) {
            if (!isdigit(ib1[i])) {
                throw runtime_error("Ungültige IBAN: falsche Zeichen");
            }
        }
        int sum = 0;
        for (int i = 0; i < 15; i++) {
            sum += (ib1[i] - '0');
        }
        int last_digit = stoi(ib1.substr(15, 1));
        if ((sum % 10) != ((10 - last_digit) % 10)) {
            throw runtime_error("Ungültige IBAN: falsche Prüfziffer");
        }
        setIban(ib1);
    }
    // Weitere Methoden können hier hinzugefügt werden.
};

int main() {
    const int MAX_IBANS = 20;
    Iban* ibans[MAX_IBANS];

    // Erstelle Fidschi-IBANs
    ibans[0] = new Fidschi("FI3333666636991233");
    ibans[1] = new Fidschi("FI4444444444444444");
    ibans[2] = new Fidschi("FI1234123412341234");

    // Erstelle Caiman-IBANs
    ibans[3] = new Caiman("CA1234123412341236");
    ibans[4] = new Caiman("CA9999999999999999");
    ibans[5] = new Caiman("CA1234567890123456");

    // Gib alle IBANs aus
    for (int i = 0; i < MAX_IBANS && ibans[i] != nullptr; i++) {
        try {
            ibans[i]->pruefeIban(ibans[i]->getIban());
            cout << "IBAN " << i+1 << " (" << ibans[i]->getIban() << ") ist gueltig." << endl;
        } catch (exception& e) {
            cout << "IBAN " << i+1 << " (" << ibans[i]->getIban() << ") ist ungueltig: " << e.what() << endl;
        }
    }

    // Gib Speicher frei
    for (int i = 0; i < MAX_IBANS && ibans[i] != nullptr; i++) {
        delete ibans[i];
    }

    return 0;
}

