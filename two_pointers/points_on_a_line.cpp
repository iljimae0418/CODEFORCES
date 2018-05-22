#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll; 
ll x[100005];  
int main(){
	IOFAST(); 
	ll n,d;
	cin >> n >> d;  
	for (ll i = 0; i < n; i++){
		cin >> x[i]; 
	}
	ll ans = 0;  
	ll l = 0, r = 0;  
	while (l < n){
		while (r < n && x[r]-x[l] <= d){
			ans += (r-l)*(r-l-1)/2LL;
			r++;  
		}
		l++;  
	}
	cout << ans << endl; 
	return 0;  
}
