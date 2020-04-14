#include <iostream>
#include <cmath>
using namespace std;

double oblicz(double a[], int n, double x){
    double wynik = 0;
    for (int i = n; i >= 0; i--) {
        wynik = (wynik * x) + a[i];
    }
    return wynik;
}

int main(){
    double a[] = { 5, 3, 6, 9 };
    cout << oblicz(a, 3, 2) << endl;
    return 0;
}
