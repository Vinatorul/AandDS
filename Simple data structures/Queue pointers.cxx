#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = 0;    
};

class Queue {
private:
    Node* tail = 0;
    Node* head = 0;
    int __size = 0;
public:
    void push(int n) {
        Node* node = new Node();
        node->data = n;
        if (tail) {
            tail->next = node;
        } else {
            head = node;
        }
        tail = node;
        __size++;
    }

    void pop() {
        Node* node = head;
        head = head->next;
        delete node;
        __size--;
        if (__size == 0)
            tail = 0;
    }

    int front() {
        return head->data;
    }

    int size() {
        return __size;
    }

    void clear() {
        while (__size > 0) {
            pop();
        }
    }

    bool empty() {
        return __size == 0;
    }
};

int main() {
    Queue q;
    string s;
    cin >> s;
    while (s != "exit") {
        if (s == "push") {
            int n;
            cin >> n;
            q.push(n);
            cout << "ok\n";
        } else if (s == "pop") {
            if (q.empty()) {
                cout << "error\n";
            } else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (s == "front") {
            if (q.empty()) {
                cout << "error\n";
            } else {
                cout << q.front() << '\n';
            }
        } else if (s == "size") {
            cout << q.size() << '\n';
        } else if (s == "clear") {
            cout << "ok\n";
            q.clear();
        }
        cin >> s;
    }
    cout << "bye" << endl;
    return 0;
}
