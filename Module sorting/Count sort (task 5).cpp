#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    int Amin = 1e9;
    int Amax = -1e9;
    // Считываем массив, параллельно вычисляя минимум и максимум
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        Amin = min(Amin, A[i]);
        Amax = max(Amax, A[i]);
    }
    // Массив для подсчёта размера max - min + 1
    vector<int> C(Amax - Amin + 1);
    // Подсчитываем количество вхождений каждого элемента
    for (int i = 0; i < n; i++) {
        C[A[i] - Amin]++;
    }
    // Создаём массив В и заполняем его уже в отсортированном порядке
    vector<int> B(n);
    int k = 0;
    for (int i = 0; i < C.size(); i++) {
        for (int j = 0; j < C[i]; j++) {
            B[k] = i + Amin;
            k++;
        }
    }
    // Вывод ответа
    for (int i = 0; i < n; i++) {
        cout << B[i] << " ";
    }
    return 0;
}
