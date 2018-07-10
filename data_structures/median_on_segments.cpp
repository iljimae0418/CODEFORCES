#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <map> 
using namespace std; 
typedef long long ll; 
#define MAXN 200005
int a[MAXN];  
int psum[MAXN];  
int main(){
	int n,m,pos = -1; 
	cin >> n >> m; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		if (a[i] < m) psum[i] = -1;  
		else if (a[i] == m){
			psum[i] = 0; 
			pos = i;  
		}else{
			psum[i] = 1;  
		}
	}
	for (int i = 1; i <= n; i++){
		psum[i] += psum[i-1];  
	}
	map<int,int> cnt; 
	cnt[psum[0]] = 1; // note that psum[0] = 0  
	for (int i = pos-1; i >= 1; i--){
		cnt[psum[i]]++;  
	}
	// proceed with binary search 
	ll ans = 0; 
	for (int r = pos; r <= n; r++){
		// psum[r]-psum[l-1] = 0 or 1  
		// psum[l-1] = psum[r] or psum[l-1] = psum[r]-1 
		ans += cnt[psum[r]] + cnt[psum[r]-1]; 
	}
	cout << ans << endl; 
	return 0;  
}	
