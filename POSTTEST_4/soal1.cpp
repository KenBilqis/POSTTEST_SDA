#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};
void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0'; // Return null character jika stack kosong
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    // --- LENGKAPI DI SINI ---

    // 1. Push setiap karakter dari string s ke dalam stack.
    // Karena stack bersifat LIFO (Last-In, First-Out), karakter terakhir dari string akan berada di puncak stack.
    for (char c : s) {
        push(stackTop, c);
    }

    // 2. Pop setiap karakter dari stack dan tambahkan ke string `reversed`.
    // Karakter yang terakhir dimasukkan (yaitu karakter paling puncak stack), akan dikeluarkan lebih dulu, sehingga urutan karakter menjadi terbalik.
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    // --- LENGKAPI DI SINI ---

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl; // Output: ataD rukurts
    return 0;
}