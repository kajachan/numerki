#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

double horner(double x, vector<double> wsp) {

    double wynik = wsp[0];
    for (int i = 1; i <= wsp.size() - 1; i++) {
        wynik = wynik * x + wsp[i];
    }
    return wynik;

}

