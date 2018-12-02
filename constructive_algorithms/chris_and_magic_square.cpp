#include <iostream>
#include <cstdlib>
#include <set> 
#include <algorithm>
using namespace std; 
typedef long long ll;  
ll a[505][505]; 
ll sum = 0, target = 0;  
int main(){
	int n,r,c; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j]; 
			if (a[i][j] == 0){
				r = i; 
				c = j;  
			}
		}
	}
	// base case: 
	if (n == 1){
		cout << 1 << endl; 
		return 0;  
	}
	// first get sum 
	for (int i = 0; i < n; i++){
		if (i == r){
			continue; 
		}
		for (int j = 0; j < n; j++){
			sum += a[i][j];  
		}
		if (sum != 0) break; 
	}
	// get target 
	for (int i = 0; i < n; i++){
		target += a[r][i];  
	}
	ll ans = sum-target; 
	if (ans <= 0){
		cout << -1 << endl; 
		return 0; 
	}
	// check if our answer is valid 
	a[r][c] = ans; 
	// check rows 
	for (int i = 0; i < n; i++){
		ll chk = 0; 
		for (int j = 0; j < n; j++){
			chk += a[i][j];  
		}
		if (chk != sum){
			cout << -1 << endl; 
			return 0; 
		}
	}
	// cols 
	for (int i = 0; i < n; i++){
		ll chk = 0; 
		for (int j = 0; j < n; j++){
			chk += a[j][i];  
		}
		if (chk != sum){
			cout << -1 << endl; 
			return 0; 
		}
	}
	// check d1 
	ll chk = 0; 
	for (int i = 0; i < n; i++){	
		chk += a[i][i];  
	}
	if (chk != sum){
		cout << -1 << endl; 
		return 0;  
	}
	// check d2 
	chk = 0; 
	for (int i = 0; i < n; i++){
		chk += a[i][n-1-i];  
	}
	if (chk != sum){
		cout << -1 << endl; 
		return 0; 
	}
	cout << ans << endl; 
	return 0; 
}
