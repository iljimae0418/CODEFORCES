#include <iostream>
#include <cstdlib>
#include <vector> 
#include <map>
#include <cstring> 
#include <algorithm>
using namespace std; 
typedef long long ll;  
typedef pair<ll,ll> P; 
ll a[200005]; 
ll b[200005];  
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);  
	int n,m;  
	cin >> n >> m;  
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	for (int i = 0; i < m; i++){
		cin >> b[i]; 
	}
	// get ranges 
	ll start = 1, end = 0; 
	vector<P> ranges; 
	for (int i = 0; i < n; i++){
		end = start+a[i]-1;  
		ranges.push_back(P(start,end)); 
		start = end+1;  
	}
	// loop over ranges 
	for (int i = 0; i < m; i++){
		ll key = b[i]; 
		int l = 0, r = n-1; 
		while (l <= r){
			int mid = (l+r)>>1; 
			ll start = ranges[mid].first; 
			ll end = ranges[mid].second; 
			if (key >= start && key <= end){
				// we found the answer 
				ll f = (ll)mid+1; 
				ll d = key-start+1;  
				cout << f << " " << d << endl; 
				break; 
			}else if (key < start){
				r = mid-1; 
			}else if (key > end){
				l = mid+1;  
			}
		}
	}
	return 0; 
}
