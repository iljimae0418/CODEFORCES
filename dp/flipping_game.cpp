#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int a[101],b[101]; 
int dp[101];  
int main(){
	int n,ans = 0; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		if (a[i] == 0) b[i] = 1; 
		else b[i] = -1; 
		if (a[i]) ans++; 
	}
	// we calculate the maximum subarray sum of b[] 
	dp[0] = b[0]; 
	int maxval = dp[0]; 
	for (int i = 1; i < n; i++){
		dp[i] = max(b[i],dp[i-1]+b[i]); 
		maxval = max(maxval,dp[i]); 
	}
	cout << ans+maxval << endl; 
	return 0; 
}
