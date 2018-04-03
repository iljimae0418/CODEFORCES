#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
const int mod = 1e9+7; 
long long dp[100005];
long long psum[100005];  
int main(){
	int t,k; 
	cin >> t >> k; 
	for (int i = 0; i < k; i++){
		dp[i] = 1LL;  
	}
	for (int i = k; i <= 100000; i++){
		dp[i] = (dp[i-1]%mod + dp[i-k]%mod)%mod;  
	}	
	for (int i = 1; i <= 100000; i++){
		psum[i] = (psum[i-1]%mod + dp[i]%mod)%mod; 
	}
	while (t--){
		int a,b; 
		cin >> a >> b; 
		cout << (psum[b]-psum[a-1]+mod)%mod << endl; 
	}
	return 0;  
}
