#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[10]; 
int main(){
	int v; 
	cin >> v;  
	int minval = 2e9; 
	for (int i = 1; i <= 9; i++){
		cin >> a[i]; 
		minval = min(minval,a[i]); 
	}
	if (v < minval){
		cout << -1 << endl; 
	}else{
		// it is most beneficial to create longest string 
		int maxLen = v/minval; 
		while (maxLen){
			for (int i = 9; i >= 1; i--){
				if (a[i] <= v && (v-a[i])/minval == maxLen-1){
					cout << i; 
					v -= a[i]; 
					maxLen--; 
					break; 
				}
			}
		}
		cout << endl; 
	}
	return 0; 
}
