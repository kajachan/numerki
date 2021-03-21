#include <iostream>
#include <cmath>


using namespace std;


void bisekcja(double (*f)(double), double a, double b,int wariant)
{
    unsigned int i=0, iteracje=UINT_MAX;
    double x, eps=-1.0;
    if (wariant==1)
    {
        cout << "podaj epsilon"<<endl;
        cin >> eps;
    }
    else
    {
        cout << "podaj liczbe iteracji"<<endl;
        cin >> iteracje;
    }
    do {
        x = (a+b)/2;
        if (f(a)*f(x)<0) b=x;
        else a=x;
        i++;
    } while((abs(f(x)) >= eps) && (i != iteracje)&& (a!=b));

    cout<< "Wykonanych iteracji: "<< i <<endl;

    cout <<"Znalezione miejsce zerowe: " << x <<endl;

}