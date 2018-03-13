#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int a[100005];
int dp[100005],seen[100005];  
int main(){
	int n,m; 
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	dp[n-1] = 1;  
	seen[a[n-1]] = 1;  
	for (int i = n-2; i >= 0; i--){
		if (!seen[a[i]]){
			dp[i] = dp[i+1]+1;  
			seen[a[i]] = 1;  
		}else{
			dp[i] = dp[i+1];  
		}
	}
	while (m--){
		int l; 
		cin >> l;
		l--; // zero based indexing 
		cout << dp[l] << endl; 
	}
	return 0;  
}
