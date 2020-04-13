#include <iostream>
using namespace std;
struct element {
	double value;
	element* pointer;
	element() {
		value = 0;
		pointer = NULL;
	}
};
void F1(element*& First, int n) {
	element* p = NULL;
	int i = 0, a;
	double b;
	while (i < n) {
		element* d = new element();
		cout << "Введите элемент списка" << endl;
		cin >> d->value;
		if (First == NULL) {
			First = d;
			p = d;
		}
		else {
			p->pointer = d;
			p = d;
		}
		i++;
		a = (int)d->value;
		b = d->value - a;
		cout << "Целая часть : " << a << endl;
		cout << "Дробная часть : " << b << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	int N;
	cout << "Введите количество элементов списка: " << endl;
	cin >> N;
	cout << "Элементов в списке: " << N << endl;
	element* first = NULL;
	F1(first, N);
	return 0;
}