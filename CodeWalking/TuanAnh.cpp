#include<iostream>
#include<vector>
using namespace std;

int count(int n){
    if (n == 1) return 1;
    if (n == 2) return 2;
    return 1 + 2*count(n-1);
}



int main() {
	int n;
    cout << "nhap n\n";
    cin >> n;
    if (n % 2 != 0)
        cout << 0 << '\n';
    else cout << count (n / 2) << '\n';

    return 0;
}



