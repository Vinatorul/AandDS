#include <iostream>
#include <vector>
using namespace std;

int main() {
	// Чтение входных данных в соответствии с форматом
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int counter = 0;
	// Алгоритм сортировки "пузырьком"
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) { // 0 и n - 1
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
				counter += 1;
			}
		}
	}
	// вывод в соответствии с форматом
	cout << counter;
	return 0;
}






