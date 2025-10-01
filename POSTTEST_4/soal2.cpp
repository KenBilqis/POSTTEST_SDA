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
    if (top == nullptr) return '\0';
    Node* temp = top;
    char val = temp->data;
    top = top->next;
    delete temp;
    return val;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    // --- LENGKAPI DI SINI ---
    // 1. Loop setiap karakter dalam `expr`.
    // 2. Jika karakter adalah kurung buka '(', '{', '[', push ke stack.
    // 3. Jika karakter adalah kurung tutup ')', '}', ']', cek:
    //    a. Apakah stack kosong? Jika ya, return false.
    //    b. Pop stack, lalu cek apakah kurung tutup cocok dengan kurung buka. Jika tidak, return false.
    // 4. Setelah loop selesai, jika stack kosong, return true. Jika tidak, return false.
    // --- LENGKAPI DI SINI ---

    // JAWABAN:
    for (char c : expr) {
        // Jika karakter adalah kurung buka, simpan di stack
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // Jika karakter adalah kurung tutup
        else if (c == ')' || c == '}' || c == ']') {
            // Jika stack kosong, berarti tidak ada pasangan buka = tidak seimbang
            if (stackTop == nullptr) {
                return false;
            }

            // Ambil kurung buka terakhir dari stack
            char lastOpen = pop(stackTop);

            // Periksa apakah pasangan kurung sesuai
            if ((c == ')' && lastOpen != '(') ||
                (c == '}' && lastOpen != '{') ||
                (c == ']' && lastOpen != '[')) {
                return false; // Kondisi jika jenis kurung tidak cocok
            }
        }
        // Karakter selain kurung diabaikan (misalnya: huruf, angka, spasi)
    }

    // Setelah semua karakter diproses, stack harus kosong agar seimbang
    // Jika masih ada sisa di stack, berarti ada kurung buka yang tidak ditutup
    return stackTop == nullptr;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    // Expected output: Seimbang
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}