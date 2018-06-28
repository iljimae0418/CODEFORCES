#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
typedef long long ll; 
bool ok(ll x,ll n){
	ll vasya = 0; // amount eaten by vasya
	ll temp = n;   
	while (temp){
		vasya += min(x,temp); 
		temp -= min(x,temp); 
		temp -= temp/10; // reduce by ceiling of 10% 
	}
	return 2LL*vasya >= n; 
} 
int main(){
	ll n;  
	cin >> n; 
	ll l = 1LL, r = n;  
	while (l <= r){
		ll mid = (l+r)>>1LL;  
		if (ok(mid,n)){
			r = mid-1; 
		}else{
			l = mid+1; 
		}
	}
	cout << l << endl; 
	return 0; 
}
