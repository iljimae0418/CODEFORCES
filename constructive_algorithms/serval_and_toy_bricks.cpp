#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int grid[105][105];
int col[105],row[105];
int rowcnt[105],colcnt[105];
int main(int argc,char **argv){
  int n,m,h;
  cin >> n >> m >> h;
  for (int i = 1; i <= m; i++){
    cin >> col[i];
  }
  for (int i = 1; i <= n; i++){
    cin >> row[i];
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cin >> grid[i][j];
      rowcnt[i] += grid[i][j];
      colcnt[j] += grid[i][j];
    }
  }
  for (int i = 1; i <= m; i++){
    for (int j = n; j >= 1; j--){
      if (grid[j][i] == 1 && row[j] >= col[i]){
        grid[j][i] = col[i];
      }
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      if (grid[i][j] == 1 && row[i] <= col[j]){
        grid[i][j] = row[i];
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
  return 0; 
}
