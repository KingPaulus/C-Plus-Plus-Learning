// Created by: Paul Merget

// Diese Beispiel soll Interfaces erklären.
// Interfaces sind eine Art von Klassen, die nur Methoden enthalten, aber keine Variablen.
// Interfaces können nicht instanziiert werden, sondern nur von anderen Klassen implementiert werden.

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class verzeichnis {
public:
    virtual void Beispiel() = 0;
};

class Mensch : verzeichnis {
private:
    string name;
    int alter;
public:
    Mensch (string name2, int alter2) {
        name = name2;
        alter = alter2;
    }
    void Beispiel() {
        cout << "Hello there, I'm " + name + " and I'm " + to_string(alter) + " years old." << endl;
    }
};

int main() {
    string name;
    int alter;
    cout << "Erstelle Deine Mensch (Interface)" << endl;
    cout << "---------------------------------" << endl;
    cout << "what is your name? " << endl;
    cin >> name;
    cout << "what is your age? " << endl;
    cin >> alter;
    Mensch M1 = *new Mensch(name, alter);
    M1.Beispiel();
    return 0;
}