#include <iostream>
using namespace std;

void balikArray(int *arr, int jumlah) {
    int *start = arr;
    int *end = arr + jumlah - 1;
    
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}

void tampilkanArray(int *arr, int jumlah) {
    for (int i = 0; i < jumlah; i++) {
        cout << *(arr + i);
        if (i < jumlah - 1) cout << ", ";
    }
}

int main() {
    const int jumlah = 7;
    int arrGanjil[jumlah];
    
    for (int i = 0; i < jumlah; i++) {
        arrGanjil[i] = (i + 1) * 3;
    }
    
    cout << "Array angka ganjil sebelum dibalik: ";
    tampilkanArray(arrGanjil, jumlah);
    
    balikArray(arrGanjil, jumlah);
    
    cout << "\nArray angka ganjil setelah dibalik: ";
    tampilkanArray(arrGanjil, jumlah);
    
    return 0;
}