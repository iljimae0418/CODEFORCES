#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std; 
typedef long long ll; 
int main(){
	int n,m; 
	cin >> n >> m; 
	map<ll,ll> b1,b2; // bucket1, bucket2
	for (ll i = 1; i <= n; i++){
		b1[i%5]++; 
	}
	for (ll i = 1; i <= m; i++){
		b2[i%5]++; 
	}
	// sum of remainders (0,0),(1,4),(2,3),(3,2),(4,1)
	ll ans = b1[0]*b2[0]+b1[1]*b2[4]+b1[2]*b2[3]+b1[3]*b2[2]+b1[4]*b2[1]; 
	cout << ans << endl; 
	return 0; 
}
