#include <iostream>
using namespace std;
void F1(double* mas, int N) {
	setlocale(LC_ALL, "RUS");
	int a;
	double x;
	for (int i = 0; i < N; i++) {
		a = (int)mas[i];
		x = mas[i] - a;
		cout << "цел" << a << endl;
		cout << "дроб" << x << endl;
	}
}
int main() {
	setlocale(LC_ALL, "RUS");
	int N;
	cin >> N;
	double* mas = new double[N];
	for (int i = 0; i < N; i++) {
		cin >> mas[i];
	}
	F1(mas, N);
	system("pause");
	return 0;
}
