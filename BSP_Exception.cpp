/*********************************************************
* Beispiel Exception                                     *
* ===================                                    *
* Wird ein Fehler festgestellt, so wird dieser mit der   *
* throw - Anweisung gemeldet:                            *
* Syntax:  throw  fehlerobjekt;                          *
* fehlerobjekt kann ein beliebiger Datentyp sein.        *
* Z.B. ein string, ein char-Array oder ein Objekt        *
* einer Klasse.                                          *
*                                                        *
* Aufgefangen wird der Fehler mit:                       *
*                                                        *
* try                                                    *
* {                                                      *
*       // Anweisungen, die Exceptions ausloesen koennen *
* }                                                      *
* catch (typ1 var)                                       *
* {                                                      *
*       Behandlung Exception vom Typ 1                   *
* }                                                      *
* ....... // andere Exceptionstypen                      *
* catch (...)     // drei Punkte !!!                     *
* {                                                      *
*      Alle uebrigen Exceptions                          *
* }                                                      *
*                                                        *
* Der Fehler kann in der gleichen Funktion oder in       *
* Funktionen der oberen Hierarchie-Ebene aufgerufen      *
* werden, spaetestens in der main-Funktion.              *
* Wird der Fehler nicht abgefangen, fuehrt dies zum      *
* Programmabbruch!!                                      *
*********************************************************/



#include <iostream>
#include <string>

using namespace std;

class Error
{
public:
    void errorAnzeige()
    {
        cout << "Nenner ist 0 !!!" << endl;
    }
};

double quot (int a, int b)
{
    if (b<0)
    {
        string str="Nenner ist negativ!";
        throw str;
    }
    else if (b==0)
    {
        Error eo;
        throw eo;
    }

    cout << "Return";
    return ((double)a/b);
}

int main ()
{
    int x,y;
    double erg;
    bool flag=false;

    while (flag == false)
    {
        try
        {
            cout << "2 positive ganze Zahlen: ";
            cin >> x >> y;
            erg = quot (x,y);
            cout << "Ergebnis: " << erg;
            flag = true;
        }
        catch (string s)
        {
            // Cout in Rot
            cerr << s << endl;
        }
        catch (Error eo)
        {
            eo.errorAnzeige();
        }
        catch (...)
        {
            cout << "Ausnahmefehler!!";
            exit(1);
        }
    }
    return 0;
}