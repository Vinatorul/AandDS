#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &A, vector<int> &B) {
    int i = 0;
    int j = 0;
    vector<int> C(A.size() + B.size());
    for (int k = 0; k < C.size(); k++) {
        // Если в массиве А все элементы закончились
        if (i == A.size()) {
            C[k] = B[j];
            j++;
        // Если в массиве B все элементы закончились
        } else if (j == B.size()) {
            C[k] = A[i];
            i++;
        } else if (A[i] <= B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
    }
    return C;
}

vector<int> merge_sort(vector<int> &V, int l, int r) {
    // Проверяем, не равна ли длина 1
    // Частный случай, при котором рекурсия завершается
    if (r - l == 1) {
        vector<int> res(1);
        res[0] = V[l];
        return res;
    }
    // Находим середину массива
    int m = (l + r) / 2;
    // Сортируем левую и правую половины независимо
    vector<int> left = merge_sort(V, l, m);
    vector<int> right = merge_sort(V, m, r);
    // Сливаем отсортированные половины
    return merge(left, right);
}

int main()
{
    // Чтение данных
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    // Вызов сортировки
    vector<int> v_sorted = merge_sort(v, 0, n);
    // Вывод результата
    for (int i = 0; i < n; i++) {
        cout << v_sorted[i] << ' ';
    }
    return 0;
}
