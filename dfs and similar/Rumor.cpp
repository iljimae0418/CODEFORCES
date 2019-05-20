/*
Algorithm: sum of minimum cost for each connected component
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 100005;
typedef long long ll;
const ll INF = 1e17+9;
vector<int> adj[MAXN];
ll c[MAXN];
int visited[MAXN];
ll minval = INF;
void dfs(int v){
  if (visited[v]) return;
  visited[v] = 1;
  minval = min(minval,c[v]);
  for (int i = 0; i < adj[v].size(); i++){
    int u = adj[v][i];
    dfs(u);
  }
}
int main(int argc,char **argv){
  int n,m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    cin >> c[i];
  }
  for (int i = 0; i < m; i++){
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ll sum = 0;
  for (int i = 1;i <= n; i++){
    if (!visited[i]){
      minval = INF;
      dfs(i);
      sum += minval;
    }
  }
  cout << sum << endl;
  return 0;
}
