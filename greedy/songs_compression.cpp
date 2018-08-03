#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std; 
typedef long long ll; 
typedef pair<ll,ll> P;   
bool cmp(P p1,P p2){
	return abs(p1.first-p1.second) > abs(p2.first-p2.second);  
}
int main(){
	ll n,m; 
	cin >> n >> m; 
	vector<P> v; 
	ll sum = 0,smallest = 0;  
	for (int i = 0; i < n; i++){
		ll a,b; 
		cin >> a >> b; 
		v.push_back(P(a,b));
		sum += a;   
		smallest += b;   
	}
	sort(v.begin(),v.end(),cmp); 
	if (sum <= m){ // no modifications needed 
		cout << 0 << endl; 
	}else if (smallest > m){ // no solution 
		cout << -1 << endl; 
	}else{
		int cnt = 0; 
		for (int i = 0; i < n; i++){
			sum -= v[i].first-v[i].second; 
			cnt++; 
			if (sum <= m) break; 
		}
		cout << cnt << endl; 
	}
	return 0; 
}
