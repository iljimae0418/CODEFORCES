#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll;  
ll isPerfectCube(ll x){
	ll l = 1LL, r = min(x,1000000LL);  
	while (l <= r){
		ll mid = (l+r)>>1LL; 
		if (mid*mid*mid == x) return mid; 
		else if (mid*mid*mid < x) l = mid+1; 
		else r = mid-1; 
	}
	return -1;  
}
int main(){
	int n; 
	scanf("%d",&n);  
	while (n--){
		ll a,b; 
		scanf("%lld %lld",&a,&b);  
		ll c = a*b,x;  
		if ((x = isPerfectCube(c)) != -1){
			if (a%x == 0 && b%x == 0) puts("Yes");   
			else puts("No");   
		}else{
			puts("No");   
		}
	}
	return 0; 
}
