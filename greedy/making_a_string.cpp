#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <set> 
using namespace std; 
typedef long long ll; 
ll a[30];
set<ll> used;  
int main(){
	int n; 
	ll ans = 0; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n,greater<ll>()); 
	for (int i = 0; i < n; i++){
		if (used.count(a[i])){
			for (ll j = a[i]-1;;j--){
				if (j == 0) break; // we skip 
				if (!used.count(j)){
					ans += j; 
					used.insert(j); 
					break; 
				}
			}
		}else{
			ans += a[i];  
			used.insert(a[i]); 
		}
	}
	cout << ans << endl; 
	return 0; 
}
