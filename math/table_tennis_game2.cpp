#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll;  
bool pass(ll k,ll a,ll b){
	if (a >= k && b >= k) return true;  
	if (a >= k && b < k && a%k == 0) return true;  
	if (a < k && b >= k && b%k == 0) return true;  
	return false; 
}
int main(){
	ll k,a,b; 
	cin >> k >> a >> b;  
	if (pass(k,a,b)){
		cout << a/k + b/k << endl; 
	}else{
		cout << -1 << endl; 
	}
	return 0; 
}
