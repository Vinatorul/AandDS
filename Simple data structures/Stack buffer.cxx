#include <iostream>
using namespace std;

class Stack {
private:
    int buffer[101];
    int top = -1;
public:
    void push(int a) {
        top++;
        buffer[top] = a;
    }

    void pop() {
        top--;
    }

    int size() {
        return top + 1;
    }

    bool empty() {
        return top == -1;
    }

    void clear() {
        top = -1;
    }

    int back() {
        return buffer[top];
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
