#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector> 
#include <set> 
using namespace std;  
struct edge{
	int to,color; 
	edge(){} 
	edge(int a,int b):to(a),color(b){}
};  
vector<edge> G[111]; 
int visited[111];  
int res[111][111]; 
bool chk(int u,int v,int c){
	if (u == v) return true; 
	for (int i = 0; i < G[u].size(); i++){
		edge e = G[u][i]; 
		int next = e.to; 
		int color = e.color; 
		if (!visited[next] && c == color){
			visited[next] = 1; 
			if (chk(next,v,color)) return true; 
			visited[next] = 0; 
		}
	}
	return false;  
}
int main(){
	int n,m,q; 
	cin >> n >> m; 
	set<int> color_collection; 
	for (int i = 0; i < m; i++){
		int a,b,c; 
		cin >> a >> b >> c; 
		color_collection.insert(c);  
		// undirected graph 
		edge e(b,c); 
		G[a].push_back(e); 
		e.to = a; 
		G[b].push_back(e); 
	}
	cin >> q; 
	while (q--){
		int u,v; 
		cin >> u >> v;  
		int cnt = 0; 
		for (set<int>::iterator it = color_collection.begin(); it != color_collection.end(); it++){
			memset(visited,0,sizeof(visited)); 
			visited[u] = 1;  
			if (chk(u,v,*it)) cnt++; 
		}
		cout << cnt << endl; 
	} 
	return 0; 
}
