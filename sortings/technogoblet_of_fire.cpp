#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int p[101],s[101],c[101];
int main(int argc,char **argv){
  int n,m,k,ans = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++){
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++){
    cin >> s[i];
  }
  for (int i = 1; i <= k; i++){
    cin >> c[i];
  }
  map<int,priority_queue<int,vector<int>,less<int> > > mp;
  for (int i = 1; i <= n; i++){
    mp[s[i]].push(p[i]);
  }
  for (int i = 1; i <= k; i++){
    if (mp[s[c[i]]].top() != p[c[i]]) ans++;
  }
  cout << ans << "\n";
  return 0;
}
