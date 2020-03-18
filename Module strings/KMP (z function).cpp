#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> z_function(const string &s) {
    vector<int> Z(s.size());
    Z[0] = s.size();
    int l = 0;
    int r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= r) {
            Z[i] = min(Z[i - l], r - i + 1);
        }
        while (i + Z[i] < s.size() && s[Z[i]] == s[i + Z[i]]) {
            Z[i] += 1;
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

int main() {
    string s, t;
    cin >> s >> t;
    string t_s = t + "&" + s;
    vector<int> Z = z_function(t_s);
    for (int i = 0; i < Z.size(); i++) {
        if (Z[i] == t.size()) {
            cout << i - t.size() - 1 << ' ';
        }
    }
    return 0;
}
