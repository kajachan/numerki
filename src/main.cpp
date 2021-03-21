#include <iostream>
#include <vector>
#include "deklaracje.h"
#include <cmath>
#include <iomanip>
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "C:\\gnuplot\\bin"

using namespace std;

vector <double> wsp;

double trygonometryczna(double x);
double wykladnicza(double x);
double zlozenie(double x);
void tworzenieWykresu(double f (double), double l, double r);

int main() {
    double wspolczynnik,stopien,a,b,lp,pp;
    int wyborFunkcji, wyborWariantu;
    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);

    cout << setprecision(10) << fixed;

    bool flag1 = 0;

    //sprawdzenie czy podany wyborFunkcji to 1, 2 lub 3
    while(!flag1) {
        cout << "Podaj funkcje do zbadania.\n1. - sin(2*x)+x+1.5\n2. - 2*exp(-x)-4*x*x\n3. - exp(sin(x))-1\n" << endl;
        cin >> wyborFunkcji;
        if (wyborFunkcji == 1 || wyborFunkcji == 2 || wyborFunkcji == 3) {
            flag1 = 1;
        } else {
            cout << "Podaj prawidlowy numer funkcji\n";
        }
    }

    //sprawdzenie czy podany wyborWariantu to 1 lub 2
    bool flag = 0;
    while(!flag) {
        cout << "Podaj wybor Wariantu stopu:\n 1.Epsilon\n 2.Iteracje" << endl;
        cin >> wyborWariantu;
        if (wyborWariantu == 1 || wyborWariantu == 2) {
            flag = 1;
        } else {
            cout << "Podaj prawidlowy numer wariantu\n";
        }
    }
    cout << "Wprowadz przedzial szukania." << endl;
    cin >> a >> b;
    if(a > b) {
        swap(a,b);
    }
    if (wyborFunkcji == 1) tworzenieWykresu(trygonometryczna, lp, pp);
    else if (wyborFunkcji == 2) tworzenieWykresu(wykladnicza, lp, pp);
    else if (wyborFunkcji == 3) tworzenieWykresu(zlozenie, lp, pp);

    if (wyborFunkcji == 1) {
        if (trygonometryczna(a) * trygonometryczna(b) >= 0)
        {
            cout <<"Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        bisekcja(trygonometryczna, a, b, wyborWariantu);
        sieczne(a, b, wyborWariantu, trygonometryczna);
    } else if (wyborFunkcji == 2) {
        if (wykladnicza(a) * wykladnicza(b) >= 0)
        {
            cout <<"Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        bisekcja(wykladnicza, a , b , wyborWariantu);
        sieczne(a, b, wyborWariantu, wykladnicza);
    } else if (wyborFunkcji == 3) {
        if (zlozenie(a) * zlozenie(b) >= 0) {
            cout << "Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        bisekcja(zlozenie, a, b, wyborWariantu);
        sieczne(a, b, wyborWariantu, zlozenie);
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
    //cout<< Horner(2, wsp)<<endl;




    return 0;
}

// funkcje do zbadania

double trygonometryczna(double x) {
    return sin(2 * x) + x + 1.5;
}

double wykladnicza(double x) {
    return 2 * exp(-x) - 4 * x * x;
}

double zlozenie(double x) {
    return exp(sin(x)) - 1;
}

// tworzenie wykresu
void tworzenieWykresu(double f (double), double l, double r)
{
    Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
    Gnuplot main_plot;
    main_plot.set_title("Wykres");
    main_plot.set_grid();
    main_plot.set_xrange(l, r) ;
    main_plot.set_xlabel("X");
    main_plot.set_ylabel("Y");

    main_plot.set_style( "points" );
    main_plot.set_pointsize(2.0);
    vector <double> x(200);
    vector <double> y(200);

    while (l <= r)
    {
        x.push_back(l);
        y.push_back(f(l));
        l+=0.005;
    }
    main_plot.plot_xy( x, y, "wykres" );
    getchar();
    getchar();
}