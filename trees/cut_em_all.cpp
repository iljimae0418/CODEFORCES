#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
vector<int> G[100005]; 
long long dp[100005];  
void dfs(int cur,int parent){
	dp[cur] = 1LL; 
	for (int i = 0; i < G[cur].size(); i++){
		int next = G[cur][i]; 
		if (next != parent){
			dfs(next,cur); 
			dp[cur] += dp[next]; 
		}
	}
}
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n-1; i++){
		int a,b; 
		cin >> a >> b; 
		G[a].push_back(b); 
		G[b].push_back(a); 
	}
	int leaf = -1; 
	for (int i = 1; i <= n; i++){
		if (G[i].size() == 1){
			leaf = i; 
			break; 
		}
	}	
	dfs(leaf,-1); 
	int ans = 0; 
	for (int i = 1; i <= n; i++){
		if (dp[i]%2 == 0 && G[i].size() > 1){
			ans++; 
		}
	}
	if (n%2 == 0) cout << ans << endl; 
	else cout << -1 << endl; 
	return 0; 
}
