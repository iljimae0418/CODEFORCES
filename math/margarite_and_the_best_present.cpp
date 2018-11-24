#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cmath>
using namespace std; 
typedef long long ll; 
int main(){
	int q; 
	cin >> q; 
	while (q--){
		ll l,r;  
		cin >> l >> r;  
		ll d = r-l+1;  
		if (d%2 == 0){
			if (l%2 == 1){
				cout << d/2 << endl; 
			}else if (l%2 == 0){
				cout << -d/2 << endl; 
			}
		}else if (d%2 == 1){
			ll a_r = (r%2 == 0 ? r : -r);  
			if (l%2 == 1){
				cout << a_r + (d-1)/2 << endl; 
			}else if (l%2 == 0){
				cout << a_r - (d-1)/2 << endl; 
			}
		}
	}
	return 0; 
}
