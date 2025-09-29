#include <iostream>
using namespace std;

#define MAX 1000

struct List {
    int a[MAX];
    int n; // số phần tử hiện tại

    // Khởi tạo
    List() { n = 0; }

    // Truy cập
    int get(int i) {
        if (i < 0 || i >= n) return -1;
        return a[i];
    }

    // Chèn đầu
    void insertFirst(int x) {
        for (int i = n; i > 0; i--) a[i] = a[i-1];
        a[0] = x;
        n++;
    }

    // Chèn cuối
    void insertLast(int x) {
        a[n++] = x;
    }

    // Chèn tại i
    void insertAt(int i, int x) {
        if (i < 0 || i > n) return;
        for (int j = n; j > i; j--) a[j] = a[j-1];
        a[i] = x;
        n++;
    }

    // Xóa đầu
    void deleteFirst() {
        if (n == 0) return;
        for (int i = 0; i < n-1; i++) a[i] = a[i+1];
        n--;
    }

    // Xóa cuối
    void deleteLast() {
        if (n > 0) n--;
    }

    // Xóa tại i
    void deleteAt(int i) {
        if (i < 0 || i >= n) return;
        for (int j = i; j < n-1; j++) a[j] = a[j+1];
        n--;
    }

    // Duyệt xuôi
    void traverseForward() {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }

    // Duyệt ngược
    void traverseBackward() {
        for (int i = n-1; i >= 0; i--) cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    List L;

    // Chèn cuối
    L.insertLast(10);
    L.insertLast(20);
    L.insertLast(30);
    cout << "Sau khi chèn cuối 10,20,30: ";
    L.traverseForward();

    // Chèn đầu
    L.insertFirst(5);
    cout << "Sau khi chèn đầu 5: ";
    L.traverseForward();

    // Chèn tại vị trí i
    L.insertAt(2, 15);
    cout << "Sau khi chèn 15 vào vị trí 2: ";
    L.traverseForward();

    // Xóa đầu
    L.deleteFirst();
    cout << "Sau khi xóa đầu: ";
    L.traverseForward();

    // Xóa cuối
    L.deleteLast();
    cout << "Sau khi xóa cuối: ";
    L.traverseForward();

    // Xóa tại vị trí i
    L.deleteAt(1);
    cout << "Sau khi xóa tại vị trí 1: ";
    L.traverseForward();

    // Duyệt ngược
    cout << "Duyệt ngược: ";
    L.traverseBackward();

    // Truy cập
    cout << "Phần tử tại vị trí 0 là: " << L.get(0) << endl;

    return 0;
}
