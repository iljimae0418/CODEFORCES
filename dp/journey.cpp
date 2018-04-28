#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring> 
using namespace std; 
vector<int> tree[100005];
int visited[100005];  
int dp[100005]; 
long double solve(int x = 1,int p = -1){
	long double sum = 0; 
	for (int i = 0; i < tree[x].size(); i++){
		int next = tree[x][i]; 
		if (next != p){
			sum += solve(next,x)+1; 
		}
	}
	return sum ? sum/ (tree[x].size()-(p != -1)) : 0;  
}
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n-1; i++){
		int u,v; 
		cin >> u >> v; 
		tree[u].push_back(v);  
		tree[v].push_back(u); 
	} 
	cout.setf(ios::showpoint); 
	cout.setf(ios::fixed); 
	cout.precision(15);  
	cout << solve() << endl; 
	return 0;  
}
