#include <iostream>
#include <cmath>


double arctan(double x, int n) {
    double arctan;
    double clen = 0;

    for (int k = 0; k <= n; ++k) {
        double clen = pow(-1, k) * pow(x, 2 * k + 1) / (2 * k + 1);
        arctan += clen;
    }

    return arctan;
}

double funkcija(double x, int n){
    return arctan(x/2,n)*exp(3*x);
}


double trapeznaMetoda(double a, double b, int n) {
    double h = (b - a) / n;
    double vrednost = funkcija(a, n) + funkcija(b, n);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        vrednost += 2 * funkcija(x, n);
        

    }

    return vrednost * h / 2;
}

int main() {
    
    double a = 0.0;
    double b = M_PI/4;
    int n = 100;

   
    double integral = trapeznaMetoda(a, b, n);

    
    std::cout << "Rezultat integrala je: " << integral << std::endl;

    return 0;
}