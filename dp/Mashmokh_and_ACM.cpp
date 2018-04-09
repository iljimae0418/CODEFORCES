#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
int dp[2005][2005]; 
vector<int> multiple[2005]; 
const int mod = 1e9+7; 
int main(){
	int n,k; 
	cin >> n >> k; 
	// fill in the multiple array 
	for (int i = 1; i <= n; i++){
		if (i == 1) multiple[i].push_back(1); 
		else if (i > 1){
			multiple[i].push_back(1);  
			multiple[i].push_back(i); 
		}
		for (int j = 2; j*j <= i; j++){
			if (i%j == 0){
				if (j == i/j){
					multiple[i].push_back(j);  
				}else{
					multiple[i].push_back(j);  
					multiple[i].push_back(i/j);  
				}
			}
		}
	}
	// fill in dp table 
	for (int i = 1; i <= n; i++){
		dp[i][0] = 0; 
		dp[i][1] = 1; 
	}
	for (int i = 1; i <= n; i++){
		for (int j = 2; j <= k; j++){
			for (int l = 0; l < multiple[i].size(); l++){
				dp[i][j] = (dp[i][j]%mod+dp[multiple[i][l]][j-1]%mod)%mod; 
			}
		}	
	}
	int ans = 0; 
	for (int i = 1; i <= n; i++){
		ans = (ans%mod + dp[i][k]%mod)%mod; 
	}
	cout << ans << endl; 
	return 0; 
}
