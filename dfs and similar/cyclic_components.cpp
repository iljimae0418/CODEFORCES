#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <cstring> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
vector<int> G[200005];
int visited[200005]; 
void dfs(int cur,vector<int> &component){
	if (visited[cur]) return; 
	visited[cur] = 1;  
	component.push_back(cur);  
	for (int i = 0; i < G[cur].size(); i++){
		int next = G[cur][i]; 
		dfs(next,component);  
	}
}
int chk(vector<int> &component){
	for (int i = 0; i < component.size(); i++){
		if (G[component[i]].size() != 2) return 0; 
	}
	return 1; 
}
int main(){
	IOFAST();  
	int n,m;  
	cin >> n >> m; 
	for (int i = 0; i < m; i++){
		int a,b; 
		cin >> a >> b; 
		G[a].push_back(b); 
		G[b].push_back(a); 
	}
	int ans = 0; 
	for (int i = 1; i <= n; i++){
		vector<int> component; 
		if (!visited[i]){
			dfs(i,component);
			ans += chk(component);  
		}
	} 
	cout << ans << endl; 
	return 0; 
}
