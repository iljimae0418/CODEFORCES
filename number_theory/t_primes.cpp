#include <iostream>
#include <cstdlib>
#include <set> 
using namespace std;
typedef long long ll;  
ll a[100005];  
int prime[1000001];  
void sieve(){
	for (int i = 0; i <= 1000000; i++){
		prime[i] = 1;  
	}
	prime[0] = prime[1] = 0; 
	for (ll i = 2; i <= 1000000; i++){
		if (prime[i]){ 
			for (ll j = i*i; j <= 1000000; j += i){
				prime[j] = 0;  
			}
		}
	}
}
int main(){
	int n;
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sieve(); // run sieve 
	set<ll> tprime; 
	for (ll i = 1; i <= 1000000; i++){
		if (prime[i]) tprime.insert(i*i); 
	}
	for (int i = 0; i < n; i++){
		if (tprime.count(a[i])) cout << "YES" << endl; 
		else cout << "NO" << endl; 
	}
	return 0; 
}
