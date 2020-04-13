#include <math.h> 
#include<iostream> 
using namespace std;

float F1(float x)
{
	float result = 0;

	if (x >= 0)
	{
		result = 5 * x + 7;
	}
	else
	{
		result = 1 / x;
	}
	return result;
}
float F2(float& x)

{
	x = F1(x);
	return x;

}

int main()
{
	int m, n;
	cout << "Vvedite nachalo = ";
	cin >> m;
	cout << "Vvedite konech = ";
	cin >> n;
	cout << "Function 1:" << endl;
	for (float i = m; i < n; i++)
	{
		cout << "i=" << i << ";F1(i)=" << F1(i) << endl;
	}
	cout << "Function 2:" << endl;

	for (float i = m; i < n; i++)

	{

		cout << " i = " << i << "; F2(i) = " << F2(i) << endl;

	}
	system("pause");
	return 0;
}
