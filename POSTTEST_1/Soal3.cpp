#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

int main() {
    // Nim Ganjil bang
    Mahasiswa mhs[5] = {
        {"Gita Sekar Andarani", 2001, 3.75},
        {"Mutiara Azzahra", 2004, 4},
        {"Indah Cahya", 2001, 3.85},
        {"Febriola Sinambela", 2005, 3.95},
        {"Jabieb", 1989, 3.80}
    };

    int ipkTertinggi = 0;
    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > mhs[ipkTertinggi].ipk) {
            ipkTertinggi = i;
        }
    }

    cout << "Mahasiswa dengan IPK tertinggi:\n";
    cout << "Nama   : " << mhs[ipkTertinggi].nama << endl;
    cout << "NIM    : " << mhs[ipkTertinggi].nim << endl;
    cout << "IPK    : " << mhs[ipkTertinggi].ipk << endl;

    return 0;
}