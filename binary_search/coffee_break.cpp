#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
typedef long long ll; 
typedef pair<ll,ll> P; 
ll a[200005],ans[200005]; 
set<P> st;  
int main(){
	IOFAST(); 
	ll n,m,d; 
	cin >> n >> m >> d; 
	for (ll i = 1; i <= n; i++){
		cin >> a[i]; 
		st.insert(P(a[i],i)); // sorted in increasing order of a[i].
	}
	int cnt = 0; 
	while (!st.empty()){
		cnt++; 
		ll pos = st.begin()->second;  
		st.erase(st.begin()); 
		ans[pos] = cnt; 
		while (1){
			set<P>::iterator it = st.lower_bound(P(a[pos]+d+1,0));  
			if (it == st.end()) break; 
			pos = it->second; 
			st.erase(it); 
			ans[pos] = cnt; 
		}
	}
	cout << cnt << endl; 
	for (ll i = 1; i <= n; i++){
		cout << ans[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
