#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map> 
using namespace std; 
typedef long long ll;  
ll a[100005]; 
ll prime[100005]; 
void eratos(){
	for (ll i = 0; i < 100005; i++){
		prime[i] = 1;  
	}
	prime[0] = prime[1] = 0; 
	for (ll i = 2; i < 100005; i++){
		if (prime[i]){
			for (ll j = i*i; j < 100005; j += i){
				prime[j] = 0;  
			}
		}
	}
}
int main(){
	ll n; 
	cin >> n; 
	map<ll,ll> freq; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		ll x = a[i]; 
		for (ll j = 2; j*j <= a[i]; j++){
			if (x%j == 0){
				freq[j]++;  
				while (x%j == 0){
					x /= j; 
				}
			}
		}
		if (x > 1) freq[x]++; 
	}
	ll maxcnt = 0, max_prime_factor = -1;  
	for (map<ll,ll>::iterator it = freq.begin(); it != freq.end(); it++){
		if (it->second > maxcnt){
			maxcnt = it->second; 
			max_prime_factor = it->first;  
		}
	}
	if (max_prime_factor == -1){
		cout << 1 << endl; 
		return 0; 
	}
	int cnt = 0;  
	for (int i = 0; i < n; i++){
		if (a[i]%max_prime_factor == 0){
			cnt++; 
		}
	}
	cout << cnt << endl; 
	return 0;  
}
