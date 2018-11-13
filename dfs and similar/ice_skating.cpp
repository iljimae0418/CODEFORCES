#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set> 
#include <vector>
#include <map> 
using namespace std;  
typedef pair<int,int> P;  
int graph[105][105]; // all coordinates are unique
int visited[105];  
vector<P> v;   
void dfs(int x){
	visited[x] = 1;  
	for (int i = 0; i < v.size(); i++){
		if (graph[x][i] && !visited[i]){
			dfs(i);  
		}
	}
	return; 
}
int main(int argc,char **argv){
	int n; 
	cin >> n;
	v.resize(n);  
	for (int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second; 
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j) continue;  
			if (v[i].first == v[j].first || 
				v[i].second == v[j].second){
				// connected 
				graph[i][j] = graph[j][i] = 1;  
			}else{
				// not connected  
				graph[i][j] = 0;  
			}
		}
	} 
	int cnt = 0;  
	for (int i = 0; i < v.size(); i++){
		if (!visited[i]){
			dfs(i);  
			cnt++;  
		}
	}
	cout << cnt-1 << endl; 
	return 0;  
}
