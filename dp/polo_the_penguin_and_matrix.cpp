#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;  
int grid[101][101];
vector<int> k;  
int main(){
	int n,m,d; 
	cin >> n >> m >> d;  
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> grid[i][j];  
			k.push_back(grid[i][j]);  
		}
	}
	sort(k.begin(),k.end());  
	// check if it's solvable 
	int cmp = grid[1][1]%d; 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (cmp != grid[i][j]%d){
				cout << -1 << endl; 
				return 0; 
			}
		}
	}
	int median = k[k.size()/2];
	int ans = 0; 
	for (int i = 0; i < k.size(); i++){
		ans += abs(median-k[i]); 
	}
	ans /= d; 
	cout << ans << endl; 
	return 0; 
} 
