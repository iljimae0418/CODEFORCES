#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath> 
using namespace std; 
double a[101];  
const double PI = 3.14159265358979323846;  
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n); 
	double ans = 0; 
	int tick = 1; 
	for (int i = n-1; i >= 0; i--){
		if (tick){
			tick = 0; 
			ans += a[i]*a[i];  
		}else{
			tick = 1; 
			ans -= a[i]*a[i]; 
		}
	}
	ans *= PI; 
	cout.setf(ios::showpoint); 
	cout.setf(ios::fixed); 
	cout.precision(10);
	cout << ans << endl; 
	return 0; 
}
