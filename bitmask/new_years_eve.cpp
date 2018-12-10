#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	typedef long long ll; 
	ll n,k;  
	cin >> n >> k; 
	if (k == 1){
		cout << n << "\n"; 
	}else{
		ll res = 1LL; 
		while (res <= n){
			res <<= 1LL;  
		}
		cout << res-1 << endl; 
	}
	return 0;  
}
