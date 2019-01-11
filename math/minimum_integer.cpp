#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	typedef long long ll; 
	int q; 
	cin >> q; 
	while (q--){
		ll l,r,d; 
		cin >> l >> r >> d; 
		if (l > d){
			cout << d << endl; 
		}else{
			ll k = r/d; 
			cout << d * (k+1LL) << endl; 
		}
	}
	return 0;  
}
