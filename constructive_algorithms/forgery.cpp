// collect all valid center stamp points from grid 
// try applying this to cpy 
// check if cpy and grid are equal 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
typedef pair<int,int> P; 
int n,m; 
char grid[1005][1005]; 
char cpy[1005][1005];  
bool inRange(int x,int y){
	return (x >= 0 && x < n && y >= 0 && y < m);  
}
bool chk(int i,int j){
	// check if all the 8 neighbours are '#'
	for (int k1 = -1; k1 <= 1; k1++){
		for (int k2 = -1; k2 <= 1; k2++){
			if (k1 == 0 && k2 == 0) continue;  
			int ni = i+k1;  
			int nj = j+k2; 
			if (!inRange(ni,nj)) return false;  
 			if (inRange(ni,nj) && grid[ni][nj] == '.') return false; 
		}
	}
	return true; 
}
int main(){
	cin >> n >> m;
	int cnt_dots = 0;  
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> grid[i][j];
			cpy[i][j] = '.'; 
		}
	}
	vector<P> points;  
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (chk(i,j)){
				points.push_back(P(i,j));  
			}
		}
	}
	for (int i = 0; i < points.size(); i++){
		int x = points[i].first, y = points[i].second; 
		for (int j = -1; j <= 1; j++){
			for (int k = -1; k <= 1; k++){
				if (j == 0 && k == 0) continue; 
				int nx = x+j; 
				int ny = y+k;  
				cpy[nx][ny] = '#';  
			}
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] != cpy[i][j]){
				cout << "NO" << endl; 
				return 0; 
			}
		}
	}
	cout << "YES" << endl; 
	return 0; 
}
