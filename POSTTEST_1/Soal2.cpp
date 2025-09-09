#include <iostream>
using namespace std;

int main() {
    int arrGanjil[3][3] = {
        {1, 2, 0},
        {7, 2, 0},
        {0, 4, 3}
    };

    int jumlahDiagonalUtama = 0;
    int jumlahDiagonalSekunder = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                jumlahDiagonalUtama += arrGanjil[i][j];
            }
            if (i + j == 2) {
                jumlahDiagonalSekunder += arrGanjil[i][j];
            }
        }
    }

    cout << "NIM GANJIL" << endl;
    cout << "Array 2D Matriks 3x3: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arrGanjil[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nJumlah diagonal utama: " << jumlahDiagonalUtama << endl;
    cout << "Jumlah diagonal sekunder: " << jumlahDiagonalSekunder << endl;
    cout << "Total jumlah diagonal utama + diagonal sekunder: "
         << jumlahDiagonalUtama + jumlahDiagonalSekunder << endl;

    return 0;
}