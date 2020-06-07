#include <iostream>
#include <vector>
using namespace std;

int CountSum(std::vector<std::vector<int>> a, int x, int y){
	int sum = a[x+1][y+1];
	for(int i = 0; i < 3; ++i){
		sum +=  a[x][y+i];
		sum += a[x + 2][y+i];
	}
	
	return sum;
}

int hourglassMaxSum(std::vector<std::vector<int>> a)
{
	int maxSum = 0;
	
	for (int i = 0; i < a.size() -3; i++){
		for (int j = 0; j < a[i].size() - 3; j++){
			if (a[i][j] != 0){
				int sum = CountSum(a, i,j);
				maxSum = (sum > maxSum)? sum : maxSum;
				i += 2;
			}
		}
	}
	return maxSum;

}
int main(){
	std::vector<std::vector<int>> a = {{1,1,1,0,0,0},{0,1,0,0,0,0},{1,1,1,0,0,0},{0,0,2,4,4,0},{0,0,0,2,0,0},{0,0,1,2,4,0}};
	cout << hourglassMaxSum(a) << "\n";
	return 0;

}
