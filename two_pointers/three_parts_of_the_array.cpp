#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll;  
ll a[200005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	int l = 1, r = n; 
	int last_l = -1, last_r = -1; 
	ll sum_l = a[l], sum_r = a[r]; 
	while (l < r){
		if (sum_l == sum_r){
			last_l = l, last_r = r; 
			l++,r--; 
			sum_l += a[l]; 
			sum_r += a[r]; 
		}else if (sum_l < sum_r){
			l++;  
			sum_l += a[l]; 
		}else if (sum_l > sum_r){
			r--; 
			sum_r += a[r]; 
		}
	}
	if (last_l == -1 && last_r == -1){
		cout << 0 << endl; 
	}else{
		ll ans = 0; 
		for (int i = 1; i <= last_l; i++){
			ans += a[i]; 
		}
		cout << ans << endl; 
	}
	return 0;  
}
