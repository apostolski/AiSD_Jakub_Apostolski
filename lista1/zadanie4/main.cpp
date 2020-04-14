#include <iostream>
using namespace std;

struct lnode {
    int key;
    lnode* next;
    lnode(int k, lnode* n = nullptr) : key(k), next(n) {}
};

int suma(lnode* L) {
    int wynik = 0;
    while (L != nullptr) {
        wynik += L->key;
        L = L->next;
    }
    return wynik;
}

int nty(int n, lnode* L) {
    if (L == nullptr) { return 0; }
    if (n == 0) { return L->key; }
    for (int i = 1; i < n + 1; i++) {
        if (L->next == nullptr)
            return 0;
        L = L->next;
    }
    return L->key;
}

lnode* filter(lnode* L) {
    if (L->next == nullptr) {
        if (L->key < 0) {
            delete L;
            return nullptr;
        }
        return L;
    }
    lnode* wynik = L;
    lnode* poprzedni = L;
    while (wynik->key < 0) {
        wynik = wynik->next;
        L = L->next;
        delete poprzedni;
        poprzedni = wynik;
        if (wynik == nullptr)
            return nullptr;
    }
    L = L->next;
    while (L != nullptr) {
        if (L->key < 0) {
            poprzedni->next = L->next;
            delete L;
            L = poprzedni;
        }
        else {
            poprzedni = poprzedni->next;
        }
        L = L->next;
    }
    return wynik;
}

void print(lnode* L) {
    cout << "elementy listy: ";
    while (L != nullptr) {
        cout << L->key << ", ";
        L = L->next;
    }
    cout << endl;
}

int main() {
    lnode* L = new lnode(12);
    L = new lnode(7, L);
    L = new lnode(5, L);
    print(L);
    cout << "suma elementow: " << suma(L) << endl;

    cout << "L_0: " << nty(0, L) << endl;
    cout << "L_1: " << nty(1, L) << endl;
    cout << "L_15: " << nty(15, L) << endl;

    lnode* T = new lnode(20);
    T = new lnode(69, T);
    T = new lnode(-420, T);
    T = new lnode(1337, T);
    print(T);
    T = filter(T);
    cout << "filter" << endl;
    print(T);
    cout << endl;

    T = new lnode(-1);
    T = new lnode(2, T);
    print(T);
    T = filter(T);
    cout << "filter" << endl;
    print(T);

    return 0;
}