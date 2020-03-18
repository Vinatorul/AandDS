#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(string &s) {
    // Создадим массив P размера длины строки S
    vector<int> res(s.size());
    res[0] = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        int j = res[i];
        // Пока элементы не равны - пытаемся рассмотреть префиксы меньшей длины
        // переходя по бордерам
        while (j > 0 && s[i + 1] != s[j]) {
            j = res[j - 1];
        }
        // Если символы совпали, то префикс i + 1 равен в точности j+1 
        if (s[i + 1] == s[j]) {
            res[i + 1] = j + 1;
        } else {
            res[i + 1] = 0;
        }
    }
    return res;
}

int main() {
    // считаем строку
    string s;
    cin >> s;
    vector<int> p = prefix_function(s);
    for (int i = 0; i < p.size(); i++) {
        cout << p[i] << ' ';
    }
    return 0;
}
