// spruce if its every non-leaf vertex has at least 3 leaf children 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
const int MAXN = 1005;  
vector<int> G[MAXN]; 
int leaf_child[MAXN];  
void dfs(int cur,int parent){ 
	if (G[cur].empty()){
		leaf_child[parent]++;  
		return;  
	}
	for (int i = 0; i < G[cur].size(); i++){
		int next = G[cur][i]; 
		if (next != parent){
			dfs(next,cur); 
		}
	}
}
int main(){
	IOFAST(); 
	int n,parent; 
	cin >> n; // it is guaranteed n >= 3 and we have a rooted tree at node 1
	for (int i = 2; i <= n; i++){
		cin >> parent; 
		G[parent].push_back(i); 
	}
	dfs(1,-1); 
	bool spruce = true; 
	for (int i = 1; i <= n; i++){
		if (leaf_child[i] > 0 && leaf_child[i] <= 2){
			spruce = false; 
			break; 
		}else if (leaf_child[i] <= 2 && G[i].size() > 0){ 
			// condition such that the node has children, but its children 
			// are not leaf nodes 
			spruce = false; 
			break; 
		}
	}
	cout << (spruce ? "Yes" : "No") << endl; 
	return 0;  
}
