#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> a;
	int n, number;
	cin >> n;
	
	for (int i = 0; i < n; ++i){
		cin >> number;
		a.push_back(number);
	}
	
	int min = 1;
	vector<int>::iterator pos = std::find(a.begin(), a.end(), min);
	
	while(pos != a.end()){
		++min;
		pos = find(a.begin(), a.end(), min);
	}
	cout << min << '\n';

	return 0;
}
