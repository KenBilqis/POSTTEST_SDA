#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

void tampilkanHeader() {
    cout << "=======================================================================" << endl;
    cout << "| GAME INVENTORY MANAGEMENT                                           |" << endl;
    cout << "| [Ken Bilqis Nuraini - 2409106015]                                   |" << endl;
    cout << "=======================================================================" << endl;
}

void tampilkanMenu() {
    cout << "| 1. Tambah Item Baru                                                  |" << endl;
    cout << "| 2. Sisipkan Item                                                     |" << endl;
    cout << "| 3. Hapus Item Terakhir                                               |" << endl;
    cout << "| 4. Gunakan Item                                                      |" << endl;
    cout << "| 5. Tampilkan Inventory                                               |" << endl;
    cout << "| 6. Hapus Item Berdasarkan Posisi                                     |" << endl;
    cout << "| 0. Keluar                                                            |" << endl;
    cout << "=======================================================================" << endl;
}

void tambahAkhir(Item* &head, string nama, string tipe, int jumlah) {
    Item* newItem = new Item;
    newItem->namaItem = nama;
    newItem->tipe = tipe;
    newItem->jumlah = jumlah;
    newItem->next = nullptr;

    if (head == nullptr) {
        head = newItem;
    } else {
        Item* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

int panjangList(Item* head) {
    int count = 0;
    Item* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void sisipkan(Item* &head, string nama, string tipe, int jumlah, int posisi) {
    int size = panjangList(head);
    if (posisi < 1 || posisi > size + 1) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    Item* newItem = new Item;
    newItem->namaItem = nama;
    newItem->tipe = tipe;
    newItem->jumlah = jumlah;

    if (posisi == 1) {
        newItem->next = head;
        head = newItem;
    } else {
        Item* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        newItem->next = temp->next;
        temp->next = newItem;
    }
}

void hapusAkhir(Item* &head) {
    if (head == nullptr) {
        cout << "Inventory kosong" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Item* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    cout << "Item terakhir berhasil dihapus" << endl;
}

Item* cariItem(Item* head, string nama) {
    Item* temp = head;
    while (temp != nullptr) {
        string namaLower = "";
        for (char c : temp->namaItem) {
            namaLower += tolower(c);
        }
        string cariLower = "";
        for (char c : nama) {
            cariLower += tolower(c);
        }
        if (namaLower == cariLower) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void hapusNode(Item* &head, Item* nodeHapus) {
    if (head == nullptr || nodeHapus == nullptr) return;

    if (head == nodeHapus) {
        head = head->next;
        delete nodeHapus;
        return;
    }

    Item* temp = head;
    while (temp != nullptr && temp->next != nodeHapus) {
        temp = temp->next;
    }

    if (temp != nullptr) {
        temp->next = nodeHapus->next;
        delete nodeHapus;
    }
}

void gunakanItem(Item* &head, string nama) {
    Item* ditemukan = cariItem(head, nama);
    if (ditemukan == nullptr) {
        cout << "Item tidak ditemukan" << endl;
        return;
    }

    ditemukan->jumlah--;
    cout << "Menggunakan " << ditemukan->namaItem << ". Jumlah sekarang: " << ditemukan->jumlah << endl;

    if (ditemukan->jumlah == 0) {
        hapusNode(head, ditemukan);
        cout << "Item dihapus karena habis" << endl;
    }
}

void tampilkanInventory(Item* head) {
    if (head == nullptr) {
        cout << "Inventory kosong" << endl;
        return;
    }

    cout << "+----+----------------------+--------+----------+" << endl;
    cout << "| No | Nama Item            | Jumlah | Tipe     |" << endl;
    cout << "+----+----------------------+--------+----------+" << endl;

    Item* temp = head;
    int counter = 1;
    while (temp != nullptr) {
        cout << "| " << setw(2) << counter << " | " << setw(20) << left << temp->namaItem << " | " 
             << setw(6) << temp->jumlah << " | " << setw(8) << temp->tipe << " |" << endl;
        temp = temp->next;
        counter++;
    }
    cout << "+----+----------------------+--------+----------+" << endl;
}

void hapusPosisi(Item* &head, int posisi) {
    int size = panjangList(head);
    if (posisi < 1 || posisi > size) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    if (posisi == 1) {
        Item* hapus = head;
        head = head->next;
        delete hapus;
    } else {
        Item* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        Item* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
    }
    cout << "Item pada posisi " << posisi << " berhasil dihapus" << endl;
}

int main() {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);

    cout << "Login berhasil!" << endl;
    cout << "SELAMAT DATANG " << nama << endl;

    Item* head = nullptr;
    int pilihan;

    do {
        tampilkanHeader();
        tampilkanMenu();
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                string namaItem, tipe;
                cout << "Nama Item: ";
                getline(cin, namaItem);
                cout << "Tipe: ";
                getline(cin, tipe);
                tambahAkhir(head, namaItem, tipe, 15);
                cout << "Item berhasil ditambahkan" << endl;
                break;
            }
            case 2: {
                string namaItem, tipe;
                int posisi;
                cout << "Nama Item: ";
                getline(cin, namaItem);
                cout << "Tipe: ";
                getline(cin, tipe);
                cout << "Posisi (Saran: 6): ";
                string input;
                getline(cin, input);
                if (input.empty()) {
                    posisi = 6;
                } else {
                    posisi = stoi(input);
                }
                sisipkan(head, namaItem, tipe, 15, posisi);
                cout << "Item berhasil disisipkan" << endl;
                break;
            }
            case 3:
                hapusAkhir(head);
                break;
            case 4: {
                tampilkanInventory(head);
                string namaItem;
                cout << "Nama Item yang akan digunakan: ";
                getline(cin, namaItem);
                gunakanItem(head, namaItem);
                break;
            }
            case 5:
                tampilkanInventory(head);
                break;
            case 6: {
                tampilkanInventory(head);
                int posisi;
                cout << "Posisi yang akan dihapus: ";
                cin >> posisi;
                cin.ignore();
                hapusPosisi(head, posisi);
                break;
            }
            case 0:
                cout << "Terima kasih telah menggunakan sistem inventory!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    while (head != nullptr) {
        Item* hapus = head;
        head = head->next;
        delete hapus;
    }

    return 0;
}