// bfs version - perhaps an overkill 
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring> 
#include <vector>
#include <queue> 
using namespace std; 
typedef pair<int,int> P;  
int previous[9][9];
int visited[9][9];  
int dx[8] = {-1,-1,-1,0,1,1,1,0}; 
int dy[8] = {-1,0,1,1,1,0,-1,-1};
string dir[8] = {"LD","L","LU","U","RU","R","RD","D"}; // grid rotated by 90 degress 
bool inRange(int x,int y){
	return (x >= 1 && x <= 8 && y >= 1 && y <= 8); 
}
int main(){
	int sx,sy,gx,gy; 
	string s,g; 
	cin >> s >> g;  
	sx = (s[0]-'a')+1;  
	sy = s[1]-'0'; 
	gx = (g[0]-'a')+1;  
	gy = g[1]-'0'; 
	queue< pair<P,int> > q; // stores (point,distance to that point from (sx,sy))
	q.push(make_pair(P(sx,sy),0));  
	visited[sx][sy] = 1; 
	memset(previous,-1,sizeof(previous)); 
	while (!q.empty()){
		pair<P,int> p = q.front(); q.pop();  
		int curx = p.first.first, cury = p.first.second; 
		int d = p.second; 
		if (curx == gx && cury == gy){
			cout << d << endl; 
			break; 
		}
		for (int i = 0; i < 8; i++){
			int nx = curx+dx[i];  
			int ny = cury+dy[i];  
			if (inRange(nx,ny) && !visited[nx][ny]){
				visited[nx][ny] = 1;  
				q.push(make_pair(P(nx,ny),d+1));  
				previous[nx][ny] = curx*10+cury;   
			}
		}
	}	
	// time for reconstruction 
	int tx = gx, ty = gy; 
	vector<string> seq; 
	while (previous[tx][ty] != -1){
		int pred_x = previous[tx][ty]/10;  
		int pred_y = previous[tx][ty]%10; 
		for (int i = 0; i < 8; i++){
			if (pred_x+dx[i] == tx && pred_y+dy[i] == ty){
				seq.push_back(dir[i]); 
				tx = pred_x;  
				ty = pred_y; 
				break; 
			}
		}
	}
	reverse(seq.begin(),seq.end()); 
	for (int i = 0; i < seq.size(); i++){
		cout << seq[i] << endl; 
	}
	return 0; 	
}	
