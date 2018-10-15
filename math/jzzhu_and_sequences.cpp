#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll; 
const ll mod = (ll)1e9+7;  
int main(){
	ll x,y,n,ans = 0; 
	cin >> x >> y >> n;  
	if (n%6 == 1){
		ans = x; 
	}else if (n%6 == 2){
		ans = y; 
	}else if (n%6 == 3){
		ans = y-x;  
	}else if (n%6 == 4){
		ans = -x; 
	}else if (n%6 == 5){
		ans = -y; 
	}else if (n%6 == 0){
		ans = x-y;  
	}
	ans = (ans + mod*((labs(ans)+mod-1LL)/mod))%mod;  
	cout << ans << endl;  
	return 0; 
}
