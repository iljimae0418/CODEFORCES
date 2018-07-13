#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int grid[2001][2001];
int cnt[2001];  
int main(){
	int n,m; 
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			char c; 
			cin >> c; 
			grid[i][j] = c-'0'; 
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] == 1){
				cnt[j]++; 
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] == 1){
				cnt[j]--;  
			}
		}
		bool possible = true; 
		for (int j = 0; j < m; j++){
			if (cnt[j] == 0){
				possible = false; 
				break; 
			}
		}
		if (possible){
			cout << "YES" << endl; 
			return 0; 
 		}
 		// if not possible, backtrack 
 		for (int j = 0; j < m; j++){
 			if (grid[i][j] == 1){
 				cnt[j]++;  
 			}
 		}
	}
	// if we reached this step, 
	// it means that we need all the n switches to 
	// turn all the lamps on. 
	cout << "NO" << endl; 
	return 0; 
}
