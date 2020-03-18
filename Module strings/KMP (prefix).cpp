#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(string &s) {
    vector<int> P(s.size());
    P[0] = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        int j = P[i];
        while (j > 0 && s[i + 1] != s[j]) {
            j = P[j - 1];
        }
        if (s[i + 1] == s[j]) {
            P[i + 1] = j + 1;
        } else {
            P[i + 1] = 0;
        }
    }
    return P;
}

int main() {
    string s, t;
    cin >> s >> t;
    string t_s = t + "&" + s;
    vector<int> P = prefix_function(t_s);
    for (int i = 0; i < P.size(); i++) {
        if (P[i] == t.size()) {
            cout << i - 2 * t.size() << ' ';
        }
    }
    return 0;
}
