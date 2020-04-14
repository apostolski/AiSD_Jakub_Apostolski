#include <iostream>
using namespace std;

void max_min(int a[], int n){
    int min, max;
    int i = 1;
    min = max = a[0];
    if (n == 1) cout << "max=min=" << a[0] << endl;
    else {
        for (int i = 1; i < n; i++) {
            if (a[i] > max) max = a[i];
            else if (a[i] < min) min = a[i];
        }
        cout << "max " << max << " min " << min << endl;
    }
}

int main(){
    int a[] = { 3,5,6,2,9,10,17,9,4,1,11,19,20,14,13,5 };
    max_min(a, 16);
    return 0;
}