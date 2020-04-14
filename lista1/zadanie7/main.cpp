#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
    int tablica_ascii[256] = { 0 };
    ifstream plik(argv[1]);
    char znak;
    while (plik.get(znak)) {
        tablica_ascii[int(znak)]++;
    }
    plik.close();
    int i = 0;
    for (int ilosc : tablica_ascii) {
        cout << i << ": " << char(i) << " | " << ilosc << endl;
        i++;
    }
    return 0;
}