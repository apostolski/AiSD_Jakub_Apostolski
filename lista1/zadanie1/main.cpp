#include <iostream>
using namespace std;

double potega_rek(double x, int n){
    double wynik = 1;
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n % 2 == 1) return x * potega_rek(x, n - 1);
    wynik = potega_rek(x, n / 2);
    return wynik * wynik;
}

double potega_bez_rek(double x, int n){
    if (n == 0) return 1;
    double wynik = 1;
    while (n > 0) {
        if (n % 2 == 1) wynik *= x;
        x *= x;
        n /= 2;
    }
    return wynik;
}

int main(){
    for (int i = 0; i < 10; i++) {
        cout << potega_rek(2, i) << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << potega_bez_rek(2, i) << endl;
    }
    return 0;
}