#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set> 
#include <map> 
#include <vector> 
using namespace std; 
char grid[1001][1001]; 
typedef pair<int,int> P; 
set<P> walls; 
bool destroyed[1001][1001]; 
map<int,int> R,C;  
int main(){
	int n,m; 
	cin >> n >> m; 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> grid[i][j]; 
			if (grid[i][j] == '*'){
				walls.insert(P(i,j)); 
				R[i]++; 
				C[j]++; 
			}
		}
	}
	if (walls.empty()){
		cout << "YES\n1 1\n"; 
		return 0; 
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int cnt = R[i]+C[j];  
			if (walls.count(P(i,j))){
				cnt--; 
			}
			if (cnt == walls.size()){
				cout << "YES" << "\n"; 
				cout << i << " " << j << "\n";  
				return 0; 
			}
		}
	}
	// we failed to complete the task 
	cout << "NO" << "\n"; 
	return 0; 
}
