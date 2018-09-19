#include <iostream> 
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	typedef long long ll; 
	ll n,k; 
	cin >> n >> k;  
	ll m = (2LL*n+1)/2;  
	ll ans = (k+m-1)/m; 
	cout << ans << endl; 
	return 0; 
}
