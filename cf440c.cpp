#include <iostream>
#include <cstdio> 
#include <cmath> 
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std; 
int dp[16]; 
// only 4,6,9 appears on the composite sum for up to 15. 
int sub[3] = {4,6,9}; 
int main(){
	memset(dp,-1,sizeof(dp));  
	dp[0] = 0; // 0 length composite sum 
	for (int i = 1; i <= 15; i++){
		for (int j = 0; j < 3; j++){
			if (i >= sub[j] && dp[i-sub[j]] != -1){
				dp[i] = max(dp[i],dp[i-sub[j]]+1); 
			}
		}
	}
	int q; 
	scanf("%d",&q); 
	while (q--){
		int i; 
		scanf("%d",&i); 
		if (i <= 15){
			printf("%d\n",dp[i]);  
		}else if (i > 15){
			int k = ceil((double)(i-15)/4.0);    
			printf("%d\n",k+dp[i-4*k]); 
		}
	}
	return 0; 
}
