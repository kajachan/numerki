#include <iostream>
#include <vector>
#include "deklaracje.h"
#include <iomanip>
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "C:\\gnuplot\\bin"

using namespace std;

vector <double> wsp;

// tworzenie wykresu
void tworzenieWykresu(double a, double b, double fun(double), double wynikb, double wyniks) {
    vector <double> x(300);
    vector <double> y(300);
    Gnuplot wykres;

    wykres.set_title("Wykres funkcji" );
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

    wykres.plot_xy(x, y, "Wykres" );
    getchar();
    getchar();
}

// main
int main() {
    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
    double a, b;
    double wynikb, wyniks;
    int wyborFunkcji, wyborWariantu;
    bool flag = 0, flag1 = 0;
    cout << setprecision(10) << fixed;

    //sprawdzenie czy podany wyborFunkcji to 1, 2 lub 3
    cout << "Podaj funkcje do zbadania.\n1. - sin(2*x)+x+1.5\n2. - 2*exp(-x)-4*x*x\n3. - exp(sin(x))-1\n" << endl;
    cin >> wyborFunkcji;
    if (!(wyborFunkcji == 1 || wyborFunkcji == 2 || wyborFunkcji == 3)) {
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
    double eps;
    bool flagType = 0;

    if (wyborFunkcji == 1) {
        if (trygonometryczna(a) * trygonometryczna(b) >= 0) {
            cout << "Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        if (wyborWariantu == 1) {
            cout << "Podaj epsilon: " << endl;
            cin >> eps;
            flagType = 1;
            wynikb = bisekcja(a, b, eps, trygonometryczna, flagType);
            wyniks = sieczne(a, b, eps, trygonometryczna, flagType);
        } else {
            cout << "Podaj ilosc iteracji: " << endl;
            cin >> iter;
            wynikb = bisekcja(a, b ,iter, trygonometryczna, flagType);
            wyniks = sieczne(a, b ,iter, trygonometryczna, flagType);
        }
        cout << "Znalezione miejsce zerowe za pomoca metody bisekcji: " << wynikb << endl;
        cout << "Znalezione miejsce zerowe za pomoca metody siecznych: " << wyniks << endl;
//          tworzenieWykresu(a, b, trygonometryczna, wynikb, wyniks);
    } else if (wyborFunkcji == 2) {
        if (wykladnicza(a) * wykladnicza(b) >= 0) {
            cout << "Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        if (wyborWariantu == 1) {
            cout << "Podaj epsilon: " << endl;
            cin >> eps;
            flagType = 1;
            wynikb = bisekcja(a, b, eps, wykladnicza, flagType);
            wyniks = sieczne(a, b, eps, wykladnicza, flagType);
        } else {
            cout << "Podaj ilosc iteracji: " << endl;
            cin >> iter;
            wynikb = bisekcja(a, b, iter, wykladnicza, flagType);
            wyniks = sieczne(a, b, iter, wykladnicza, flagType);
        }
        cout << "Znalezione miejsce zerowe za pomoca metody bisekcji: " << wynikb << endl;
        cout << "Znalezione miejsce zerowe za pomoca metody siecznych: " << wyniks << endl;
//          tworzenieWykresu(a, b, wykladnicza, wynikb, wyniks);
    } else {
        if (zlozenie(a) * zlozenie(b) >= 0) {
            cout << "Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        if (wyborWariantu == 1) {
            cout << "Podaj epsilon: " << endl;
            cin >> eps;
            flagType = 1;
            wynikb = bisekcja(a, b, eps, wykladnicza, flagType);
            wyniks = sieczne(a, b, eps, wykladnicza, flagType);
        } else {
            cout << "Podaj ilosc iteracji: " << endl;
            cin >> iter;
            wynikb = bisekcja(a, b, iter, zlozenie, flagType);
            wyniks = sieczne(a, b, iter, zlozenie, flagType);
        }
        cout << "Znalezione miejsce zerowe za pomoca metody bisekcji: " << wynikb << endl;
        cout << "Znalezione miejsce zerowe za pomoca metody siecznych: " << wyniks << endl;
        tworzenieWykresu(a, b, zlozenie, wynikb, wyniks);
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

