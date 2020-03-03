#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // Считываем данные в массив строк
    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    // Вычисляем количество раундо (равно длине элемента)
    int m = A[0].size();
    for (int i = m - 1; i >= 0; i--) {
        // Заводим 26 корзин (26 букв в английском алфавите)
        vector<vector<string> > bucket(26);
        // Применяем сортировку подсчётом
        for (int j = 0; j < n; j++) {
            // A[j][i] - это символ от 'a' до 'z'
            // Чтобы номер буквы достаточно вычесть код символа 'a'
            bucket[A[j][i] - 'a'].push_back(A[j]);
        }
        int p = 0;
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < bucket[j].size(); k++) {
                A[p] = bucket[j][k];
                p++;
            }
        }
    }
    // Выводим отсортированный
    for (int i = 0; i < n; i++) {
        cout << A[i] << ' ';
    }
    return 0;
}
