#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int x) {   // constructor cho Node
        data = x;
        next = NULL;
    }
};

struct List {
    Node* head;

    List() { head = NULL; } // khởi tạo rỗng

    // Truy cập phần tử tại vị trí i
    int get(int i) {
        Node* p = head;
        int k = 0;
        while (p && k < i) {
            p = p->next;
            k++;
        }
        return (p ? p->data : -1);
    }

    // Chèn vào đầu
    void insertFirst(int x) {
        Node* p = new Node(x);
        p->next = head;
        head = p;
    }

    // Chèn vào cuối
    void insertLast(int x) {
        Node* p = new Node(x);
        if (!head) { head = p; return; }
        Node* q = head;
        while (q->next) q = q->next;
        q->next = p;
    }

    // Chèn tại vị trí i
    void insertAt(int i, int x) {
        if (i == 0) { insertFirst(x); return; }
        Node* q = head;
        for (int k = 0; q && k < i-1; k++) q = q->next;
        if (!q) return;
        Node* p = new Node(x);
        p->next = q->next;
        q->next = p;
    }

    // Xóa đầu
    void deleteFirst() {
        if (!head) return;
        Node* p = head;
        head = head->next;
        delete p;
    }

    // Xóa cuối
    void deleteLast() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* q = head;
        while (q->next->next) q = q->next;
        delete q->next;
        q->next = NULL;
    }

    // Xóa tại vị trí i
    void deleteAt(int i) {
        if (i == 0) { deleteFirst(); return; }
        Node* q = head;
        for (int k = 0; q && k < i-1; k++) q = q->next;
        if (!q || !q->next) return;
        Node* p = q->next;
        q->next = p->next;
        delete p;
    }

    // Duyệt xuôi
    void traverseForward() {
        for (Node* p = head; p; p = p->next) cout << p->data << " ";
        cout << endl;
    }

    // Duyệt ngược
    void traverseBackward(Node* p) {
        if (!p) return;
        traverseBackward(p->next);
        cout << p->data << " ";
    }
};

int main() {
    List L;

    L.insertLast(10);
    L.insertLast(20);
    L.insertLast(30);
    cout << "Sau khi chèn cuối 10,20,30: "; L.traverseForward();

    L.insertFirst(5);
    cout << "Sau khi chèn đầu 5: "; L.traverseForward();

    L.insertAt(2, 15);
    cout << "Sau khi chèn 15 vào vị trí 2: "; L.traverseForward();

    L.deleteFirst();
    cout << "Sau khi xóa đầu: "; L.traverseForward();

    L.deleteLast();
    cout << "Sau khi xóa cuối: "; L.traverseForward();

    L.deleteAt(1);
    cout << "Sau khi xóa tại vị trí 1: "; L.traverseForward();

    cout << "Duyệt xuôi: "; L.traverseForward();
    cout << "Duyệt ngược: "; L.traverseBackward(L.head); cout << endl;

    cout << "Truy cập phần tử tại vị trí 0: " << L.get(0) << endl;

    return 0;
}
