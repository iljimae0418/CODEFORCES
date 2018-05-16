#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll; 
typedef pair<ll,ll> P; 
P a[100005]; 
bool cmp(P &p1,P &p2){
	return p1.second < p2.second; 
}
int main(){
	ll n,r,avg; 
	cin >> n >> r >> avg; 
	ll sum = 0, ans = 0; 
	for (int i = 0; i < n; i++){
		cin >> a[i].first >> a[i].second; 
		sum += a[i].first;  
	}
	sort(a,a+n,cmp); 
	for (int i = 0; i < n; i++){
		if (sum >= n*avg) break; 
		ans += a[i].second * min(r-a[i].first,n*avg-sum);  
		sum += min(r-a[i].first,n*avg-sum);  
	}
	cout << ans << endl; 
	return 0;  
}
