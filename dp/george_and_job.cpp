// application of knapsack 
#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
using namespace std; 
typedef long long ll;  
ll a[5005],psum[5005];
ll cache[5005][5005]; // dp[i][j] = max(dp[i+1][j],dp[i+m][j+1]+psum[i+m-1]-psum[i-1]); 
int n,m,k; 
ll solve(int i,int j){
	if (i > n) return 0LL; 
	ll &ret = cache[i][j]; 
	if (ret != -1) return ret; 
	ret = solve(i+1,j); 
	if (j-1 >= 0){
		ret = max(ret,solve(i+m,j-1)+(psum[i+m-1]-psum[i-1])); 
	}
	return ret;   
}
int main(){
	ios_base::sync_with_stdio(false);  
	cin.tie(NULL); 
	cin >> n >> m >> k; 
	for (int i = 1; i <= n; i++){
		cin >> a[i];  
	}
	for (int i = 1; i <= n; i++){
		psum[i] = psum[i-1]+a[i]; 
	}
	memset(cache,-1,sizeof(cache)); 
	ll ans = solve(1,k);  
	cout << ans << endl; 
	return 0; 
}
