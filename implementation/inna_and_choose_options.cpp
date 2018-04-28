#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
typedef pair<int,int> P;  
int main(){
	int t; 
	cin >> t; 
	while (t--){
		string s; 
		cin >> s; 
		// brute force 
		P a[] = {P(1,12),P(2,6),P(3,4),P(4,3),P(6,2),P(12,1)}; 
		vector<P> ans;  
		for (int i = 0; i < 6; i++){
			int r = a[i].first, c = a[i].second;
			char grid[r+1][c+1]; 
			int idx = 0;   
			for (int j = 0; j < r; j++){
				for (int k = 0; k < c; k++){
					grid[j][k] = s[idx++];  
				}
			}
			for (int j = 0; j < c; j++){
				bool win = true; 
				for (int k = 0; k < r; k++){
					if (grid[k][j] == 'O'){
						win = false;  
						break; 
					} 
				}
				if (win){
					ans.push_back(a[i]);
					break; 
				} 
			}
		}
		cout << ans.size() << " ";  
		for (int i = 0; i < ans.size(); i++){
			cout << ans[i].first << "x" << ans[i].second << " ";  
		}
		cout << endl; 
	}
	return 0;  
}
