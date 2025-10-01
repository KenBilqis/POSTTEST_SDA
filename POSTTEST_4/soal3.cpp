#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    // --- LENGKAPI DI SINI ---
    // 1. Jika queue kosong (front == nullptr), set front dan rear ke newNode
    // 2. Jika tidak kosong, sambungkan rear->next ke newNode, lalu update rear
    // --- LENGKAPI DI SINI ---

    //JAWABAN:
    if (front == nullptr) {
        // Antrian kosong: node baru menjadi satu-satunya elemen
        front = newNode;
        rear = newNode;
    } else {
        // Antrian tidak kosong: tambahkan node baru di belakang
        rear->next = newNode;
        rear = newNode;
    }
}
string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return ""; // Queue kosong

    // Simpan dokumen yang akan diproses
    string doc = front->document;

    // Simpan alamat node depan untuk dihapus
    Node* temp = front;

    // Geser front ke node berikutnya
    front = front->next;

    // Jika setelah di-dequeue antrian menjadi kosong
    if (front == nullptr) {
        rear = nullptr; // Pastikan rear juga diatur ke nullptr
    }

    // Delete node lama
    delete temp;

    // Kembalikan nama dokumen yang diproses
    return doc;
}

void processAllDocuments(Node*& front, Node*& rear) {
    // Loop hingga queue kosong, dequeue dan print setiap dokumen
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}