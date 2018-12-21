// delete all nodes with only one edge 
// we care about degrees of the nodes
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <vector> 
#include <map> 
#include <set> 
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
#define MAXN 111 
set<int> g[MAXN]; 
bool chk(int n,vector<int> &destroy){
	for (int i = 1; i <= n; i++){
		if (g[i].size() == 1){
			destroy.push_back(i);  
		}
	}
	return destroy.empty();  
}
int main(int argc,char **argv){
	IOFAST(); 
	int n,m,a,b; 
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> a >> b; 
		g[a].insert(b);  
		g[b].insert(a); 
	} 
	int cnt = 0;  
	while (1){
		vector<int> destroy; // empty vector
		if (chk(n,destroy)) break;
		for (int i = 0; i < destroy.size(); i++){
			int x = destroy[i]; 
			g[x].clear();  
			for (int j = 1; j <= n; j++){
				if (j == x) continue; 
				if (g[j].count(x)){
					g[j].erase(x);  
				}
			}
		} 
		cnt++;  // one group destroyed! 
	}
	cout << cnt << endl; 
	return 0; 
}
