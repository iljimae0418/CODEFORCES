#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll;  
int main(){
	ll n; 
	cin >> n; 
	ll ans = 0;  
	if (n%2 == 1) cout << 0 << endl; 
	else{
		ll k = n/2; 
		if (k%2 == 1){
			cout << k/2 << endl; 
		}else{
			cout << k/2 - 1 << endl; 
		}
	}
	return 0; 
}
