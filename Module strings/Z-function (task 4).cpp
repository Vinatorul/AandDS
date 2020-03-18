#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> z_function(string &s) {
    // Создадим массив Z размера длины строки S
    vector<int> Z(s.size());
    Z[0] = s.size();
    // Проинициализируем самый правый отрезок [0, 0] 
    int l = 0;
    int r = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= r) {
            // если i внутри отрезка [l, r], то выбираем начальное приближение
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        // Запускаем наивный алгоритм подсчёта Z-функции
        while (i + Z[i] < s.size() && s[Z[i]] == s[Z[i] + i]) {
            Z[i]++;
        }
        // Если мы просмотрели строку правее, чем r, то обновим отрезок [l, r]
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

int main() {
    // считаем строку
    string s;
    cin >> s;
    vector<int> Z = z_function(s);
    for (int i = 0; i < Z.size(); i++) {
        cout << Z[i] << ' ';
    }
    return 0;
}
