#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
typedef long long ll; 
ll gcd(ll a,ll b){
	if (b == 0) return a; 
	return gcd(b,a%b); 
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b); 
}
int main(){
	ll n,a,b,p,q; 
	cin >> n >> a >> b >> p >> q; 
	ll l = lcm(a,b); 
	ll k = n/l; 
	ll ans = (n/a - k)*p + (n/b - k)*q + k*max(p,q); 
	cout << ans << endl; 
	return 0; 
}
