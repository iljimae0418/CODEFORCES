#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int psum[MAXN];
int main(int argc,char **argv){
  int n,m;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++){
    psum[i] = psum[i-1]+a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++){
    int x;
    cin >> x;
    int pos = lower_bound(psum+1,psum+n+1,x)-(psum+1);
    cout << (pos+1) << "\n";
  }
  return 0;
}
