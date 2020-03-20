#include <iostream>
using namespace std;

const int QUEUE_SIZE = 100;

class Queue {
private:
    int buffer[QUEUE_SIZE];
    int tail = -1;
    int head = 0;
    int __size = 0;
public:
    void push(int n) {
        tail++;
        if (tail == QUEUE_SIZE)
            tail = 0;
        buffer[tail] = n;
        __size++;
    }

    void pop() {
        head++;
        if (head == QUEUE_SIZE)
            head = 0; 
        __size--;
    }

    int front() {
        return buffer[head];
    }

    int size() {
        return __size;
    }

    void clear() {
        __size = 0;
        tail = -1;
        head = 0;
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
