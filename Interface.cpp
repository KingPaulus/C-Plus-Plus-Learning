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
    Mensch (string name2, int alter2){
        name = name2;
        alter = alter2;
    }
    void Beispiel() {
        cout << "Test";
    }
};

int main() {
    Mensch J1 = *new Mensch("John", 40);
    J1.Beispiel();
    return 0;
}