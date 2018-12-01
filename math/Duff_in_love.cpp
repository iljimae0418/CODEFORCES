#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <algorithm> 
#include <vector> 
#include <map> 
using namespace std; 
typedef long long ll; 
const int MAXK = 1e6+5;  
int prime[MAXK]; 
void eratos(){
	for (int i = 0; i < MAXK; i++){
		prime[i] = 1; 
	}
	prime[0] = prime[1] = 0; 
	for (ll i = 2; i < MAXK; i++){
		if (prime[i]){
			for (ll j = i*i; j < MAXK; j += i){
				prime[j] = 0; 
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	ll n; 
	cin >> n; 
	ll ans = 1LL;  
	ll x = n;  
	for (ll i = 2; i*i <= n; i++){
		if (x%i == 0){
			ans *= i;  
			while (x%i == 0){
				x /= i;  
			}
		}
	}
	if (x > 1){
		ans *= x;  
	}
	cout << ans << "\n";  
	return 0; 
}
