#include <iostream>
using namespace std;
 int min( int a,  int b)
{
	if (a <= b) return a;
	else {
		return b;
	}
}
int main()
{
	 int t[25000], r[25000], f[25000];
	 int n;
	cin >> n;
	for ( int i = 1; i <= n; i++)
	{
		cin >> t[i];
	}
	for (int i = 1; i <= n-1; i++)
	{
		cin >> r[i];
	}
	f[0] = 0;
	f[1] = t[1];
	for (int i = 2; i <= n; i++)
	{
		f[i] = min(f[i - 2] + r[i - 1], f[i - 1] + t[i]);
	}
	cout << f[n];
	return 0;
}
