#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	typedef long long ll;   
	map<ll,ll> mp; 
	for (int i = 0; i < n; i++){
		ll x; 
		cin >> x; 
		mp[x]++; 
	}
	ll d = mp.rbegin()->first - mp.begin()->first; 
	ll cnt = 0; 
	if (d == 0){
		if (n == 2) cnt = 1; 
		else if (n > 2) cnt = 0.5 * mp.rbegin()->second * (mp.rbegin()->second - 1); 
	}else{
		cnt = mp.rbegin()->second * mp.begin()->second;  
	}
	cout << d << " " << cnt << endl; 
	return 0;  
}
