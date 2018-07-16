#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); 
vector<int> tree[200005]; 
vector<int> arr; 
int idx[200005]; // idx[i] = position of i in arr 
int subtree[200005]; // subtree[i] = size of subtree with root node i 
void dfs(int cur){
	arr.push_back(cur); 
	subtree[cur]++;  
	if (tree[cur].empty()){ 
		return;  
	}
	for (int i = 0; i < tree[cur].size(); i++){
		int next = tree[cur][i]; 
		dfs(next);  
		subtree[cur] += subtree[next];  
	}
}
int main(){
	fast();  
	int n,q,p; 
	cin >> n >> q;
	for (int i = 2; i <= n; i++){
		cin >> p; // p is the parent of index i 
		tree[p].push_back(i);  
	}  
	dfs(1);  
	for (int i = 0; i < arr.size(); i++){	
		idx[arr[i]] = i;  
	}
	while (q--){
		int u,k; 
		cin >> u >> k;
		if (subtree[u] < k || idx[u]+k-1 > arr.size()-1){
			cout << -1 << endl; 
		}else{
			cout << arr[idx[u]+k-1] << endl; 
		}
	}
	return 0;  
}
