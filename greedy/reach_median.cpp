#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath> 
using namespace std;  
typedef long long ll;  
ll a[200005];  
int main(){
	ll n,s; 
	cin >> n >> s; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	sort(a,a+n);  
	ll mid = a[n/2],ans = 0; 
	if (mid == s){
		cout << 0 << endl;
		return 0;  
	}else if (s > mid){
		for (int i = n/2; i < n; i++){
			if (a[i] < s){ 
				ans += abs(a[i]-s);  
			}
		}
	}else if (s < mid){
		for (int i = n/2; i >= 0; i--){
			if (a[i] > s){
				ans += abs(a[i]-s); 
			}
		}
	}
	cout << ans << endl;  
	return 0;  
}
