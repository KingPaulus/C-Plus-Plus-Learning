//
// Created by Paul Merget on 15.02.23.
//

#include "Array_2D.h"

#include <iostream>
#include <vector>
using namespace std;

int bewertung(int kategorie)
{
    int bewertung = 5;
    return bewertung;
}

float vkinput(int kategorie)
{
    float average = 100;
    return average;
};

float kostenInput(int kategorie)
{
    float costavg = 80;
    return costavg;
}

float ergebnis(int kategorie)
{
    float ertrag = 0;
    float kosten = 0;
    float ergebnis = 0;
    ertrag = vkinput(0);
    kosten = kostenInput(0);
    ergebnis = ertrag - kosten;
    return ergebnis;
}

void erzeugeKategorieliste()
{
    int kategorieliste[4][5] = {
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0},
            {0,0,0,0,0}			   };

    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            kategorieliste[i][0] = i + 1;
            kategorieliste[i][1] = vkinput(i+1);
            kategorieliste[i][2] = kostenInput(i+1);
            kategorieliste[i][3] = ergebnis(i+1);
            kategorieliste[i][4] = bewertung(i+1);
        }
    }

    for (i = 0; i < 4; i++)							// output(kategorieliste);
    {
        for (j = 0; j < 5; j++)
        {
            cout << kategorieliste[i][j] << " ";

        }
        cout << endl;
    }
}

int main()
{
    erzeugeKategorieliste();
}
