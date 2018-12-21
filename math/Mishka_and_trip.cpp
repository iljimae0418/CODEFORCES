#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;  
typedef long long ll; 
ll c[100005]; 
bool capital[100005]; 
vector<ll> capital_list;  
int main(int argc,char **argv){
	ll n,k,sum = 0,x;
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> c[i]; 
		sum += c[i]; 
	}
	for (int i = 1; i <= k; i++){
		cin >> x; 
		capital[x] = true; 
		capital_list.push_back(x);  
	}
	ll ans = 0; 
	for (int i = 1; i <= n; i++){	
		if (capital[i] || (i+1 <= n && capital[i+1]) || 
			(i == n && capital[1])) continue; 
		if (i == n) ans += c[i]*c[1];  
		else ans += c[i]*c[i+1];  	
	}
	ll cumulative = 0; 
	for (int i = 0; i < capital_list.size(); i++){
		x = capital_list[i]; 
		cumulative += c[x]; 
		ans += c[x]*(sum-cumulative);  
	}
	cout << ans << "\n"; 
	return 0; 
}
