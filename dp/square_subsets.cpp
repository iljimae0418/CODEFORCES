#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector> 
using namespace std;  
typedef long long ll;
const ll MOD = 1e9 + 7;
int p[21],a[100005];   
int primes[22] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};   
ll power(ll base,ll expo,ll mod){
	ll ret = 1LL; 
	while (expo > 0){
		if (expo & 1) ret = (ret * base)%mod;  
		base = (base * base)%mod; 
		expo >>= 1;  
	}
	return ret; 
}
int main(){
	int n,i,x,j,now,sum; 
	cin >> n; 
	for (i = 1; i <= n; i++){
		cin >> x; 
		for (j = 0; j <= 18; j++){
			now = 0;  
			while (x%primes[j] == 0){
				x /= primes[j];  
				now ^= 1;  
			}
			a[i] |= now*(1<<j);  
		}
	}
	for (i = 1; i <= n; i++){
		for (j = 18; j >= 0; j--){
			if (a[i]&(1<<j)){
				if (p[j] == 0){
					p[j] = a[i]; 
					break; 
				}else{
					a[i] ^= p[j];  
				}
			}
		}
	}
	sum = n; 
	for (j = 0; j <= 18; j++){
		if (p[j]) sum--; 
	}
	cout << power(2LL,sum,MOD)-1 << endl; 
	return 0;  
}
