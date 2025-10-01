#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

/*
 * Fungsi ini menerima referensi ke pointer head dan tail.
 * Pointer head dan tail akan di-update setelah penukaran.
 */
void exchangeHeadAndTail(Node *&head_ref) {
    // Hanya berjalan jika ada 2 node atau lebih
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;
    Node* tail = head_ref->prev;  // Tail adalah prev dari head

    // Hal yang perlu dilakukan:
    // Buat kondisi jika hanya 2 node, cukup swap head_ref
    // Simpan neighbor ( yaitu head_next dan tail_prev)
    // Update koneksi: tail_prev <-> tail <-> head_next
    // Update koneksi: head_next <- ... -> tail_prev <-> head <-> tail_prev
    // terakhir Update head_ref

    // kondisi bisa kalian sesuaikan sendiri tapi usahakan outputnya sama

    // Jawaban:

    // Simpan tetangga head dan tail sebelum modifikasi
    Node* head_next = head->next;   // node setelah head
    Node* tail_prev = tail->prev;   // node sebelum tail

    // Visualisasi awal (contoh: 1 <-> 2 <-> 3 <-> 4 <-> 5):
    // head = 1, tail = 5
    // head->next = 2, tail->prev = 4
    //
    // Struktur awal:
    // 5 <-> 1 <-> 2 <-> 3 <-> 4 <-> 5 (circular)

    // Kasus khusus: hanya 2 node → head <-> tail <-> head
    if (head_next == tail) {
        // Cukup tukar posisi head dan tail secara logis
        // Karena circular doubly linked, cukup ubah head_ref
        head_ref = tail;
        // Koneksi tetap valid: tail->next = head (lama), head->prev = tail
        return;
    }

    // === Langkah 1: Putuskan head dan tail dari posisi lama ===
    // atur ulang pointer

    // === Langkah 2: Sambungkan tail_prev ke head_next (menghapus head & tail dari tengah) ===
    tail_prev->next = head_next;
    head_next->prev = tail_prev;

    // === Langkah 3: Jadikan tail sebagai head baru, dan head sebagai tail baru ===
    // Lalu susun: [tail] <-> [head_next ... tail_prev] <-> [head]

    // Hubungkan tail (akan jadi head baru) ke head_next
    tail->next = head_next;
    head_next->prev = tail;

    // Hubungkan tail_prev ke head (akan jadi tail baru)
    head->prev = tail_prev;
    tail_prev->next = head;

    // Hubungkan ujung-ujung circular: head (baru) <-> ... <-> tail (baru)
    tail->prev = head;  // karena head sekarang jadi tail
    head->next = tail;  // karena tail sekarang jadi head

    // Visualisasi akhir:
    // tail (5) jadi head baru
    // head (1) jadi tail baru
    // Urutan: 5 <-> 2 <-> 3 <-> 4 <-> 1 <-> 5

    // === Langkah 4: Update head_ref ===
    head_ref = tail; // tail lama menjadi head baru
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

void insertEnd(Node *&head_ref, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main()
{
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    // Expected output: 5 2 3 4 1
    printList(head);

    return 0;
}