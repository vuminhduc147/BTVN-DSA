#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
};

struct QueueLinkedList {
    Node* frontNode; // đầu queue
    Node* rearNode;  // cuối queue
    int count;

    QueueLinkedList() {
        frontNode = rearNode = NULL;
        count = 0;
    }

    bool isEmpty() {
        return frontNode == NULL;
    }

    void enqueue(int item) {
        Node* p = new Node(item);
        if (rearNode == NULL) { // queue rỗng
            frontNode = rearNode = p;
        } else {
            rearNode->next = p;
            rearNode = p;
        }
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        Node* p = frontNode;
        int value = p->data;
        frontNode = frontNode->next;
        if (frontNode == NULL) rearNode = NULL; // nếu rỗng hẳn
        delete p;
        count--;
        return value;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        return frontNode->data;
    }

    int size() {
        return count;
    }

    void traverse() {
        for (Node* p = frontNode; p; p = p->next) cout << p->data << " ";
        cout << endl;
    }
};

int main() {
    QueueLinkedList q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Queue sau khi enqueue 10,20,30: "; q.traverse();

    cout << "Front: " << q.front() << endl;

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Queue sau khi dequeue: "; q.traverse();

    cout << "Size: " << q.size() << endl;
    cout << "Queue rong: " << (q.isEmpty() ? "Co" : "Khong") << endl;

    return 0;
}
