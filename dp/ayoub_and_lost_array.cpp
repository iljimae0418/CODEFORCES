#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
const int mod = 1e9+7;  
long long dp[200005][3];  
int main(int argc,char **argv){
	int n,l,r;  
	cin >> n >> l >> r; 
	long long m0 = (r/3)-((l+3-1)/3)+1; // ceil(a/b) = (a+b-1)/b
	long long m1 = ((r-1)/3)-((l-1+3-1)/3)+1;  
	long long m2 = (r-2 >= 0 ? ((r-2)/3)-((l-2+3-1)/3)+1 : 0); 
	m0 %= mod; 
	m1 %= mod; 
	m2 %= mod; 
	dp[1][0] = m0, dp[1][1] = m1, dp[1][2] = m2;  
	for (int i = 2; i <= n; i++){
		dp[i][0] = dp[i-1][0]*m0 + dp[i-1][1]*m2 + dp[i-1][2]*m1; 
		dp[i][0] %= mod;  
		dp[i][1] = dp[i-1][0]*m1 + dp[i-1][1]*m0 + dp[i-1][2]*m2;  
		dp[i][1] %= mod; 
		dp[i][2] = dp[i-1][0]*m2 + dp[i-1][1]*m1 + dp[i-1][2]*m0; 
		dp[i][2] %= mod; 
	}
	cout << dp[n][0] << endl; 
	return 0;  
}
