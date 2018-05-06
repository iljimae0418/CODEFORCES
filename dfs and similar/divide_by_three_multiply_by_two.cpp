#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <set> 
#include <map> 
using namespace std; 
typedef long long ll;  
ll a[105]; 
map< ll,vector<ll> > g;  
int dfs(ll cur,vector<ll> &path){
	path.push_back(cur); 
	if (g[cur].empty()) return 1; 
	int ret = 0; 
	for (int i = 0; i < g[cur].size(); i++){
		ll next = g[cur][i]; 
		ret = dfs(next,path)+1; // there is at most one edge per node 
	}
	return ret;  
}
int main(){
	int n; 
	cin >> n; 
	set<ll> exist;  
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		exist.insert(a[i]);  
	}
	for (int i = 1; i <= n; i++){
		if (exist.count(a[i]*2LL)){
			g[a[i]].push_back(a[i]*2LL);  
		}
		if (a[i]%3LL == 0 && exist.count(a[i]/3LL)){
			g[a[i]].push_back(a[i]/3LL);  
		}
	}
	// O(n^2) algorithm 
	for (int i = 1; i <= n; i++){
		vector<ll> path; 
		int ans = dfs(a[i],path);  
		if (ans == n){
			for (int j = 0; j < path.size(); j++){
				cout << path[j] << " "; 
			}
			cout << endl; 
			break; 
		}
	}
	return 0;  
}
