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
    Item* prev; // <-- tambahan untuk double linked list
};

void berhasilDiHapus() {
    cout << "\n==============================" << endl;
    cout << "|    ITEM BERHASIL DIHAPUS   |" << endl;
    cout << "==============================" << endl;
}

void berhasilDiTambahkan() {
    cout << "\n==================================" << endl;
    cout << "|    ITEM BERHASIL DITAMBAHKAN   |" << endl;
    cout << "==================================" << endl;
}

void tampilkanMenu() {
    cout << "\n==============================================" << endl;
    cout << "| GAME INVENTORY MANAGEMENT                  |" << endl;
    cout << "| [Ken Bilqis Nuraini - 2409106015]          |" << endl;
    cout << "==============================================" << endl;
    cout << "| 1. Tambah Item Baru                        |" << endl;
    cout << "| 2. Sisipkan Item                           |" << endl;
    cout << "| 3. Hapus Item Terakhir                     |" << endl;
    cout << "| 4. Gunakan Item                            |" << endl;
    cout << "| 5. Tampilkan Inventory                     |" << endl;
    cout << "| 6. Hapus Item Berdasarkan Posisi           |" << endl;
    cout << "| 7. Tampilkan Inventory dari Belakang       |" << endl;
    cout << "| 8. Tampilkan Detail Item Berdasarkan Nama  |" << endl;
    cout << "| 0. Keluar                                  |" << endl;
    cout << "==============================================" << endl;
}

void tambahAkhir(Item* &head, string nama, string tipe, int jumlah) {
    Item* newItem = new Item;
    newItem->namaItem = nama;
    newItem->tipe = tipe;
    newItem->jumlah = jumlah;
    newItem->next = nullptr;
    newItem->prev = nullptr;

    if (head == nullptr) {
        head = newItem;
    } else {
        Item* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newItem;
        newItem->prev = temp;
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
    newItem->next = nullptr;
    newItem->prev = nullptr;

    if (posisi == 1) {
        newItem->next = head;
        if (head != nullptr) {
            head->prev = newItem;
        }
        head = newItem;
    } else {
        Item* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        newItem->next = temp->next;
        newItem->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newItem;
        }
        temp->next = newItem;
    }
}

void hapusAkhir(Item* &head) {
    if (head == nullptr) {
        cout << "Inventory kosong" << endl;
        return;
    }

    Item* hapus = head;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        while (hapus->next != nullptr) {
            hapus = hapus->next;
        }
        hapus->prev->next = nullptr;
        delete hapus;
    }
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
        if (head != nullptr) {
            head->prev = nullptr;
        }
    } else {
        if (nodeHapus->prev != nullptr) {
            nodeHapus->prev->next = nodeHapus->next;
        }
        if (nodeHapus->next != nullptr) {
            nodeHapus->next->prev = nodeHapus->prev;
        }
    }
    delete nodeHapus;
}

void gunakanItem(Item* &head, string nama) {
    Item* ditemukan = cariItem(head, nama);
    if (ditemukan == nullptr) {
        cout << "Item tidak ditemukan" << endl;
        return;
    }
    ditemukan->jumlah--;
    cout << "Berhasil menggunakan " << ditemukan->namaItem << "\nJumlah sekarang: " << ditemukan->jumlah << endl;
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
    cout << "+====+======================+========+==========+" << endl;
    cout << "| No | Nama Item            | Jumlah | Tipe     |" << endl;
    cout << "+====+======================+========+==========+" << endl;
    Item* temp = head;
    int counter = 1;
    while (temp != nullptr) {
        cout << "| " << setw(2) << counter << " | " << setw(20) << left << temp->namaItem << " | "
             << setw(6) << temp->jumlah << " | " << setw(8) << temp->tipe << " |" << endl;
        temp = temp->next;
        counter++;
    }
    cout << "+====+======================+========+==========+" << endl;
}

void tampilkanInventoryTerbalik(Item* head) {
    if (head == nullptr) {
        cout << "Inventory kosong" << endl;
        return;
    }

    // Cari tail
    Item* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    cout << "+----+----------------------+--------+----------+" << endl;
    cout << "| No | Nama Item            | Jumlah | Tipe     |" << endl;
    cout << "+----+----------------------+--------+----------+" << endl;
    Item* temp = tail;
    int counter = panjangList(head);
    while (temp != nullptr) {
        cout << "| " << setw(2) << counter << " | " << setw(20) << left << temp->namaItem << " | "
             << setw(6) << temp->jumlah << " | " << setw(8) << temp->tipe << " |" << endl;
        temp = temp->prev;
        counter--;
    }
    cout << "+----+----------------------+--------+----------+" << endl;
}

void tampilkanDetailItem(Item* head, string nama) {
    Item* ditemukan = cariItem(head, nama);
    if (ditemukan == nullptr) {
        cout << "Item tidak ditemukan" << endl;
        return;
    }
    cout << "+----------------------+--------+----------+" << endl;
    cout << "| Nama Item            | Jumlah | Tipe     |" << endl;
    cout << "+----------------------+--------+----------+" << endl;
    cout << "| " << setw(20) << left << ditemukan->namaItem << " | "
         << setw(6) << ditemukan->jumlah << " | " << setw(8) << ditemukan->tipe << " |" << endl;
    cout << "+----------------------+--------+----------+" << endl;
}

void hapusPosisi(Item* &head, int posisi) {
    int size = panjangList(head);
    if (posisi < 1 || posisi > size) {
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    Item* hapus = head;
    if (posisi == 1) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
    } else {
        for (int i = 1; i < posisi; i++) {
            hapus = hapus->next;
        }
        hapus->prev->next = hapus->next;
        if (hapus->next != nullptr) {
            hapus->next->prev = hapus->prev;
        }
    }
    delete hapus;
}

int main() {
    cout << "=================================" << endl;
    cout << "|      SELAMAT DATANG DI        |" << endl;
    cout << "|   GAME INVENTORY MANAGEMENT   |" << endl;
    cout << "=================================" << endl;
    string nama, nim;
    cout << "\nMasukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    getline(cin, nim);
    cout << "\n=================================" << endl;
    cout << "|        LOGIN BERHASIL!        |" << endl;
    cout << "=================================\n" << endl;
    cout << "HALOO " << nama << '\n' << endl;

    Item* head = nullptr;
    int pilihan;

    do {
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
                berhasilDiTambahkan();
                break;
            }
            case 2: {
                string namaItem, tipe;
                int posisi;
                cout << "Nama Item: ";
                getline(cin, namaItem);
                cout << "Tipe: ";
                getline(cin, tipe);
                cout << "Posisi: ";
                string input;
                getline(cin, input);
                if (input.empty()) {
                    posisi = 6;
                } else {
                    posisi = stoi(input);
                }
                sisipkan(head, namaItem, tipe, 15, posisi);
                berhasilDiTambahkan();
                break;
            }
            case 3:
                hapusAkhir(head);
                berhasilDiHapus();
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
                berhasilDiHapus();
                break;
            }
            case 7:
                tampilkanInventoryTerbalik(head);
                break;
            case 8: {
                tampilkanInventory(head);
                string namaItem;
                cout << "Masukkan Nama Item untuk ditampilkan detailnya: ";
                getline(cin, namaItem);
                tampilkanDetailItem(head, namaItem);
                break;
            }
            case 0:
                cout << "Terima kasih telah menggunakan sistem inventory!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (pilihan != 0);

    // Bersihkan memori
    while (head != nullptr) {
        Item* hapus = head;
        head = head->next;
        delete hapus;
    }

    return 0;
}