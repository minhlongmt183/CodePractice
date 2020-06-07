#include <iostream>
using namespace std;
int Sum(int a[], int n)
{
	int Sum1 = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > 0)
		{
			Sum1 += a[i];
		}
		
	}
	return Sum1;
}

int main()
{
	int a[100];
	int n;
	cin >> n;
	cout << Sum(a, n);
	return 0;
}
