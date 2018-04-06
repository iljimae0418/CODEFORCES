#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std;  
typedef pair<int,int> P; 
typedef long long ll;  
P a[200005]; 
int main(){
	int n; 
	cin >> n; 
	map<ll,ll> mpx,mpy;
	map<P,ll> mpp;    
	for (int i = 0; i < n; i++){
		ll x,y; 
		cin >> x >> y; 
		mpx[x]++; 
		mpy[y]++; 
		mpp[P(x,y)]++;  
	}
	long long ans = 0; 
	for (map<ll,ll>::iterator it = mpx.begin(); it != mpx.end(); it++){
		if (it->second >= 2) ans += (it->second)*(it->second - 1)/2;  
	}
	for (map<ll,ll>::iterator it = mpy.begin(); it != mpy.end(); it++){
		if (it->second >= 2) ans += (it->second)*(it->second - 1)/2; 
	}
	for (map<P,ll>::iterator it = mpp.begin(); it != mpp.end(); it++){
		if (it->second > 1) ans -= (it->second)*(it->second - 1)/2;  
	}
	cout << ans << endl; 
	return 0;  
}
