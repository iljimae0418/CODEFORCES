#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;  
typedef long long ll;  
ll a[100005]; 
int main(){	
	ll n,k,l;  
	cin >> n >> k >> l; 
	for (int i = 0; i < n*k; i++){
		cin >> a[i]; 
	}
	sort(a,a+n*k);  
	ll x = a[0]+l; 
	ll leq = 0, g = 0; 
	int firstIdx = -1;  
	for (int i = 0; i < n*k; i++){
		if (a[i] <= x) leq++; 
		else{
			if (firstIdx == -1) firstIdx = i;  
			g++;
		} 
	}
	if (a[0]+l < a[n-1]){
		cout << 0 << endl; 
	}else{
		ll v = n*k-1; 
		ll rest = 0; 
		for (int i = 1; i < n*k; i++){
			if (a[0]+l < a[i]){
				v = i-1; 
				rest = n*k-i;  
				break; 
			}
		}
		ll sum = 0; 
		for (int i = 0; i < n; i++){
			if (rest >= k-1){
				rest -= k-1; 
				sum += a[v]; 
				v--; 
			}else{
				int p = k-1-rest; 
				rest = 0; 
				v -= p; 
				sum += a[v]; 
				v--; 
			}
		}
		cout << sum << endl; 
	}
	return 0; 
}
