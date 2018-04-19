#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n,k; 
	cin >> n >> k; 
	string s; 
	cin >> s; 
	int l = 0, r = 0, ans = -1000, d = 0; 
	// run two pointer two times 
	// 1. all subsegments should be composed of 'a' 
	while (l < n){
		while (r < n){
			if (s[r] == 'a') r++; 
			else{
				if (d+1 > k) break; 
				r++; 
				d++;  
			}
		}
		ans = max(ans,r-l); 
		if (s[l] == 'b') d--; 
		l++;  
	}
	// 2. all subsegments should be composed of 'b' 
	l = 0, r = 0, d = 0; 
	while (l < n){
		while (r < n){
			if (s[r] == 'b') r++;  
			else{
				if (d+1 > k) break; 
				r++; 
				d++; 
			}
		}
		ans = max(ans,r-l);  
		if (s[l] == 'a') d--; 
		l++;  
	}
	cout << ans << endl; 
	return 0; 
}
