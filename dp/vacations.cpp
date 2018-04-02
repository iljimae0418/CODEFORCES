#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
int dp[101][3]; 
int main(){
	int num; 
	cin >> num; 
	int maxval = 0; 
	for (int i = 0; i < num; i++){
		int z; 
		cin >> z; 
		if (z & 1){
			dp[i+1][1] = max(dp[i+1][1],dp[i][0]+1); 
			dp[i+1][1] = max(dp[i+1][1],dp[i][2]+1); 
		}
		if (z & 2){
			dp[i+1][2] = max(dp[i+1][2],dp[i][0]+1);  
			dp[i+1][2] = max(dp[i+1][2],dp[i][1]+1);  
		}	
		dp[i+1][0] = max(dp[i+1][0],dp[i][0]); 
		dp[i+1][0] = max(dp[i+1][0],dp[i][1]); 
		dp[i+1][0] = max(dp[i+1][0],dp[i][2]);  
	}
	for (int i = 0; i < 3; i++){
		maxval = max(maxval,dp[num][i]); 
	}
	cout << num-maxval << endl; 
	return 0; 
}
