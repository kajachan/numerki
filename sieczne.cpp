#include <iostream>
#include <cmath>

using namespace std;

double sieczne(double a, double b, int wariant, double (*f)(double)) {
    int i = 0, iteracje = 0;
    double e = -2.0;
    cout<<"METODA SIECZNYCH"<<endl;
    if (wariant == 1) {
        cout << "Podaj epsilon:" << endl;
        cin >> e;
    } else {
            cout << "Podaj liczbe iteracji: " << endl;
            cin >> iteracje;
    }

    // c = x_{2}, b = x_{1}, a = x_{0}
    double c;

    do {
        c = b - f(b) * (b - a) / (f(b) - f(a));
        a = b;
        b = c;
//        if (f(c) == 0) {
//            cout << "Znalezione miejsce zerowe: " << c << endl;
//             cout << "Ilosc iteracji to " << i;
//            return 0;
//        }
        i++;
    } while ((abs(f(c)) >= e) && (iteracje != i));

    cout << "Znalezione miejsce zerowe to " << c << endl;
    cout << "Ilosc iteracji to " << i<<endl;

    return c;
}
