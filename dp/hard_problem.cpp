#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;  
// dp[i][j] = minimum amount of energy that should be spent to make first i strings 
// sorted in lexicographical order and ith of them will be reversed if j = 1 and not reversed 
// if j = 0.  dp[i][j] is updated by dp[i-1][0] and dp[i-1][1].  
string s[100005][2];  
typedef long long ll; 
ll c[100005]; 
ll dp[100005][2];  
const ll INF = (ll)2e17+88LL; 
int main(){
	int n; 
	cin >> n;  
	for (int i = 0; i < n; i++){
		cin >> c[i]; 
	}
	for (int i = 0; i < n; i++){
		cin >> s[i][0];  
		s[i][1] = s[i][0]; 
		reverse(s[i][1].begin(),s[i][1].end()); 
	}	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2; j++){
			dp[i][j] = INF;  
		}
	}
	dp[0][0] = 0; 
	dp[0][1] = c[0]; // reverse first string cost 
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < 2; j++){
			if (s[i][0] <= s[i+1][j]){
				dp[i+1][j] = min(dp[i+1][j],dp[i][0]+j*c[i+1]);  
			}
			if (s[i][1] <= s[i+1][j]){
				dp[i+1][j] = min(dp[i+1][j],dp[i][1]+j*c[i+1]);  
			}
		}
	}
	if (dp[n-1][0] == INF && dp[n-1][1] == INF){
		cout << -1 << endl; 
	}else{
		cout << min(dp[n-1][0],dp[n-1][1]) << endl; 
	}
	return 0; 
}
