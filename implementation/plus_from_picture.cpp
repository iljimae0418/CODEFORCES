#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 505;
char grid[MAXN][MAXN];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int h,w;
/*
Find a location on the grid such that there exists at least one asterisk
at the top,bottom,left or right of the current asterisk.
*/
bool inRange(int x,int y){
  return (x >= 0 && x < h && y >= 0 && y < w);
}
bool chk(int x,int y){
  int cnt = 0;
  for (int k = 0; k < 4; k++){
    int nx = x+dx[k];
    int ny = y+dy[k];
    if (inRange(nx,ny) && grid[nx][ny] == '*') cnt++;
  }
  return cnt == 4;
}
void process(int x,int y){
  int tx = x,ty = y;
  while (tx >= 0 && grid[tx][ty] == '*'){
    grid[tx][ty] = '.';
    tx--;
  }
  tx = x+1, ty = y;
  while (tx < h && grid[tx][ty] == '*'){
    grid[tx][ty] = '.';
    tx++;
  }
  tx = x, ty = y-1;
  while (ty >= 0 && grid[tx][ty] == '*'){
    grid[tx][ty] = '.';
    ty--;
  }
  tx = x, ty = y+1;
  while (ty < w && grid[tx][ty] == '*'){
    grid[tx][ty] = '.';
    ty++;
  }
}
int main(int argc,char **argv){
  cin >> h >> w;
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cin >> grid[i][j];
    }
  }
  bool found = false;
  for (int i = 0; i < h; i++){
    if (found) break;
    for (int j = 0; j < w; j++){
      if (grid[i][j] == '*' && chk(i,j)){
        process(i,j);
        found = true;
        break;
      }
    }
  }
  /*for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      cout << grid[i][j];
    }
    cout << endl;
  }*/
  if (!found){
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < h; i++){
    for (int j = 0; j < w; j++){
      if (grid[i][j] == '*' && found){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
