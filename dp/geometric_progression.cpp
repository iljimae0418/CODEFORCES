#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <vector> 
#include <map> 
using namespace std; 
typedef long long ll;    
int a[200005]; 
int main(){
	map<ll,ll> rt,lt;  
	int n;
	ll k; 
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		rt[a[i]]++; 
	}
	ll ans = 0;  
	for (int i = 1; i <= n; i++){
		ll cnt1 = 0, cnt2 = 0;  
		if (a[i]%k == 0){
			cnt1 = lt[a[i]/k];  
		}
		rt[a[i]]--;  
		cnt2 = rt[a[i]*k];  
		ans += cnt1*cnt2; 
		lt[a[i]]++;  
	}
	cout << ans << endl; 
	return 0;  
}
