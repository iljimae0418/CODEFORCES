#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
vector<int> a[10];
int sum[10];
void init(){
  for (int i = 1; i <= 9; i++){
    int pos = i;
    while (pos != 0){
      sum[i] += pos;
      a[i].push_back(pos);
      pos = (pos+i)%10;
    }
    a[i].push_back(0);
  }
}
int main(int argc,char **argv){
  IOFAST();
  init();
  int q;
  cin >> q;
  while (q--){
    ll n,m;
    cin >> n >> m; // number of pages, required divisor
    if (m == 0 || m%10 == 0) cout << 0 << "\n";
    else{
      ll cycle = n/m;
      ll rem = cycle%a[m%10].size();
      // cout << cycle << " " << rem << endl;
      ll ans = (cycle/a[m%10].size())*sum[m%10];
      for (int i = 0; i < rem; i++){
        ans += a[m%10][i];
      }
      cout << ans << "\n";
    }
  }
  return 0;
}
