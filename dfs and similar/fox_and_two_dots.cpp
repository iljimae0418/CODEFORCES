#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
const int N = 55;
const int M = 55;
char grid[N][M];
int n,m;
int visited[N][M];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
bool inRange(int x,int y){
  return (x >= 1 && x <= n && y >= 1 && y <= m);
}
bool cycle;
void dfs(int curx,int cury,int px,int py,char color){
  if (visited[curx][cury]){
    cycle = true;
    return;
  }
  visited[curx][cury] = 1;
  for (int i = 0; i < 4; i++){
    int nx = curx+dx[i];
    int ny = cury+dy[i];
    if (nx == px && ny == py) continue; // don't move back to the direction of the parent vertex
    if (inRange(nx,ny) && grid[nx][ny] == color){
      dfs(nx,ny,curx,cury,color);
    }
  }
}
int main(int argc,char **argv){
  cin >> n >> m;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> grid[i][j]; 
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (!visited[i][j]){
        dfs(i,j,-1,-1,grid[i][j]);
      }
    }
  }
  puts(cycle ? "Yes" : "No");
  return 0;
}
