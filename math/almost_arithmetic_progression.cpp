#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll;  
const ll INF = 2e17; 
ll a[100005];  
bool already_ap(ll x){
	ll d = a[1]-a[0]; 
	for (ll i = 1; i < x-1; i++){
		if (a[i+1]-a[i] != d) return false; 
	}
	return true;  
}
ll sig(ll x){
	return x*(x+1)/2LL;  
}
int main(){
	IOFAST(); 
	ll n;   
	cin >> n;  
	for (ll i = 0; i < n; i++){
		cin >> a[i]; 
	}
	if (n == 1LL || n == 2LL){
		cout << 0 << endl; 
		return 0; 
	}
	if (already_ap(n)){
		cout << 0 << endl; 
		return 0; 
	}
	// do all 9 case work 
	ll minval = INF;   
	for (ll i = -1; i <= 1; i++){
		for (ll j = -1; j <= 1; j++){
			ll cnt = 0; 
			bool can = true; 
			ll d = (a[1]+j)-(a[0]+i);
			cnt += abs(i) + abs(j); 
			ll next = (a[1]+j)+d;   
			for (ll k = 2; k < n; k++){
				if (abs(a[k]-next) > 1){
					can = false; 
					break; 
				}
				cnt += abs(a[k]-next); 
				next += d; 
			}
			if (can) minval = min(minval,cnt); 
		}
	}
	if (minval == INF) cout << -1 << endl;
	else cout << minval << endl; 
	return 0; 
}
