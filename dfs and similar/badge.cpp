#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
using namespace std; 
int p[1005]; 
int visited[1005]; 
int dfs(int x){
	if (visited[x]) return x; 
	visited[x] = 1; 
	return dfs(p[x]);  
}
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> p[i]; 
	}
	for (int i = 1; i <= n; i++){
		memset(visited,0,sizeof(visited)); 
		cout << dfs(i) << " ";  
	}
	cout << endl; 
	return 0;  
}
