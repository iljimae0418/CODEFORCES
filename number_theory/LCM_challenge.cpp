#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
typedef long long ll; 
const int MAXN = 1000005;
ll INF = 2e18;   
int prime[MAXN]; 
void eratos(){
	for (int i = 0; i < MAXN; i++){
		prime[i] = 1;  
	}
	prime[0] = prime[1] = 0; 
	for (ll i = 2; i < MAXN; i++){
		if (prime[i]){
			for (ll j = i*i; j < MAXN; j += i){
				prime[j] = 0; 
			}
		}
	}
}
ll gcd(ll a,ll b){
	if (b == 0LL) return a; 
	return gcd(b,a%b);  
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);  
}
int main(){
	ll n; 
	cin >> n; 
	eratos(); // run sieve algorithm 
	vector<ll> v; 
	if (n == 1LL) cout << 1 << endl; 
	else if (n == 2LL) cout << 2 << endl; 
	else if (n == 3LL) cout << 6 << endl; 
	else{
		if (n%2 == 1){
			cout << n*(n-1)*(n-2) << endl; 
		}else{
			if (n%3 == 0){
				cout << (n-1)*(n-2)*(n-3) << endl; 
			}else{
				cout << n*(n-1)*(n-3) << endl; 
			}
		}
	}
	return 0;  
}
