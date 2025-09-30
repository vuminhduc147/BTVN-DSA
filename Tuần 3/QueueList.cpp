#include <iostream>
using namespace std;

#define MAX 1000

struct QueueArray {
    int a[MAX];
    int n; // số phần tử hiện tại

    QueueArray() { n = 0; }

    bool isEmpty() {
        return n == 0;
    }

    void enqueue(int item) {
        if (n == MAX) {
            cout << "Queue day!" << endl;
            return;
        }
        a[n++] = item; // thêm vào cuối
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        int value = a[0]; // lấy phần tử đầu
        for (int i = 0; i < n-1; i++) a[i] = a[i+1]; // dồn mảng
        n--;
        return value;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong!" << endl;
            return -1;
        }
        return a[0];
    }

    int size() {
        return n;
    }

    void traverse() {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    QueueArray q;

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
