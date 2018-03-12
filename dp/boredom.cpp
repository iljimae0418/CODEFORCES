#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
typedef long long ll; 
ll dp[100005],cnt[100005]; 
const ll INF = 2e11+88;  
int main(){
	int n; 
	cin >> n; 
	while (n--){
		int x; 
		cin >> x; 
		cnt[x]++; 
	}
	dp[0] = 0, 
	dp[1] = cnt[1]; 
	for (ll i = 2; i <= 100000; i++){
		dp[i] = max(dp[i-1],dp[i-2]+i*cnt[i]);  
	}
	cout << dp[100000] << endl; 
	return 0; 
}
