// need to have at least n-1 edges 
// since m is less than n/2 it is always possible to have n-1 edges 
// find the vertex that can be connected to n-1 other vertices 
// we are dealing with a bi-directional graph 
// thus if we cannot have road from 1-3 then we also cannot have road from 3-1
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
int graph[1005][1005]; 
int main(){
	IOFAST();  
	for (int i = 0; i < 1005; i++){
		for (int j = 0; j < 1005; j++){
			graph[i][j] = 1;  
		}
	}
	int n,m,x,y; 
	cin >> n >> m; 
	for (int i = 0; i < m; i++){
		cin >> x >> y; 
		graph[x][y] = graph[y][x] = 0;  
	}
	// print out that there are n-1 solutions first 
	cout << n-1 << endl; 
	for (int i = 1; i <= n; i++){
		int cnt = 0; 
		for (int j = 1; j <= n; j++){
			if (i == j) continue; 
			if (graph[i][j]) cnt++; 
		}
		if (cnt == n-1){
			for (int j = 1; j <= n; j++){
				if (i == j) continue; 
				cout << i << " " << j << endl; 
			}
			break; 
		}
	}
	return 0;  
}
