#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
vector<int> G[2222]; 
int maxHeight(int cur,int parent){
	if (G[cur].empty()) return 1;  
	int ret = 0; 
	for (int i = 0; i < G[cur].size(); i++){
		int next = G[cur][i]; 
		if (next != parent) ret = max(ret,1+maxHeight(next,cur)); 
	}
	return ret;  
}
int main(){
	// there are 5 nodes in total 
	// edge from 1->2, 1->4 and 2->3 
	int n,parent; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> parent;  
		if (parent != -1){
			G[parent].push_back(i); 
		}
	}
	int ans = 0; 
	for (int i = 1; i <= n; i++){
		ans = max(ans,maxHeight(i,-1)); 
	} 
	cout << ans << endl; 
	return 0; 
}
