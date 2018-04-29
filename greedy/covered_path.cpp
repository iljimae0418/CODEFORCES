// find maximum possible length of path section 
#include <iostream>
#include <cstdlib> 
#include <cstring> 
#include <algorithm>
#include <numeric> 
using namespace std; 
int t,d,v1,v2; 
int a[101];   
int main(){
	cin >> v1 >> v2; 
	cin >> t >> d; 
	a[1] = v1, a[t] = v2; 
	// let's employ a greedy method  
	for (int i = 2; i <= t-1; i++){
		a[i] = a[i-1]+d; 
	}
	// going backwards 
	for (int i = t; i >= 2; i--){
		if (abs(a[i]-a[i-1]) > d){
			int diff = abs(a[i]-a[i-1])-d; 
			if (a[i-1] > a[i]) a[i-1] -= diff; 
			else a[i-1] += diff; 
		}
	}
	int ans = accumulate(a+1,a+t+1,0);
	cout << ans << endl; 
	return 0; 
}
