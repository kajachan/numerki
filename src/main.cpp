#include <iostream>
#include <vector>
#include "deklaracje.h"
#include <iomanip>
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "C:\\gnuplot\\bin"

using namespace std;

vector <double> wsp;

void tworzenieWykresu(double a, double b, double fun(double), double wynikb, double wyniks);

int main() {
    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
    double a, b, wynikb, wyniks;
    int wyborFunkcji, wyborWariantu;
    bool flag = 0, flag1 = 0;


    //sprawdzenie czy podany wyborFunkcji to 1, 2 lub 3
    cout << setprecision(5) << fixed;
    cout << "Podaj funkcje do zbadania." << endl;
    cout << "1. - 27.3*x - 17.75*x^2 - 8.35*x^3 + 3.2*x^4 + x^5" << endl;
    cout << "2. - 2*sin(2 * x) + 0.3" << endl;
    cout << "3. - 3 * exp(-x*x) - 0.8" << endl;
    cout << "4. - exp(sin(x)) - 1" << endl;
    cout << "5. - exp(x) + cos(x)" << endl;
    cin >> wyborFunkcji;
    if (!(wyborFunkcji == 1 || wyborFunkcji == 2 || wyborFunkcji == 3 || wyborFunkcji == 4 || wyborFunkcji == 5)) {
        cout << "Podaj prawidlowy numer funkcji.\n";
        return 0;
    }

    //sprawdzenie czy podany wyborWariantu to 1 lub 2
    cout << "Podaj wybor wariantu stopu:\n 1.Epsilon\n 2.Iteracje" << endl;
    cin >> wyborWariantu;
    if (!(wyborWariantu == 1 || wyborWariantu == 2)) {
        cout << "Podaj prawidlowy numer wariantu.\n";
        return 0;
    }

    cout << "Wprowadz przedzial szukania." << endl;
    cin >> a >> b;

    if(a > b) {
        swap(a,b);
    }

    int iter;
    double e;
    bool flagType = 0;

    if (wyborFunkcji == 1) {
        if (wielomian(a) * wielomian(b) >= 0) {
            cout << "Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        if (wyborWariantu == 1) {
            cout << "Podaj epsilon: " << endl;
            cin >> e;
            flagType = 1;
            wynikb = bisekcja(a, b, e, wielomian, flagType);
            wyniks = sieczne(a, b, e, wielomian, flagType);
        } else {
            cout << "Podaj ilosc iteracji: " << endl;
            cin >> iter;
            wynikb = bisekcja(a, b ,iter, wielomian, flagType);
            wyniks = sieczne(a, b ,iter, wielomian, flagType);
        }
        cout << "Znalezione miejsce zerowe za pomoca metody bisekcji: " << wynikb << endl;
        cout << "Znalezione miejsce zerowe za pomoca metody siecznych: " << wyniks << endl;
        tworzenieWykresu(a, b, wielomian, wynikb, wyniks);
    } else if (wyborFunkcji == 2) {
        if (trygonometryczna(a) * trygonometryczna(b) >= 0) {
            cout << "Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        if (wyborWariantu == 1) {
            cout << "Podaj epsilon: " << endl;
            cin >> e;
            flagType = 1;
            wynikb = bisekcja(a, b, e, trygonometryczna, flagType);
            wyniks = sieczne(a, b, e, trygonometryczna, flagType);
        } else {
            cout << "Podaj ilosc iteracji: " << endl;
            cin >> iter;
            wynikb = bisekcja(a, b, iter, trygonometryczna, flagType);
            wyniks = sieczne(a, b, iter, trygonometryczna, flagType);
        }
        cout << "Znalezione miejsce zerowe za pomoca metody bisekcji: " << wynikb << endl;
        cout << "Znalezione miejsce zerowe za pomoca metody siecznych: " << wyniks << endl;
        tworzenieWykresu(a, b, wykladnicza, wynikb, wyniks);
    } else if (wyborFunkcji == 3) {
        if (wykladnicza(a) * wykladnicza(b) >= 0) {
            cout << "Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        if (wyborWariantu == 1) {
            cout << "Podaj epsilon: " << endl;
            cin >> e;
            flagType = 1;
            wynikb = bisekcja(a, b, e, wykladnicza, flagType);
            wyniks = sieczne(a, b, e, wykladnicza, flagType);
        } else {
            cout << "Podaj ilosc iteracji: " << endl;
            cin >> iter;
            wynikb = bisekcja(a, b, iter, wykladnicza, flagType);
            wyniks = sieczne(a, b, iter, wykladnicza, flagType);
        }
        cout << "Znalezione miejsce zerowe za pomoca metody bisekcji: " << wynikb << endl;
        cout << "Znalezione miejsce zerowe za pomoca metody siecznych: " << wyniks << endl;
        tworzenieWykresu(a, b, wykladnicza, wynikb, wyniks);
    } else if (wyborFunkcji == 4) {
        if (zlozenie(a) * zlozenie(b) >= 0) {
            cout << "Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        if (wyborWariantu == 1) {
            cout << "Podaj epsilon: " << endl;
            cin >> e;
            flagType = 1;
            wynikb = bisekcja(a, b, e, zlozenie, flagType);
            wyniks = sieczne(a, b, e, zlozenie, flagType);
        } else {
            cout << "Podaj ilosc iteracji: " << endl;
            cin >> iter;
            wynikb = bisekcja(a, b, iter, zlozenie, flagType);
            wyniks = sieczne(a, b, iter, zlozenie, flagType);
        }
        cout << "Znalezione miejsce zerowe za pomoca metody bisekcji: " << wynikb << endl;
        cout << "Znalezione miejsce zerowe za pomoca metody siecznych: " << wyniks << endl;
        tworzenieWykresu(a, b, zlozenie, wynikb, wyniks);
    } else {
        if (zlozenie2(a) * zlozenie2(b) >= 0) {
            cout << "Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        if (wyborWariantu == 1) {
            cout << "Podaj epsilon: " << endl;
            cin >> e;
            flagType = 1;
            wynikb = bisekcja(a, b, e, zlozenie2, flagType);
            wyniks = sieczne(a, b, e, zlozenie2, flagType);
        } else {
            cout << "Podaj ilosc iteracji: " << endl;
            cin >> iter;
            wynikb = bisekcja(a, b, iter, zlozenie2, flagType);
            wyniks = sieczne(a, b, iter, zlozenie2, flagType);
        }
        cout << "Znalezione miejsce zerowe za pomoca metody bisekcji: " << wynikb << endl;
        cout << "Znalezione miejsce zerowe za pomoca metody siecznych: " << wyniks << endl;
        tworzenieWykresu(a, b, zlozenie2, wynikb, wyniks);
    }

     // Dotyczy obliczania wartosci wielomianu na podstawie schematu hornera

    /*cout << "Podaj stopien wielomianu:";
    cin >> stopien;
    for(int i=0;i<=stopien;i++)
    {
        cout << "Podaj wspolczynnik stojacy przy " << stopien-i << " potedze" << endl;
        cin >> wspolczynnik;
        wsp.push_back(wspolczynnik);*/

    //cout<<fwielomianowa(1, wsp);
    //cout<< horner(2, wsp)<<endl;

    return 0;
}

void tworzenieWykresu(double a, double b, double fun(double), double wynikb, double wyniks) {
    vector <double> x(300);
    vector <double> y(300);
    Gnuplot wykres;

    wykres.set_title("Wykres funkcji");
    wykres.set_grid();
    wykres.set_xlabel("OX");
    wykres.set_ylabel("OY");
    wykres.set_xrange(a, b);
    wykres.set_style("points");
    wykres.set_pointsize(1.0);

    while (a <= b) {
        x.push_back(a);
        y.push_back(fun(a));
        a += 0.01;
    }

    wykres.plot_xy(x, y, "Wykres");
    getchar();
    getchar();
}

