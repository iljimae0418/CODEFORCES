#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll; 
ll psum[500005]; // initialised to zero 
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		ll x; 
		cin >> x; 
		psum[i] = psum[i-1]+x; 
	}
	ll ans = 0; 
	if (psum[n]%3 == 0){
		ll u = psum[n]/3, v = 2*psum[n]/3;  
		ll cnt = 0; 
		for (int i = 1; i < n; i++){
			if (psum[i] == v) ans += cnt; 
			if (psum[i] == u) cnt++; 
		}
	}	
	cout << ans << endl; 
	return 0;  
}
