// BFS 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue> 
using namespace std; 
const int INF = 2e9;  
int h,w,k,x1,y1,x2,y2; 
string b[1010];  
int dx[4] = {0,1,0,-1};  
int dy[4] = {1,0,-1,0};  
int dist[1010][1010]; 
bool inRange(int x,int y){
	return (x >= 0 && x < h && y >= 0 && y < w); 
}
int main(){
	cin >> h >> w >> k; 
	for (int i = 0; i < h; i++){
		cin >> b[i]; 
	}
	cin >> x1 >> y1 >> x2 >> y2;  
	x1--,y1--,x2--,y2--; // change to 0-based indexing  
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			dist[i][j] = INF;  
		}
	}
	dist[x1][y1] = 0;  
	queue<int> que;  
	que.push(x1*1010+y1);  
	while (!que.empty()){
		int q = que.front(); que.pop(); 
		int x = q/1010;  
		int y = q%1010;  
		int cnt = dist[x][y];  
		if (x == x2 && y == y2){
			cout << cnt << endl; 
			return 0; 
		}
		for (int d = 0; d < 4; d++){
			int nx = x,ny = y;  
			for (int i = 0; i < k; i++){
				nx += dx[d], ny += dy[d]; 
				if (inRange(nx,ny)){
					if (b[nx][ny] == '#' || dist[nx][ny] <= cnt){
						break; 
					}
					if (b[nx][ny] == '.' && dist[nx][ny] == INF){
						dist[nx][ny] = cnt+1; 
						que.push(nx*1010+ny); 
					}
				}else{
					break; 
				}
			}
		}
	}
	cout << -1 << endl; // no possible path 
	return 0;  
}
