// Iban.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Iban
{
public:
    virtual void prufeIban(string ib) = 0;
    virtual string getIban() = 0;

};

class Iban2 : public Iban {

private:
    string iban;

public:

    void setIban(string ib) {
        iban = ib;
    }

    string getIban() {
        return iban;
    }

};

class Fidschi : public Iban2
{
public:
    Fidschi(string iban) {
        setIban(iban);
    }

    void prufeIban(string ib) {
        string error = "";
        if (ib.size() != 18) {
            error = "Laenge falsch";
            throw error;
        }

        if (ib.at(0) != 'F' || ib.at(1) != 'I') {
            error = "Buchstaben falsch";
            throw error;
        }

        string ziffern = ib.substr(2);

        for (int i = 0; i < 4; i++) {
            int block = 0;
            try {
                block = stoi(ziffern.substr(i * 4, 4));
            }
            catch (string s) {
                error = "Falsche Zeichen!";
                throw error;
            }
            if (block % 3 != 0) {
                error = "Block " + to_string(i) + " ist nicht durch 3 teilbar!";
                throw error;
            }

        }
    }

};

class Caiman : public Iban2
{
public:
    Caiman(string iban) {
        setIban(iban);
    }

    void prufeIban(string ib) {
        string error = "";
        if (ib.size() != 18) {
            error = "Laenge falsch";
            throw error;
        }

        if (ib.at(0) != 'C' || ib.at(1) != 'A') {
            error = "Buchstaben falsch";
            throw error;
        }

        int sum = 0;
        ib = ib.substr(2);
        for (int i = 0; i < 5; i++) {
            int block = 0;
            try {
                int block = stoi(ib.substr(i * 3, 3));
                sum += berechneQuersumme(block);
            }
            catch (string s) {
                error = "Falsche Zeichen!";
                throw error;
            }

        }
        int pruf = ib.at(ib.size() - 1) - '0';


        if (sum % 10 != pruf) {
            error = "Pruefziffer falsch";
            throw error;
        }
    }

private:
    int berechneQuersumme(int zahl) {
        int summe = 0;
        while (0 != zahl) {
            summe = summe + (zahl % 10);
            zahl = zahl / 10;
        }
        return summe;
    }

};


int main()
{
    vector<Iban*> ib;


    ib.push_back(new Fidschi("FI3333666636991233"));
    ib.push_back(new Fidschi("FI45819C7081217632"));
    ib.push_back(new Fidschi("FI5055485208017410"));
    ib.push_back(new Fidschi("FI1151999033064875"));
    ib.push_back(new Fidschi("FB1824398145723681"));
    ib.push_back(new Fidschi("FI8544981939999"));

    ib.push_back(new Caiman("CR1234123412341236"));
    ib.push_back(new Caiman("CA68225H1387436589"));
    ib.push_back(new Caiman("CA1357695428952387"));
    ib.push_back(new Caiman("CA11111111111115"));
    ib.push_back(new Caiman("CA3842658726914588"));
    ib.push_back(new Caiman("CA5894369821684597"));

    for (Iban* i : ib) {
        try {

            i->prufeIban(i->getIban());
            cout << "Iban " << i->getIban() << " passed!" << endl;
        }
        catch (string e) {
            cout << "Iban: " << i->getIban() << " failed!" << endl;
            cout << e << endl;
        }
    }
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
