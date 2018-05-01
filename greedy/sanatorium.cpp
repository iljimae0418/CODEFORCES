#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	typedef long long ll; 
	ll a,b,c,ans = 2e18;  
	cin >> a >> b >> c;  
	ll n = max(a,max(b,c)); 
	ans = min(ans,n-a+n-b+n-c);  
	if (n == a){
		ans = min(ans,max(0LL,n-b-1)+max(0LL,n-c-1));  
	}
	if (n == b){
		ans = min(ans,max(0LL,n-a-1)+max(0LL,n-c-1));  
	}
	if (n == c){
		ans = min(ans,max(0LL,n-b-1)+max(0LL,n-a-1));  
	}
	cout << ans << endl;
	return 0;  
}
