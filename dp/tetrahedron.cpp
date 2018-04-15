#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <vector> 
using namespace std; 
int dp[10000001][4]; 
const int mod = 1e9+7;   
int main(){
	int n; 
	cin >> n; 
	dp[0][3] = 1; 
	dp[0][0] = dp[0][1] = dp[0][2] = 0; 
	dp[1][3] = 0; 
	dp[1][0] = dp[1][1] = dp[1][2] = 1;  
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < 4; j++){
			for (int k = 0; k < 4; k++){
				if (k != j){
					dp[i][j] = (dp[i][j]%mod + dp[i-1][k]%mod)%mod;  
				}
			}
		}
	}
	cout << dp[n][3] << endl;
	return 0; 
}
