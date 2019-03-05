#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 3e5+5;
typedef long long ll;
ll a[MAXN],psum[MAXN],q[MAXN];
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
  int n,m;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++){
    cin >> q[i];
  }
  sort(a+1,a+n+1);
  for (int i = 1; i <= n; i++){
    psum[i] = psum[i-1]+a[i];
  }
  for (int i = 1; i <= m; i++){
    cout << psum[n]-psum[n-q[i]+1]+psum[n-q[i]] << "\n";
  }
  return 0;
}
