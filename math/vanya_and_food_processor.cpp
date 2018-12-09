#include <iostream>
#include <vector> 
using namespace std; 
typedef long long ll;  
ll a[100005];  
int main(){
	ll n,h,k; 
	cin >> n >> h >> k;  
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	ll in = 0; 
	int idx = 0; 
	ll cnt = 0; 
	while (idx < n && in+a[idx] <= h){
		in += a[idx];  
		idx++; 
	}
	// time ticks when the processor chomps the potato 
	while (in > 0){
		/*if (in-k < 0){
			in = 0; 
		}else{
			in -= k; 
		}
		cnt++;  */
		// quick chomp 
		ll x = (a[idx]+in-h+k-1LL)/k; 
		in -= k*x;  
		cnt += x;  
		if (in < 0) in = 0; // adjust 
		// add in potatoes again
		while (idx < n && in+a[idx] <= h){
			in += a[idx]; 
			idx++; 
		}
		if (idx == n) break; 
	}
	/*while (in > 0){
		in -= k; 
		cnt++; 
	}*/ 
	// additional quick chomp 
	if (in > 0){
		cnt += (in+k-1LL)/k; 
	}
	cout << cnt << "\n"; 
	return 0;  
}
