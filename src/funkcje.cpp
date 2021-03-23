#include <cmath>

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

