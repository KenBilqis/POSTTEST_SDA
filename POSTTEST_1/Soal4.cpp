#include <iostream>
using namespace std;
// Nim ganjil bang
void tukar(int** a, int** b) {
    int temp = **a;
    **a = **b;
    **b = temp;
}

int main() {
    int x, y;

    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;

    int* ptrX = &x;
    int* ptrY = &y;

    cout << "\n=== Sebelum Swap ===" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    tukar(&ptrX, &ptrY);

    cout << "\n=== Setelah Swap ===" << endl;
    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}