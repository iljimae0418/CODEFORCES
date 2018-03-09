#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <map> 
#include <numeric> 
using namespace std; 
typedef long long ll;  
vector<ll> v; 
int main(){
	int n; 
	cin >> n;
	ll sum = 0;   
	for (int i = 0; i < n; i++){
		ll x; 
		cin >> x; 
		sum += x;  
		v.push_back(x); 
	}
	sort(v.begin(),v.end(),greater<ll>()); 
	ll ans = 0, temp = 0;  
	while (v.size() >= 1){
		ans += sum+temp;  
		sum -= v[v.size()-1];  
		temp = v[v.size()-1]; 
		v.pop_back(); 
	}
	cout << ans << endl; 
	return 0; 
}
