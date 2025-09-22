#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct List {
    Node* head;
    List() { head = NULL; } // khởi tạo rỗng
};


// Tạo node mới
Node* createNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

// Truy cập phần tử tại vị trí i
int get(List L, int i) {
    Node* p = L.head;
    int k = 0;
    while (p && k < i) {
        p = p->next;
        k++;
    }
    return (p ? p->data : -1); // -1 nếu không tìm thấy
}

// Chèn vào đầu
void insertFirst(List &L, int x) {
    Node* p = createNode(x);
    p->next = L.head;
    L.head = p;
}

// Chèn vào cuối
void insertLast(List &L, int x) {
    Node* p = createNode(x);
    if (!L.head) {
        L.head = p;
        return;
    }
    Node* q = L.head;
    while (q->next) q = q->next;
    q->next = p;
}

// Chèn tại vị trí i
void insertAt(List &L, int i, int x) {
    if (i == 0) { insertFirst(L, x); return; }
    Node* q = L.head;
    for (int k = 0; q && k < i-1; k++) q = q->next;
    if (!q) return; // vị trí không hợp lệ
    Node* p = createNode(x);
    p->next = q->next;
    q->next = p;
}

// Xóa đầu
void deleteFirst(List &L) {
    if (!L.head) return;
    Node* p = L.head;
    L.head = L.head->next;
    delete p;
}

// Xóa cuối
void deleteLast(List &L) {
    if (!L.head) return;
    if (!L.head->next) {
        delete L.head;
        L.head = NULL;
        return;
    }
    Node* q = L.head;
    while (q->next->next) q = q->next;
    delete q->next;
    q->next = NULL;
}

// Xóa tại vị trí i
void deleteAt(List &L, int i) {
    if (i == 0) { deleteFirst(L); return; }
    Node* q = L.head;
    for (int k = 0; q && k < i-1; k++) q = q->next;
    if (!q || !q->next) return;
    Node* p = q->next;
    q->next = p->next;
    delete p;
}

// Duyệt xuôi
void traverseForward(List L) {
    for (Node* p = L.head; p; p = p->next) cout << p->data << " ";
    cout << endl;
}

// Duyệt ngược 
void traverseBackward(Node* p) {
    if (!p) return;
    traverseBackward(p->next);
    cout << p->data << " ";
}

int main() {
    List L;

    insertLast(L, 10);
    insertLast(L, 20);
    insertLast(L, 30);
    cout << "Sau khi chèn cuối 10,20,30: "; traverseForward(L);

    insertFirst(L, 5);
    cout << "Sau khi chèn đầu 5: "; traverseForward(L);

    insertAt(L, 2, 15);
    cout << "Sau khi chèn 15 vào vị trí 2: "; traverseForward(L);

    deleteFirst(L);
    cout << "Sau khi xóa đầu: "; traverseForward(L);

    deleteLast(L);
    cout << "Sau khi xóa cuối: "; traverseForward(L);

    deleteAt(L, 1);
    cout << "Sau khi xóa tại vị trí 1: "; traverseForward(L);

    cout << "Duyệt xuôi: "; traverseForward(L);
    cout << "Duyệt ngược: "; traverseBackward(L.head); cout << endl;

    cout << "Truy cập phần tử tại vị trí 0: " << get(L, 0) << endl;

    return 0;
}
