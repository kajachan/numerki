#include <iostream>
#include <cmath>


using namespace std;


void bisekcja(double (*f)(double), double a, double b,int wariant)
{
    unsigned int licznik=0, iteracje=UINT_MAX;
    double x, eps=-1.0;
    cout<<"METODA BISEKCJI"<<endl;
    if (wariant==1)
    {
        cout << "Podaj epsilon"<<endl;
        cin >> eps;
    }
    else if (wariant==2)
    {
        cout << "Podaj liczbe iteracji"<<endl;
        cin >> iteracje;
    }
    do {
        x = (a+b)/2;
        if (f(a)*f(x)<0)
            b=x;

        else
            a=x;

        licznik++;
    } while((abs(f(x)) >= eps) && (licznik != iteracje) && (a!=b));

    cout<< "Wykonanych iteracji: "<< licznik <<endl;

    cout <<"Znalezione miejsce zerowe: " << x <<endl;

}