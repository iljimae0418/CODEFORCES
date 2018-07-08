#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int a[5005]; 
int psum[5005]; 
int n,k;  
int main(){
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		psum[i] = psum[i-1]+a[i]; 
	}
	double ans = -1.0;  
	for (int i = 1; i+k-1 <= n; i++){
		for (int len = k; len <= n-i+1; len++){
			int val = psum[i+len-1]-psum[i-1];  
			int cnt = len;  
			double avg = (double)val/(double)cnt; 
			ans = max(ans,avg);  
		}
	}
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(14); 
	cout << ans << endl; 
	return 0; 
}
