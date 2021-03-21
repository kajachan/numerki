//
// Created by HP on 19.03.2021.
//

#ifndef NUMERKI1_DEKLARACJE_H
#define NUMERKI1_DEKLARACJE_H

#include <vector>

double Horner(double x, std::vector<double> vector);
void bisekcja(double (*f)(double), double a, double b,int wariant);
double sieczne(double a, double b, int wariant, double (*f)(double));

#endif //NUMERKI1_DEKLARACJE_H
