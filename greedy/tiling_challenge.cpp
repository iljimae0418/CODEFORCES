#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 55;
char grid[MAXN][MAXN];
bool inRange(int n,int x,int y){
  return (x >= 1 && x <= n && y >= 1 && y <= n);
}
bool valid(int n,int i,int j){
  int di[4] = {1,0,-1,0};
  int dj[4] = {0,1,0,-1};
  for (int k = 0; k < 4; k++){
    int ni = i+di[k];
    int nj = j+dj[k];
    if (!(inRange(n,ni,nj) && grid[ni][nj] == '.')){
      return false;
    }
  }
  return true; 
}
int main(int argc,char **argv){
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      cin >> grid[i][j];
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (grid[i][j] == '.' && valid(n,i,j)){
        grid[i][j] = grid[i-1][j] = grid[i+1][j] = grid[i][j-1]
        = grid[i][j+1] = '#';
      }
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= n; j++){
      if (grid[i][j] == '.'){
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
