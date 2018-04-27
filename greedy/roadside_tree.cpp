#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int h[100005];  
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> h[i]; 
	}
	int ans = 0; 
	for (int i = 1; i <= n; i++){
		if (i == 1){
			// we need to climb up the tree 
			ans += h[i];  
			ans += 1; // eat the nut 
		}
		if (i < n){
			if (h[i] <= h[i+1]){
				// jump over to the tree, then eat the nut 
				// at the top of tree 
				ans += 1; 
				ans += h[i+1]-h[i]+1;  
			}else if (h[i] > h[i+1]){
				// climb down the current tree that matches the height 
				// of the neighboring tree 
				// then jump over the tree  
				ans += h[i]-h[i+1]+1; 
				ans += 1;  
			}
		}
	}
	cout << ans << endl; 
	return 0; 
}
