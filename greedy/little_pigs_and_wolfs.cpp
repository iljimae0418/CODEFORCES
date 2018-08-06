#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
char grid[11][11];  
int n,m;  
int main(){
	cin >> n >> m;  
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> grid[i][j]; 
		}
	}
	int cnt = 0; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] == 'W'){
				if (i+1 < n && grid[i+1][j] == 'P') cnt++; 
				else if (i-1 >= 0 && grid[i-1][j] == 'P') cnt++; 
				else if (j+1 < m && grid[i][j+1] == 'P') cnt++; 
				else if (j-1 >= 0 && grid[i][j-1] == 'P') cnt++;  
			}
		}
	}
	cout << cnt << endl; 
	return 0;  
}	
