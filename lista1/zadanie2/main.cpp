#include <iostream>
using namespace std;

double f(double x){
    return 0.6 * x * x - 0.2;
}

// f(a) < 0, f(b) > 0 
double solve(double a, double b){
    double c = (a + b) / 2.0;
    double y = f(c);
    if (y != 0) {
        for (int i = 0; i < 31; i++) {
            std::cout << i << ": " << a << ", " << b << ", " << c << std::endl;
            if (y < 0)
                a = c;
            else
                b = c;
            c = (a + b) / 2;
            y = f(c);
            if (y == 0 || c == a || c == b)break;
        }
    }
    return c;
}

int main(){
    cout.precision(10);
    cout << solve(0, 1) << endl;
    return 0;
}
