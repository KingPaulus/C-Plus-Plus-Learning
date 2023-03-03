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
            alter = 41;
        }
        try {
            int alter = alter + 1;

            throw (alter);
        }
        catch(int i) {
            cout << "Mein alter ist: ";
            cout << i;
        }
    }
};

int main() {
    Mensch J1 = *new Mensch("John", 40);
    J1.Beispiel();
    return 0;
}
