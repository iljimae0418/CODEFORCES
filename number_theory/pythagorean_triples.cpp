#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int main(){
	typedef long long ll; 
	ll n; 
	cin >> n; 
	if (n == 1 || n == 2){
		cout << -1 << endl; 
	}else if (n%2 == 0){
		ll m = n*n/4 - 1;  
		ll k = n*n/4 + 1;  
		cout << m << " " << k << endl; 
	}else if (n%2 == 1){
		ll m = (n*n-1)/2;  
		ll k = (n*n+1)/2; 
		cout << m << " " << k << endl; 
	}
	return 0; 
}
