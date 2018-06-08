#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
typedef long long ll; 
ll power(int x){
	if (x == 0) return 1LL;  
	if (x == 1) return 2LL; 
	return power(x/2)*power(x/2)*power(x%2); 
}
int main(){
	int n; 
	cin >> n; 
	ll ans = power(n+1)-2;  
	cout << ans << endl; 
	return 0;  
}
