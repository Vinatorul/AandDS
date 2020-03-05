#include <iostream>
#include <string>
using namespace std;

int get_hash(string &s, int n, int p, int x) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = (1ll * res * x + s[i]) % p;
    }
    return res;
}

int rabin_karp(string &s, string &t, int p, int x) {
    // Вычислили хеш искомой строки
    int ht = get_hash(t, t.size(), p, x);
    // Вычислили хеш строки S[0 .. t.size()]
    int hs = get_hash(s, t.size(), p, x);
    // Вычислили xt, нужно для скользящего хеша 
    int xt = 1;
    for (int i = 0; i < t.size(); i++) {
        xt = (1ll * xt * x) % p; 
    }
    for (int i = 0; i <= s.size() - t.size(); i++) {
        // Если хеши совпали - с высокой вероятностью мы наши вхождение
        if (ht == hs) {
            // здесь можно дополнительно проверить, является ли совпадение коллизией
            // или строки действительно одинаковые
            return i;
        }
        if (i + t.size() < s.size()) {
            // Вычисляем сдвинутый хеш, не забываем про переполнения и добавляем 1ll
            hs = (1ll * hs * x - 1ll * s[i] * xt + s[i + t.size()]) % p;
            // Хеш может получиться отрицательный из-за вычитания, исправим
            hs = (hs + p) % p;
        } 
    }
    // Ничего не нашли :(
    return -1;
}

int main() {
    // считаем строки
    string s, t;
    cin >> s >> t;
    int p = 1e9 + 7;
    int x = 26;
    cout << rabin_karp(s, t, p, x);
    return 0;
}
