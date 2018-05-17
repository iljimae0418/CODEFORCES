#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std; 
typedef long long ll;  
int main(){
	ll n,m,k;  
	cin >> n >> m >> k; 
	if (k <= n-1){
		cout << 1+k << " " << 1 << endl; 
	}else if (k > n-1 && k <= (n-1)+(m-1)){
		cout << n << " " << 1+k-(n-1) << endl; 
	}else if (k > (n-1)+(m-1)){
		ll x = (n-1)+(m-1);  
		k -= x; 
		ll complete = k/(m-1), r = k%(m-1);  
		ll fx = 0, fy = 0; 
		if (complete%2 == 0){
			fx = n-complete; 
			fy = m; 
			if (r >= 1){
				fx--; 
				fy -= (r-1); 
			}
		}else if (complete%2 == 1){
			fx = n-complete; 
			fy = 2LL;  
			if (r >= 1){
				fx--; 
				fy += (r-1);  
			}
		}
		cout << fx << " " << fy << endl; 
	}
	return 0;  
}
