#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Iban {
public:
    virtual void pruefeIban(string ib) = 0;
    virtual string getIban() = 0;
};


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
};
class Fidschi : public Iban2 {
public:
    Fidschi(string iban){
        setIban(iban);
    }
    void pruefeIban(string ib1) override {
        string quartett;
        if (ib1.substr(0, 2) != "FI") {
            throw "Buchstaben falsch";
        }
        if (ib1.length() != 18) {
            throw "Laenge falsch";
        }
        for (char c : ib1) {
            if (!isdigit(c) && !isalpha(c)) {
                throw "falsche Zeichen";
            }
        }
        for (int i = 2; i < 18; i += 4) {
            quartett = ib1.substr(i, 4);
            int zahl = stoi(quartett);
            if (zahl % 3 != 0) {
                throw "Zahl nicht durch 3 teilbar";
            }
        }
        setIban(ib1);
    }
};
class Caiman : public Iban2 {
public:
    Caiman(string iban) {
        setIban(iban);
    }
    void pruefeIban(string ib1) override {
        int summe = 0;
        int pruefziffer;
        if (ib1.substr(0, 2) != "CA") {
            throw "Buchstaben falsch";
        }
        if (ib1.length() != 18) {
            throw "Laenge falsch";
        }
        for (char c : ib1) {
            if (!isdigit(c) && !isalpha(c)) {
                throw "falsche Zeichen";
            }
        }
        for (int i = 2; i < 17; i++) {
            char c = ib1[i];
            int zahl;
            if (isdigit(c)) {
                zahl = c - '0';
            } else {
                throw "Falsche Iban";
            }
            summe += zahl;
        }
        pruefziffer = summe % 10;
        if (pruefziffer != ib1[17] - '0') {
            throw "Pruefziffer falsch";
        }
        setIban(ib1);
    }
};
int main() {
    int max = 20;
    Iban2* iban[max];
    try {
        Fidschi fidschi1("FI3333666636991233");
        fidschi1.pruefeIban("FI3333666636991233");
        cout << fidschi1.getIban() <<endl;
        Caiman caiman1("FI3333666636991233");;
        caiman1.pruefeIban("CA1234123412341236");
        cout << caiman1.getIban() <<endl;
    }
    catch (const char* msg){
        cout << msg;
    }
    catch (...)
    {
        cout << "Ausnahmefehler!!";
        exit(1);
    }
    return 0;
}