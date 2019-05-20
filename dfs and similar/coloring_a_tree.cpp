#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 10005;
int p[MAXN],c[MAXN];
vector<int> g[MAXN];
int visited[MAXN];
int ans = 1;
void dfs(int v){
  visited[v] = 1;
  for (int i = 0; i < g[v].size(); i++){
    int u = g[v][i];
    if (!visited[u]){
      if (c[u] != c[v]) ans++;
      dfs(u);
    }
  }
}
int main(int argc,char **argv){
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++){
    cin >> p[i];
    g[i].push_back(p[i]);
    g[p[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++){
    cin >> c[i];
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}
