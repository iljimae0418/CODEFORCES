#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <cstring> 
using namespace std; 
vector<int> tree[100005]; 
int cat[100005]; 
int visited[100005]; 
int n,m;  
int dfs(int cur,int cat_cnt,int par){
	// increment consecutive cats seen so far first  
	if (cat[cur]) cat_cnt++; 
	else cat_cnt = 0; 
	if (cat_cnt > m) return 0; // we saw m consecutive cats
	if (tree[cur].size() == 1 && tree[cur][0] == par){
		return 1;  // we reached a leaf of the tree 
	}
	int ret = 0; 
	for (int i = 0; i < tree[cur].size(); i++){
		int next = tree[cur][i];  
		if (!visited[next]){
			visited[next] = 1; 
			ret += dfs(next,cat_cnt,cur); 
		}
	} 
	return ret;  
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);  
	cin >> n >> m;  
	for (int i = 1; i <= n; i++){
		cin >> cat[i]; 
	}
	for (int i = 0; i < n-1; i++){
		int a,b; 
		cin >> a >> b;  // edge from a to b 
		tree[a].push_back(b); 
		tree[b].push_back(a);  
	}
	visited[1] = 1;  
	int ans = dfs(1,0,-1); // start from vertex 1  
	cout << ans << endl;
	return 0; 
}
