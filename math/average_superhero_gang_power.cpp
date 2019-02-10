#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
const int MAXN = 100005;  
typedef long long ll;  
ll psum[MAXN]; 
ll a[MAXN]; 
int main(int argc,char **argv){
	ll n,k,m;  
	cin >> n >> k >> m; 
	for (ll i = 1; i <= n; i++){
		cin >> a[i];   
	}
	sort(a+1,a+n+1); 
	for (ll i = 1; i <= n; i++){
		psum[i] = psum[i-1]+a[i];  
	}
	double ans = 0.0;  
	for (ll i = 0; i <= min(n,m); i++){
		if (i == n) continue;  // no point in deleting all the elements 
		double cur = (double)(psum[n]-psum[i]+min(k*(n-i),m-i))/(n-i);  
		ans = max(ans,cur);  
	}
	cout.setf(ios::showpoint); 
	cout.setf(ios::fixed); 
	cout.precision(20); 
	cout << ans << endl; 
	return 0; 
}
