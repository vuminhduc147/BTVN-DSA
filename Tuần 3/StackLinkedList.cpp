#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Stack {
    Node* head;   // dùng head để làm đỉnh của stack
    int count;    // theo dõi số phần tử

    Stack() {
        head = NULL;
        count = 0;
    }

    // Kiểm tra rỗng
    bool isEmpty() {
        return head == NULL;
    }

    // Thêm phần tử vào stack (đỉnh stack là đầu danh sách)
    void push(int item) {
        Node* p = new Node(item);
        p->next = head;
        head = p;
        count++;
    }

    // Xóa phần tử ở đỉnh stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        Node* p = head;
        int value = p->data;
        head = head->next;
        delete p;
        count--;
        return value;
    }

    // Lấy giá trị phần tử ở đỉnh stack
    int top() {
        if (isEmpty()) {
            cout << "Stack rong!" << endl;
            return -1;
        }
        return head->data;
    }

    // Trả về số phần tử trong stack
    int size() {
        return count;
    }

    // Duyệt stack từ trên xuống dưới
    void traverse() {
        for (Node* p = head; p; p = p->next) cout << p->data << " ";
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Stack sau khi push 10, 20, 30: ";
    st.traverse();

    cout << "Phan tu top: " << st.top() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Stack sau khi pop: "; st.traverse();

    cout << "Size hien tai: " << st.size() << endl;
    cout << "Stack rong: " << (st.isEmpty() ? "Co" : "Khong") << endl;

    return 0;
}
