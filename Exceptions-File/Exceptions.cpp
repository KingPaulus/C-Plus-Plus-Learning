#include <iostream>
#include <sstream>
#include <string>


using namespace std;

void ein_string(string dat) {
    string arr[3];
    int i = 0;
    stringstream ssin(dat);
    while (ssin.good() && i < 4){
        ssin >> arr[i];
        ++i;
    }
    for(i = 0; i < 4; i++){
        cout << arr[i] << endl;
    }
}

void ein_int (int t, int m, int y) {
    cout << "Wir haben den ";
    cout << t;
    cout << " -  ";
    cout << m;
    cout << " im Jahre ";
    cout << y;
    cout << "" << std::endl;
}

int main() {
    std::cout << "Geben sie ihr datum ein" << std::endl;
    int day;
    int month;
    int year;

    std::cout << "Geben sie ein Tag an" << std::endl;
    std::cin >> day;

    std::cout << "Geben sie ein Monat an" << std::endl;
    std::cin >> month;

    std::cout << "Geben sie ein Jahr an" << std::endl;
    std::cin >> year;
    return 0;
}
