#include <iostream>
#include <cstdlib>
#include <climits> 
#include <algorithm>
#include <vector>
using namespace std; 
typedef long long ll;  
ll c[35]; 
ll dp[35]; // dp[i] = minimum number of roubles to get 2^(i-1) liters 
ll power(int x){ // compute 2^x 
	if (x == 0) return 1LL; 
	if (x == 1) return 2LL; 
	return power(x/2)*power(x/2)*power(x%2); 
}
int main(){
	int n; 
	ll L; 
	cin >> n >> L; 
	for (int i = 0; i < n; i++){
		cin >> c[i]; 
	}
	for (int i = 0; i < n-1; i++){
		c[i+1] = min(c[i+1],2*c[i]);  
	}
	ll ans = 4e18;  
	ll sum = 0; 
	for (int i = n-1; i >= 0; i--){
		int need = L/(1<<i); 
		cout << need << endl; 
		sum += need * c[i]; 
		L -= need<<i; 
		ans = min(ans,sum+(L>0)*c[i]);  
	}
	cout << ans << endl; 
	return 0; 
}
