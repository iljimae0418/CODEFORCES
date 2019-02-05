#include <iostream>
#include <algorithm>
using namespace std; 
char grid[505][505]; 
bool chk(int n,int i,int j){
	if (grid[i][j] != 'X') return false;  
	if (!(i-1 >= 0 && i-1 < n && j-1 >= 0 && j-1 < n)) return false;  
	if (!(i-1 >= 0 && i-1 < n && j+1 >= 0 && j+1 < n)) return false; 
	if (!(i+1 >= 0 && i+1 < n && j-1 >= 0 && j+1 < n)) return false; 
	if (!(i+1 >= 0 && i+1 < n && j+1 >= 0 && j+1 < n)) return false; 
	if (grid[i-1][j-1] != 'X') return false;  
	if (grid[i-1][j+1] != 'X') return false; 
	if (grid[i+1][j-1] != 'X') return false; 
	if (grid[i+1][j+1] != 'X') return false; 
	return true;  
}
int main(){
	int n,cnt = 0; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> grid[i][j]; 
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (chk(n,i,j)) cnt++; 
		}
	}
	cout << cnt << endl; 
	return 0; 
}
