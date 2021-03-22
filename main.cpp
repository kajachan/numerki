#include <iostream>
#include <vector>
#include "deklaracje.h"
#include <cmath>
#include <iomanip>
#include "gnuplot_i.hpp"
#define GNUPLOT_PATH "C:\\gnuplot\\bin"

using namespace std;

vector <double> wsp;

double wielomian(double x);
double trygonometryczna(double x);
double wykladnicza(double x);
double zlozenie(double x);
double zlozenie2(double x);
void tworzenieWykresu(double f (double), double l, double r);


int main() {
    double wspolczynnik,stopien,a,b,lp,pp;
    //char wybor;
    int wybor2,wariant;
    //Gnuplot::set_GNUPlotPath(GNUPLOT_PATH);
    //Gnuplot main_plot;

    // Podpisy na wykresie, zeby bylo wiadomo co na nim widac
    //main_plot.set_title( "tytul wykresu" );
    //main_plot.set_xlabel( "podpis osi odcietych" );
    //main_plot.set_ylabel( "podpis osi rzednych" );

//    // styl rysowania wykresu
//    main_plot.set_style( "lines" );
//
//    // siatka poprawia czytelnosc
//    main_plot.set_grid();
//
//    // zakres osi x
//    main_plot.set_xrange( 0 , 6 ) ;
//
//    // funkcja do narysowania
//    // UWAGA: poniĹĽszy przykĹ‚ad sĹ‚uĹĽy jedynie zademonstrowaniu, ĹĽe gnuplot jest w
//    // stanie rysowaÄ‡ wykresy na podstawie wzoru funkcji. ProszÄ™ jednak pamiÄ™taÄ‡,
//    // ĹĽe zgodnie z wytycznymi zamieszczonymi na Wikampie nie wolno z tej
//    // moĹĽliwoĹ›ci korzystaÄ‡. Dane do wykresu zawsze naleĹĽy przekazywaÄ‡ w tablicy -
//    // przykĹ‚ad poniĹĽej.
//    main_plot.plot_equation( "sin(x)", "opcjonalnie podpis w legendzie" ) ;
//
//    // teraz narsujemy kilka punktow. Na poczatek zmiana stylu rysowania:
//    main_plot.set_style( "points" );
//    main_plot.set_pointsize( 2.0 );
//
//    // Tworzenie danych do wykresu. Potrzebne sa dwa wektory STL. Jeden opisuje
//    // polozenie punktow na osi X, drugi na osi Y. W rzeczywistym programie
//    // dane nie beda oczywiscie wpisywane na sztywno w kodzie, a wyliczane w oparciu
//    // o parametry wprowadzone przez uzytkownika.
    vector<double> x( 3 );
    x[ 0 ] = 0.5;
    x[ 1 ] = 3.0;
    x[ 2 ] = 4.0;

    //main_plot.plot_x(x, "podpis - opcjonalnie" );
//
//    // czekamy na nacisniecie klawisza Enter
//    getchar();

//    FILE *fp;
//    int status;
//    fp = _popen("C:\\Program\" \"Files\\gnuplot\\bin\\wgnuplot.exe","w");
//    fprintf(fp, "plot sin(x)\n");
//    fprintf(fp, "plot tan(x)\n");
//
//    pclose(fp);


    cout << setprecision(5) << fixed;
    cout << "Podaj funkcje do zbadania." << endl;
    cout << "1. - 27.3*x - 17.75*x^2 - 8.35*x^3 + 3.2*x^4 + x^5" << endl;
    cout << "2. - 2*sin(2 * x) + 0.3" << endl;
    cout << "3. - 3 * exp(-x*x) - 0.8" << endl;
    cout << "4. - exp(sin(x)) - 1" << endl;
    cout << "5. - exp(x) + cos(x)" << endl;
    cin >> wybor2;


    //sprawdzenie czy podany wariant to 1 lub 2
    bool sprawdz = 0;
    while(!sprawdz) {
        cout << "Podaj wariant stopu:\n 1.Epsilon\n 2.Iteracje" << endl;
        cin >> wariant;
        if (wariant == 1 || wariant == 2) {
            sprawdz = 1;
        } else {
            cout << "Podaj prawidlowy numer wariantu\n";
        }
    }
    cout << "Wprowadz przedzial szukania miejsca zerowego." << endl;
    cin>>a>>b;
    if(a > b) {
        swap(a,b);
    }
//    if (wybor2==1) tworzenieWykresu(trygonometryczna, lp, pp);
//    else if (wybor2==2) tworzenieWykresu(wykladnicza, lp, pp);
//    else if (wybor2==3) tworzenieWykresu(zlozenie, lp, pp);

    if (wybor2 == 1) {
        if (wielomian(a) * wielomian(b) >= 0)
        {
            cout <<"Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        bisekcja(wielomian, a,b,wariant);
        sieczne(a, b, wariant, wielomian);
    } else if (wybor2 == 2) {
        if (trygonometryczna(a) * trygonometryczna(b) >= 0)
        {
            cout <<"Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        bisekcja(trygonometryczna,a ,b ,wariant);
        sieczne(a, b, wariant, trygonometryczna);
    } else if (wybor2 == 3) {
        if (wykladnicza(a) * wykladnicza(b) >= 0) {
            cout <<"Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        bisekcja (wykladnicza, a,b,wariant);
        sieczne(a, b, wariant, wykladnicza);
    }
    else if (wybor2 == 4) {
        if (zlozenie(a) * zlozenie(b) >= 0) {
            cout <<"Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        bisekcja (zlozenie, a,b,wariant);
        sieczne(a, b, wariant, zlozenie);
    }
    else if (wybor2 == 5) {
        if (zlozenie2(a) * zlozenie2(b) >= 0) {
            cout <<"Przedzial nie spelnia warunku f(a)*f(b)<0.";
            return 0;
        }
        bisekcja (zlozenie2, a,b,wariant);
        sieczne(a, b, wariant, zlozenie2);
    }

    cout << "Wybierz przedzial rysowania"<< '\n';
    cin >>lp >> pp;
    if (lp>pp)
    {
        swap(lp,pp);
    }
    if (wybor2==1) tworzenieWykresu(wielomian,lp,pp);
    else if (wybor2==2) tworzenieWykresu(trygonometryczna,lp,pp);
    else if (wybor2==3) tworzenieWykresu(wykladnicza,lp,pp);
    else if (wybor2==4) tworzenieWykresu(zlozenie,lp,pp);
    else if (wybor2==5) tworzenieWykresu(zlozenie2,lp,pp);

    else
    {
        cout << "bledny wybor"<< '\n';
        return 0;
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

double wielomian(double x){
    return 27.3*x - 17.75*x*x - 8.35*x*x*x + 3.2*x*x*x*x + x*x*x*x*x;
}

double trygonometryczna(double x) {
    return 2*sin(2 * x) + 0.3;
}

double wykladnicza(double x) {
    return 3 * exp(-x*x) - 0.8;
}

double zlozenie(double x) {
    return exp(sin(x)) - 1;
}

double zlozenie2(double x) {
    return exp(x) + cos(x);
}

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
    main_plot.set_pointsize(1.0);
    vector <double> x(300);
    vector <double> y(300);

    while (l <= r)
    {

        int i=0;
        x.push_back(l);
        y.push_back(f(l));
        l+=0.004;
        i++;

    }
    main_plot.plot_xy( x, y, "Wykres" );
    getchar();
    getchar();

}