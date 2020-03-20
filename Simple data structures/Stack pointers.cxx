#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top = 0;
    int __size = 0;
public:
    void push(int a) {
        Node* node = new Node();
        node->data = a;
        node->next = top;
        top = node;
        __size++;
    }

    void pop() {
        Node* node = top;
        top = top->next;
        delete node;
        __size--;
    }

    int size() {
        return __size;
    }

    bool empty() {
        return __size == 0;
    }

    void clear() {
        while (__size > 0) {
            pop();
        }
    }

    int back() {
        return top->data;
    }
};

int main() {
    Stack st;

    string s;
    cin >> s;
    while (s != "exit") {
        if (s == "push") {
            int n;
            cin >> n;
            st.push(n);
            cout << "ok\n";
        } else if (s == "pop") {
            if (st.empty()) {
                cout << "error\n";
            } else {
                cout << st.back() << '\n';
                st.pop();
            }
        } else if (s == "back") {
            if (st.empty()) {
                cout << "error\n";
            } else {
                cout << st.back() << '\n';
            }        
        } else if (s == "size") {
            cout << st.size() << '\n';
        } else if (s == "clear") {
            st.clear();
            cout << "ok\n";
        }
        cin >> s;
    }
    cout << "bye" << endl;
    return 0;
}
