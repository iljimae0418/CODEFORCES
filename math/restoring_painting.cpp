#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
#include <cmath> 
#include <cstring> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
typedef long long ll; 
ll n,a,b,c,d; 
bool inRange(ll k){
	return (k >= 1 && k <= n);  
}
int main(int argc,char **argv){
	cin >> n >> a >> b >> c >> d;  
	ll cnt = 0;  
	for (ll x2 = 1LL; x2 <= n; x2++){
		ll x3 = x2+b-c; 
		ll x4 = x2+a-d; 
		ll x5 = x4+b-c;  
		if (inRange(x3) && inRange(x4) && inRange(x5) &&
			x2+a+b == x5+c+d && x3+a+c == x4+b+d && 
			x3+a == x5+d){
			cnt++; 
		}
	}
	cout << cnt*n << "\n"; 
	return 0; 
} 
