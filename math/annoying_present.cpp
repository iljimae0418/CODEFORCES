#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	typedef long long ll; 
	ll n,m; 
	cin >> n >> m; 
	ll sum = 0, maxval = n*(n-1)/2LL, minval = (n/2LL)*(n/2LL + 1LL)-(n%2 ? 0 : n/2LL); 
	while (m--){
		ll x,d; 
		cin >> x >> d; 
		sum += x*n;  
		if (d < 0) sum += d*minval; 
		if (d > 0) sum += d*maxval;  
	}
	cout.setf(ios::showpoint); 
	cout.setf(ios::fixed); 
	cout.precision(15); 
	cout << (double)sum/n << endl; 
	return 0; 
}
