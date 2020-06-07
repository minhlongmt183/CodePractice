#include <iostream>
#include <math.h>

using namespace std;


bool IsPrime(int n)
{
	if (n < 2) 
		return 0;

	if (n == 2 || n == 3)
		return 1;
	
	if (n % 2 == 0)
		return 0;

	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) 
			return 0;

	return 1;
}

int main()
{
	int a[1000];
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i){
		cin >> a[i];
		
		if (IsPrime(a[i]))
			cout << a[i] << "\n";
	}

	return 0;
}

