#include <iostream>
#include <string>
using namespace std;

int get_hash(string &s) {
    // выберем большое простое число
    int p = 1e9 + 7;
    // выберем число x
    int x = 26;
    // Запустим итеративный алгоритм вычисления полиномиального хеша
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        // H(i) = (H(i-1) * x + s[i]) mod p
        // 1ll нужно для того, чтобы выражение res * x вычислялось в типе long long
        res = (1ll * res * x + s[i]) % p;
    }
    return res;
}

int main() {
    // считаем строку
    string s;
    cin >> s;
    cout << get_hash(s);
    return 0;
}
