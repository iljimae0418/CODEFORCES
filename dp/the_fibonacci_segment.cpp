#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[100005]; 
int dp[100005]; // dp[i] = max length of good sequence ending at index i. 
int main(){
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	dp[1] = 1; 
	dp[2] = 2;
	int maxval; 
	if (n == 1){
		maxval = 1;  
	}else{
		maxval = 2; 
	}
	for (int i = 3; i <= n; i++){
		if (a[i] == a[i-1]+a[i-2]){
			dp[i] = dp[i-1]+1; 
		}else{
			dp[i] = 2;  
		}
		maxval = max(maxval,dp[i]); 
	}
	cout << maxval << endl; 
	return 0; 
}
