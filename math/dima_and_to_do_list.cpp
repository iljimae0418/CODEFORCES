#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[100005]; 
int main(){
	int n,k; 
	cin >> n >> k;  
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	int minPower = (int)2e9, ans = -1;  
	for (int i = 1; i <= k; i++){
		int power = 0, pos = i; 
		for (int j = i; j <= n; j += k){
			power += a[j];  
		}
		if (minPower > power){
			minPower = power; 
			ans = i;  
		}
	}
	cout << ans << endl; 
	return 0; 
}
