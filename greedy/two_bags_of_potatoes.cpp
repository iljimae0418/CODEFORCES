#include <iostream>
#include <cstdio>
using namespace std; 
int main(){
	typedef long long ll;  
	ll y,k,n; 
	cin >> y >> k >> n; 
	bool found = false;  
	for (ll m = 1; m <= n/k; m++){
		if (k*m-y >= 1){
			found = true; 
			cout << k*m-y << " ";  
		}
	}
	if (!found) cout << -1;  
	cout << endl; 
	return 0; 
}
