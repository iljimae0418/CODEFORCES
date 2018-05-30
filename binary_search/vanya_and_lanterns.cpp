#include <iostream>
#include <algorithm>
#include <set> 
using namespace std; 
double a[1005]; 
int n;
double l;    
bool ok(double d){
	for (int i = 1; i < n; i++){
		if (a[i-1]+d < a[i]-d) return false;  
	}
	return true;    
}
int main(){
	cin >> n >> l; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	sort(a,a+n); 
	double L = max(a[0],l-a[n-1]), R = l; 
	for (int i = 0; i < 100; i++){
		double mid = (L+R)/2.0;  
		if (ok(mid)) R = mid; 
		else L = mid;  
	}
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(10); 
	cout << (L+R)/2.0 << endl; 
	return 0; 
}
