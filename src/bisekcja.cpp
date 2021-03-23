#include <iostream>
#include <cmath>

using namespace std;

double bisekcja(double a, double b, double stop, double (*fun)(double), bool flagType) {
    int liczbaIteracji = 0, i = 0;
    double e = -2.0, c;

    if (flagType) {
        e = stop;
    } else {
        liczbaIteracji = stop;
    }

    do {
        c = (a + b) / 2;
        if (fun(a) * fun(c) < 0) b = c;
        else a = c;
        i++;
    } while((i != liczbaIteracji) && (abs(fun(c)) >= e));

    cout << "Ilosc iteracji (bisekcja) to: " << i << endl;

    return c;
}