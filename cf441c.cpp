#include <iostream>
#include <cstdlib>
#include <vector> 
#include <algorithm> 
using namespace std; 
int digitsum(int x){
	int sum = 0; 
	while (x){
		sum += x%10; 
		x /= 10; 
	}
	return sum;  
}
int main(){
	// n-x = sum of digits of x 
	// x = n - sum of digits of x
	// sum of digits of 1 = 1 <= x <= sum of digits of 10^9 = 82
	int n; 
	cin >> n; 
	vector<int> ans; 
	for (int x = max(1,n-100); x < n; x++){
		if (x + digitsum(x) == n){
			ans.push_back(x);  
		}
	}
	cout << ans.size() << endl; 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << endl; 
	}
	return 0;  
}
