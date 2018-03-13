#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int dp[100005];
int main(){
	string s; 
	cin >> s; 
	int q; 
	cin >> q; 
	// fill dp table 
	dp[0] = 0; 
	for (int i = 1; i < s.size(); i++){
		dp[i] = dp[i-1]+(s[i] == s[i-1]);  
	}
	while (q--){
		int l,r;  
		cin >> l >> r; 
		l--,r--;  
		cout << dp[r]-dp[l] << endl; 
	}
	return 0; 
}
