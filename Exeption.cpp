// Created by: Paul Merget

// Diese Beispiel soll Interfaces erklären.
// Exceptions sind eine Art von Klassen, die nur Methoden enthalten, aber keine Variablen.
// Exceptions können nicht instanziiert werden, sondern nur von anderen Klassen implementiert werden.

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


class Mensch{
private:
    string name;
    int alter;
public:
    Mensch (string name2, int alter2){
        name = name2;
        alter = alter2;
    }
    void Beispiel() {
        if(alter == 40) {
            cout << "I'm Forty Years years old.";
        }
        try {
            cout << "I Turn one year older now" << endl;
            int alter = alter + 1;
            throw (alter);
        }
        catch(int catchedAge) {
            cout << "Hey I'm";
            cout << catchedAge;
            cout << "years old." << endl;
        }
    }
};

int main() {
    string name;
    int alter;
    cout << "Erstelle Deine Mensch (Exeptions)" << endl;
    cout << "---------------------------------" << endl;
    cout << "what is your name? " << endl;
    cin >> name;
    cout << "what is your age? " << endl;
    cin >> alter;
    Mensch M1 = *new Mensch(name, alter);
    M1.Beispiel();
    return 0;
}
