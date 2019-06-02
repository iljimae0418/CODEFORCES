#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> P;
int main(int argc,char **argv){
  int k;
  scanf("%d",&k);
  vector<P> f;
  for (int i = 1; i*i <= k; i++){
    if (k%i == 0){
      f.push_back(P(i,k/i));
    }
  }
  int n = -1,m = -1;
  for (int i = 0; i < f.size(); i++){
    if (f[i].first >= 5 && f[i].second >= 5){
      n = f[i].first;
      m = f[i].second;
      break;
    }
  }
  if (n == -1 && m == -1){
    return !printf("-1\n");
  }
  char grid[n+1][m+1];
  memset(grid,0,sizeof(grid));
  char c[5] = {'a','e','i','o','u'};
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      grid[i][j] = c[(i+j)%5];
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      printf("%c",grid[i][j]);
    }
  }
  puts("");
  return 0;
}
