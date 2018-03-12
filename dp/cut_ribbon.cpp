#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std; 
int cache[4005]; 
const int INF = 987654321;  
int a,b,c;  
int solve(int n){
	if (n == 0) return 0; 
	if (n < 0) return 0; 
	int &ret = cache[n]; 
	if (ret != -1) return ret;
	ret = -INF;  
	if (n >= a) ret = max(ret,solve(n-a)+1); 
	if (n >= b) ret = max(ret,solve(n-b)+1); 
	if (n >= c) ret = max(ret,solve(n-c)+1); 
	return ret;  
}
int main(){
	int n; 
	cin >> n >> a >> b >> c; 
	memset(cache,-1,sizeof(cache)); 
	cout << solve(n) << endl; 
	return 0;  
}

/*
This is a brute force code that also solves the problem 

#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std; 
int n,a,b,c; 
int main(){
	cin >> n >> a >> b >> c; 
	int maxval = -1; 
	for (int k1 = 0; k1 <= n/a; k1++){
		for (int k2 = 0; k2 <= n/b; k2++){
			int rem = n-k1*a-k2*b;  
			if (rem >= 0 && rem%c == 0){
				maxval = max(maxval,k1+k2+rem/c); 
			}
		}
	}
	cout << maxval << endl; 
	return 0;  
}
*/  

/*
This is a bottom up dp code that also solves the problem 

#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std; 
int dp[4005]; 
int n,a,b,c; 
const int INF = 987654321; 
int main(){
	cin >> n >> a >> b >> c; 
	for (int i = 1; i <= n; i++){
		dp[i] = -INF;  
		if (i-a >= 0) dp[i] = max(dp[i],dp[i-a]+1); 
		if (i-b >= 0) dp[i] = max(dp[i],dp[i-b]+1); 
		if (i-c >= 0) dp[i] = max(dp[i],dp[i-c]+1); 
	}
	cout << dp[n] << endl;
	return 0; 
}
*/  
