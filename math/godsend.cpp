#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e6+5;
ll a[MAXN];
int main(int argc,char **argv){
  int n;
  cin >> n;
  ll sum = 0;
  bool odd = false;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    if (a[i]&1) odd = true;
    sum += a[i];
  }
  if (sum&1){
    cout << "First" << "\n";
  }else{
    if (odd) cout << "First" << "\n";
    else cout << "Second" << "\n";
  }
  return 0;
}
