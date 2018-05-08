#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll; 
ll a[200005];
ll psum[200005];  
pair<ll,int> dp[200005];  
int main(){
	int n,k; 
	cin >> n >> k;  
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++){
		psum[i] = psum[i-1]+a[i]; 
	}
	dp[k].first = psum[k]; // sum from [1,k]
	dp[k].second = 1; 
	for (int i = k+1; i <= n; i++){
		if (psum[i]-psum[i-k] > dp[i-1].first){
			dp[i].first = psum[i]-psum[i-k]; 
			dp[i].second = i-k+1;  
		}else{
			dp[i].first = dp[i-1].first; 
			dp[i].second = dp[i-1].second;  
		}
	}
	ll ans = 0; 
	int idx1 = -1,idx2 = -1;  
	for (int i = 1; i <= n; i++){
		if (dp[i-1].first+psum[i+k-1]-psum[i-1] > ans){
			ans = dp[i-1].first+psum[i+k-1]-psum[i-1];  
			idx1 = dp[i-1].second; 
			idx2 = i;  
		}
	}
	cout << idx1 << " " << idx2 << endl; 
	return 0;  
}
