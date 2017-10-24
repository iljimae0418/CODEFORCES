// k rounding: min positive integer x, such that x ends with 
// k or more zeros in base 10 and is divisible by n. 
#include <iostream>
#include <cstdlib>
#include <map> 
using namespace std; 
typedef long long ll; 
ll gcd(ll a,ll b){
	if (b == 0) return a; 
	return gcd(b,a%b);  
}
ll lcm(ll a,ll b){
	return (a*(b/gcd(a,b))); 
}
int main(){
	ll n,k; 
	cin >> n >> k;  
	ll cmp = 1; 
	for (int i = 0; i < k; i++){
		cmp *= 10; 
	}
	cout << lcm(n,cmp) << endl; 
	return 0;  
}
