#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector>
#include <cstring> 
#include <set> 
using namespace std; 
int a[1001],b[1001]; 
int n; 
double m; 
const double INF = 1e10; 
bool ok(double x){
	double w = x+m;  
	for (int i = 0; i < n; i++){
		int j = (i+1)%n; 
		w -= w/a[i]; 
		w -= w/b[j]; 
	}
	return w >= m; 
}
int main(){
	cin >> n >> m;  
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	for (int i = 0; i < n; i++){
		cin >> b[i]; 
	}	
	double l = 0, r = INF;
	for (int i = 0; i < 100; i++){
		double mid = (l+r)/2.0;  
		if (ok(mid)) r = mid; 
		else l = mid; 
	}
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(10); 
	double ans = (l+r)/2.0; 
	if (ans == INF) cout << -1 << endl; 
	else cout << ans << endl; 
	return 0; 
}	
