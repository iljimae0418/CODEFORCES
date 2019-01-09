#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm>
#include <vector> 
using namespace std;
typedef long long ll;  
const int MAXV = 100005; 
int color[MAXV]; 
int connected[MAXV]; 
vector<int> G[MAXV]; 
void dfs(int cur,int c){
	color[cur] = c; 
	for (int i = 0; i < G[cur].size(); i++){
		if (color[G[cur][i]] == 0){
			dfs(G[cur][i],-c);  
		}
	}
}
int main(int argc,char **argv){
	int n,u,v;
	ll ans = 0;  
	scanf("%d",&n); 
	for (int i = 0; i < n-1; i++){
		scanf("%d %d",&u,&v);  
		G[u].push_back(v); 
		G[v].push_back(u);  
	}
	for (int i = 1; i <= n; i++){
		if (color[i] == 0){
			dfs(i,1); 
		}
	}
	vector<int> group_one,group_two; 
	for (int i = 1; i <= n; i++){
		if (color[i] == 1){
			group_one.push_back(i); 
		}else{
			group_two.push_back(i);  
		}
	}
	for (int i = 0; i < group_one.size(); i++){
		ans += (ll)group_two.size()-(ll)G[group_one[i]].size();  
	}
	printf("%lld\n",ans); 
	return 0; 
}
