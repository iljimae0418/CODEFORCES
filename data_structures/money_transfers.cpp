#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll;  
ll n;  
ll a[100005]; 
ll psum[100005];  
int main(){
	IOFAST(); 
	cin >> n; 
	ll ans = 222222LL;  
	map<ll,ll> freq;  
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		psum[i] = psum[i-1]+a[i];  
		freq[psum[i]]++;  
		ans = min(ans,n-freq[psum[i]]);  
	}
	cout << ans << endl; 
	return 0; 
}
