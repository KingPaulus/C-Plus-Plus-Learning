//
// Created by Paul Merget on 15.02.23.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Interface Spiel
class Spiel {
public:
    virtual void setSpieler(string spieler[]) = 0;
    virtual void spiele() = 0;
};

// Klasse Wuerfelspiel1
class Wuerfelspiel1 : public Spiel {
private:
    string* spieler;
    int anzahlSpieler;
public:
    void setSpieler(string spieler[]) {
        this->spieler = spieler;
        this->anzahlSpieler = sizeof(spieler) / sizeof(spieler[0]);
    }

    void spiele() {
        int ergebnisse[anzahlSpieler];
        for (int i = 0; i < anzahlSpieler; i++) {
            int summe = 0;
            for (int j = 0; j < 3; j++) {
                int wurf = rand() % 6 + 1;
                summe += wurf;
            }
            ergebnisse[i] = summe;
            cout << spieler[i] << " hat " << summe << " Punkte gewürfelt." << endl;
        }

        int maxPunkte = 0;
        int gewinner = -1;
        for (int i = 0; i < anzahlSpieler; i++) {
            if (ergebnisse[i] > maxPunkte) {
                maxPunkte = ergebnisse[i];
                gewinner = i;
            }
        }

        cout << "Das Spiel ist beendet! Der Gewinner ist " << spieler[gewinner] << "." << endl;
    }
};

// Klasse Wuerfelspiel2
class Wuerfelspiel2 : public Spiel {
private:
    string* spieler;
    int anzahlSpieler;
public:
    void setSpieler(string spieler[]) {
        this->spieler = spieler;
        this->anzahlSpieler = sizeof(spieler) / sizeof(spieler[0]);
    }

    void spiele() {
        int ergebnisse[anzahlSpieler];
        for (int i = 0; i < anzahlSpieler; i++) {
            int wurf = rand() % 6 + 1;
            ergebnisse[i] = wurf;
            cout << spieler[i] << " hat " << wurf << " gewürfelt." << endl;
        }

        int maxWurf = 0;
        int gewinner = -1;
        for (int i = 0; i < anzahlSpieler; i++) {
            if (ergebnisse[i] > maxWurf) {
                maxWurf = ergebnisse[i];
                gewinner = i;
            }
        }

        cout << "Das Spiel ist beendet! Der Gewinner ist " << spieler[gewinner] << "." << endl;
    }
};

// Hauptprogramm
int main() {
    srand(time(NULL));
    string spieler[] = {"Paul", "Justus"};

    Spiel* spiel1 = new Wuerfelspiel1();
    spiel1->setSpieler(spieler);
    spiel1->spiele();
    delete spiel1;

    Spiel* spiel2 = new Wuerfelspiel2();
    spiel2->setSpieler(spieler);
    spiel2->spiele();
    delete spiel2;

    return 0;
}
