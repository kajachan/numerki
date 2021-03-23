#include <iostream>
#include <cmath>

using namespace std;

double sieczne(double a, double b, double stop, double (*fun)(double), bool flagType) {
    int liczbaIteracji = 0, i = 0;
    double e = -2.0, c;

    if (flagType) {
        e = stop;
    } else {
        liczbaIteracji = stop;
    }

    // c = x_{2}, b = x_{1}, a = x_{0}

    do {
        c = b - fun(b) * (b - a) / (fun(b) - fun(a));
        a = b;
        b = c;
//        if (fun(c) == 0) {
//            cout << "Znalezione miejsce zerowe: " << c << endl;
//             cout << "Ilosc iteracji to " << i;
//            return 0;
//        }
        i++;
    } while ((liczbaIteracji != i) && (abs(fun(c)) >= e));

    cout << "Ilosc iteracji (sieczne) to: " << i << endl;

    return c;
}
