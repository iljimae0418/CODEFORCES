#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;  
char grid[105][105]; 
int cnt[105];   
long long mod = 1e9+7;  
int main(){
	int n,m; 
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> grid[i][j];  
		}
	}
	for (int i = 0; i < m; i++){
		set<char> distinct;  
		for (int j = 0; j < n; j++){
			distinct.insert(grid[j][i]);  
		}
		cnt[i] = distinct.size();  
	}
	long long ans = 1;  
	for (int i = 0; i < m; i++){
		ans *= cnt[i];  
		ans %= mod;  
	}
	cout << ans << endl; 
	return 0;  
}
