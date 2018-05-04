#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[100005]; 
int not_sleep[100005]; 
int psum[100005]; 
int main(){
	int n,k; 
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++){
		cin >> not_sleep[i];  
	}
	for (int i = 1; i <= n; i++){
		if (!not_sleep[i]) psum[i] = a[i];  
	}
	for (int i = 1; i <= n; i++){
		psum[i] += psum[i-1];  
	}
	int maxval = 0; 
	for (int i = 1; i <= n; i++){
		maxval = max(maxval,psum[i+k-1]-psum[i-1]); 
	}
	int ans = 0; 
	for (int i = 1; i <= n; i++){
		if (not_sleep[i]) ans += a[i]; 
	}
	ans += maxval; 
	cout << ans << endl;
	return 0; 
}
