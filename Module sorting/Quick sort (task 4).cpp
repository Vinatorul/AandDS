#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &A, int l, int r) {
    // Инициализация
    int i = l;
    int j = r - 1;
    int v = A[(l + r - 1) / 2];
    // Запускаем цикл, пока индексы не встретятся
    while (i <= j) {
        // Двигаем индекс i, пока A[i] упорядочены относительно разделяющего элемента
        while (A[i] < v)
            i++;
        // Двигаем индекс j, пока A[j] упорядочены относительно разделяющего элемента
        while (A[j] > v)
            j--;
        // Если индексы встретелись - выходим
        if (i >= j)
            break;
        // Если мы дошли до сюда, то A[i] и A[j] стоят не на своих местах, меняем
        swap(A[i], A[j]);
        i++;
        j--;
    }
    // Возвращаем индекс по которому произошло разделение
    return j + 1;
}

void quicksort(vector<int> &A, int l, int r) {
    // Если полуинтервал имеет длину меньше 2, то сортировать нечего
    if (r - l <= 1) {
        return;
    }
    // Разбиваем массив на два полуинтервала
    int q = partition(A, l, r);
    // Сортируем два новых полуинтервала независимо
    quicksort(A, l, q);
    quicksort(A, q, r);
}

int main() {
    // Ввод данных
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    quicksort(v, 0, n);
    for (int i = 0; i < n; ++i) {
        cout << v[i] << ' ';
    }
    return 0;
}
