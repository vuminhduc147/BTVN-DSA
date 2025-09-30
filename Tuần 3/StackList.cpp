#include <iostream>
using namespace std;

#define MAX 1000

struct Stack {
    int a[MAX];
    int n; // số phần tử hiện tại

    // Khởi tạo
    Stack() { n = 0; }

    // Kiểm tra rỗng
    bool isEmpty() {
        return n == 0;
    }

    // Thêm phần tử vào đỉnh stack
    void push(int item) {
        if (n == MAX) {
            cout << "Stack day!" << endl;
            return;
        }
        a[n++] = item;
    }

    // Xóa phần tử ở đỉnh stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return a[--n];
    }

    // Lấy phần tử ở đỉnh stack
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return a[n-1];
    }

    // Trả về kích thước stack
    int size() {
        return n;
    }

    // Duyệt stack (từ đỉnh xuống đáy)
    void traverse() {
        for (int i = n-1; i >= 0; i--) cout << a[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Stack sau khi push 10,20,30: ";
    st.traverse();

    cout << "Top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Stack sau khi pop: ";
    st.traverse();

    cout << "Size hien tai: " << st.size() << endl;

    cout << "Stack rong: " << (st.isEmpty() ? "Co" : "Khong") << endl;

    return 0;
}
