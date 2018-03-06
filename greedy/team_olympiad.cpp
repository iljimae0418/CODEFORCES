#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std;  
map<int,vector<int> > mp; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		int t; 
		cin >> t; 
		mp[t].push_back(i);  
	}
	int ans = min(mp[1].size(),min(mp[2].size(),mp[3].size()));  
	cout << ans << endl; 
	for (int i = 0; i < ans; i++){
		cout << mp[1][i] << " " << mp[2][i] << " " << mp[3][i] << endl; 
	}
	return 0;  
}
