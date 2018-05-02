#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <cstring> 
#include <algorithm>
using namespace std; 
const int maxn = 5000005;  
typedef long long ll;  
int prime[maxn];  
int parent[maxn]; // parent[i] = smallest prime factor of i
ll f[maxn]; // f[i] = sum of prime factors from 1...i 
void eratos(){
	for (int i = 0; i < maxn; i++){
		prime[i] = 1;  
	}
	prime[0] = prime[1] = 0; 
	for (ll i = 2; i < maxn; i++){
		if (prime[i]){
			parent[i] = i;  
			for (ll j = i*i; j <= maxn; j += i){
				parent[j] = i; 
				prime[j] = 0;  
			}
		}
	}
	for (int i = 2; i < maxn; i++){
		f[i] = f[i/parent[i]]+1;  
	}
	for (int i = 1; i < maxn; i++){
		f[i] += f[i-1];  
	}
}
int main(){
	eratos(); 
	int q; 
	cin >> q; 
	while (q--){
		int a,b; 
		scanf("%d %d",&a,&b); 
		// find sum of prime factors of 
		// (b+1,b+2,...,a-1,a) 
		printf("%lld\n",f[a]-f[b]); 
	}
	return 0; 
}
