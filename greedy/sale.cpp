#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std;  
int a[101]; 
int n,m;  
int cache[101][101];  
int solve(int i,int j){
	if (i == n) return 0; 
	if (j == m) return 0; 
	int &ret = cache[i][j];  
	if (ret != -1) return ret;  
	return ret = max(solve(i+1,j),solve(i+1,j+1)+a[i]);  
}
int main(){
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		a[i] *= -1; 
	}
	sort(a,a+n,greater<int>()); 
	memset(cache,-1,sizeof(cache));  
	cout << solve(0,0) << endl; 
	return 0; 
}	
