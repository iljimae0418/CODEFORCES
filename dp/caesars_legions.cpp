#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std; 
int mod = 1e8;  
int cache[101][101][11][11]; 
int n1,n2,k1,k2;  
int solve(int f,int h,int cf,int ch){
	if (f == 0 && h == 0) return 1; 
	int &ret = cache[f][h][cf][ch]; 
	if (ret != -1) return ret; 
	ret = 0;  
	if (f > 0 && cf < k1) ret = (ret%mod + solve(f-1,h,cf+1,0)%mod)%mod;
	if (h > 0 && ch < k2) ret = (ret%mod + solve(f,h-1,0,ch+1)%mod)%mod; 
	return ret; 
}
int main(){
	cin >> n1 >> n2 >> k1 >> k2;
	memset(cache,-1,sizeof(cache));  
	int ans = solve(n1,n2,0,0); 
	cout << ans << endl;
	return 0;  
}
