//
// Created by HP on 19.03.2021.
//

#ifndef NUMERKI1_DEKLARACJE_H
#define NUMERKI1_DEKLARACJE_H

#include <vector>

double horner(double x, std::vector<double> wsp);
double bisekcja(double a, double b, double stop, double (*fun)(double), bool flagType);
double sieczne(double a, double b, double stop, double (*fun)(double), bool flagType);

double wielomian(double x);
double trygonometryczna(double x);
double wykladnicza(double x);
double zlozenie(double x);
double zlozenie2(double x);

void tworzenieWykresu(double a, double b, double fun(double), double wynikb, double wyniks);

#endif //NUMERKI1_DEKLARACJE_H
