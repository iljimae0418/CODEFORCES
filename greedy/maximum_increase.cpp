#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int a[100005],dp[100005];  
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	dp[1] = 1; 
	int maxval = dp[1];  
	for (int i = 2; i <= n; i++){
		if (a[i] > a[i-1]) dp[i] = dp[i-1]+1; 
		else dp[i] = 1; 
		maxval = max(maxval,dp[i]); 
	}
	cout << maxval << endl; 
	return 0; 
}
