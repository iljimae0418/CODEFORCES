/*
If we have l nodes on one set and r nodes on the other set, there can be l*r edges total that maintains bipartite propeerty. 
Since there are already n-1 edges, the maximum number of edges that can be added while maintaining bipartite property is 
l*r - (n-1). 
*/ 

#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
vector<int> adj[100005];  
int color[100005];  
int visited[100005]; 
void dfs(int cur,int c){
	if (visited[cur]) return;  
	visited[cur] = 1;  
	if (c == 1){
		color[cur] = 1;  
		for (int i = 0; i < adj[cur].size(); i++){
			int next = adj[cur][i];  
			dfs(next,-1); 
		}
	}else if (c == -1){
		color[cur] = -1;  
		for (int i = 0; i < adj[cur].size(); i++){
			int next = adj[cur][i];  
			dfs(next,1); 
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	int n; 
	cin >> n; 
	for (int i = 0; i < n-1; i++){
		int a,b; 
		cin >> a >> b; 
		adj[a].push_back(b); 
		adj[b].push_back(a); 
	}
	dfs(1,1);  
	int totalOne = 0, totalNegone = 0; 
	for (int i = 1; i <= n; i++){
		if (color[i] == 1) totalOne++; 
		else if (color[i] == -1) totalNegone++; 
	}
	/*int ans = 0; 
	for (int i = 1; i <= n; i++){
		int cnt = 0; 
		if (color[i] == 1){
			for (int j = 0; j < adj[i].size(); j++){
				int neighbor = adj[i][j]; 
				if (color[neighbor] == -1){
					cnt++; 
				}
			}
			ans += (totalNegone-cnt); 
		}else if (color[i] == -1){
			for (int j = 0; j < adj[i].size(); j++){
				int neighbor = adj[i][j];  
				if (color[neighbor] == 1){
					cnt++;  
				}
			}
			ans += (totalOne-cnt); 
		}
	}
	cout << ans/2 << endl;*/ 
	long long ans = (long long)totalOne*(long long)totalNegone-(n-1); 
	cout << ans << endl; 
	return 0;  
}
