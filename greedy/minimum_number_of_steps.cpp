#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll; 
const ll mod = (ll)1e9+7; 
ll mod_pow(ll a,ll x){
	ll res = 1LL; 
	while (x > 0){
		if (x&1) res = (res*a)%mod;  
		a = (a*a)%mod; 
		x >>= 1;  
	}
	return res; 
} 
int main(){
	string s; 
	cin >> s; 
	ll ans = 0, cnt = 0;  
	for (int i = s.size()-1; i >= 0; i--){
		if (s[i] == 'b'){
			cnt++;  
		}else{
			ans += cnt; 
			cnt *= 2; 
			ans %= mod;  
			cnt %= mod; 
		}
	}
	cout << ans << endl; 
	return 0; 
}
