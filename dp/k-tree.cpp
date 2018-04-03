#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
#include <cmath> 
using namespace std; 
const int mod = 1e9+7;  
int n,k,d; 
int cache[100][2]; 
int solve(int sum,int exist){
	if (sum == n && exist) return 1; 
	int &ret = cache[sum][exist]; 
	if (ret != -1) return ret; 
	ret = 0; 
	for (int i = 1; i <= k; i++){
		if (sum+i <= n){
			if (i >= d) ret = (ret%mod + solve(sum+i,1)%mod)%mod; 
			if (i < d && exist) ret = (ret%mod + solve(sum+i,1)%mod)%mod; 
			if (i < d && !exist) ret = (ret%mod + solve(sum+i,0)%mod)%mod;  
		}
	}
	return ret; 
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cin >> n >> k >> d;  
	int ans = 0; 
	for (int i = 1; i <= k; i++){
		memset(cache,-1,sizeof(cache)); 
		if (i >= d) ans = (ans%mod + solve(i,1)%mod)%mod; 
		else ans = (ans%mod + solve(i,0)%mod)%mod; 
	}
	cout << ans << endl;
	return 0;  
}
