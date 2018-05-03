#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std; 
#define MAXN 100005 // max number of vertices 
#define MAXM 100005 // max number of edges 
typedef long long ll;  
struct edge{
	int to; 
	ll cost; 
	edge(){} 
	edge(ll a,ll b): to(a),cost(b) {} 
};  
vector<edge> G[MAXN]; 
ll d[MAXN]; // d[i] = shortest distance to i 
int parent[MAXN]; 
typedef pair<ll,int> P; 
const ll INF = (ll)2e15+77; 
void dijkstra(int s){ // s: starting vertex  
	for (int i = 1; i < MAXN; i++){
		d[i] = INF;  
	}
	memset(parent,-1,sizeof(parent)); 
	d[s] = 0LL; 
	priority_queue< P,vector<P>,greater<P> > pq;
	pq.push(P(d[s],s));  
	while (!pq.empty()){
		P p = pq.top(); pq.pop(); 
		int v = p.second; 
		if (d[v] < p.first) continue; 
		for (int i = 0; i < G[v].size(); i++){
			edge e = G[v][i]; 
			if (d[e.to] > d[v]+e.cost){
				d[e.to] = d[v]+e.cost;  
				parent[e.to] = v; 
				pq.push(P(d[e.to],e.to)); 
			}
		}
	}
}
void reconstruct(vector<int> &path,int t){ // t = destination vertex
	for (;t!=-1;t = parent[t]){
		path.push_back(t); 
	}
	reverse(path.begin(),path.end()); 
}
int main(){
	int n,m,a,b,c; 
	cin >> n >> m; 
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;  
		edge e; 
		e.to = b, e.cost = c;   
		G[a].push_back(e); 
		e.to = a; 
		G[b].push_back(e);  
	}
	dijkstra(1); 
	vector<int> path; 
	reconstruct(path,n);  
	if (d[n] == INF) cout << -1 << endl;
	else{
		for (int i = 0; i < path.size(); i++){
			cout << path[i] << " "; 
		}
		cout << endl; 
	}
	return 0; 
}
