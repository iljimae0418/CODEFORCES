#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
char grid[505][505]; 
int hor[505][505],ver[505][505]; 
// dp[i][j] = number of good cells for a grid with lower right corner (i,j) 
// and upper left (1,1).  
int h,w,q; 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	cin >> h >> w; 
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			cin >> grid[i][j];  
		}
	}
	// fill in hor and ver 
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			hor[i][j] = hor[i-1][j]+hor[i][j-1]-hor[i-1][j-1]; 
			if (grid[i][j] == '.' && grid[i][j+1] == '.') hor[i][j]++;  
			ver[i][j] = ver[i-1][j]+ver[i][j-1]-ver[i-1][j-1]; 
			if (grid[i][j] == '.' && grid[i+1][j] == '.') ver[i][j]++;  
		}
	}
	int q; 
	cin >> q;  
	while (q--){
		int r1,c1,r2,c2; 
		cin >> r1 >> c1 >> r2 >> c2; 
		int ans = 0;  
		ans += hor[r2][c2-1]-hor[r1-1][c2-1]-hor[r2][c1-1]+hor[r1-1][c1-1]; 
		ans += ver[r2-1][c2]-ver[r1-1][c2]-ver[r2-1][c1-1]+ver[r1-1][c1-1];  
		cout << ans << endl; 
	} 
	return 0; 
}
