#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
const int MAXN = 3e5+5;
ll x[MAXN],p[MAXN];
ll gcd(ll a,ll b){
  if (b == 0) return a;
  return gcd(b,a%b);
}
int main(int argc,char **argv){
  IOFAST();
  int n,m;
  cin >> n >> m;
  vector<ll> d;
  for (int i = 1; i <= n; i++){
    cin >> x[i];
  }
  for (int i = 1; i <= m; i++){
    cin >> p[i];
  }
  for (int i = 2; i <= n; i++){
    d.push_back(x[i]-x[i-1]);
  }
  ll g = d[0];
  for (int i = 1; i < d.size(); i++){
    g = gcd(g,d[i]);
  }
  for (int i = 1; i <= m; i++){
    if (g%p[i] == 0){
      cout << "YES" << endl;
      cout << x[1] << " " << i << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
