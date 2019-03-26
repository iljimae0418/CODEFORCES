/*
Tentative, haven't tested the code yet 
Note that
p[n] = p[1] + (p[2]-p[1]) + (p[3]-p[2]) + ... + (p[n]-p[n-1])
= p[1] + q[1] + q[2] + ... + q[n-1]

so in fact we have to find
p[1],p[1]+q[1],p[1]+q[1]+q[2],...,p[1]+q[1]+q[2]+...+q[n-1]
1 <= p[1]+q[1]+q[2],...,p[1]+q[1]+q[2]+...+q[n-1] <= n
1 <= p[1] + k <= n
1-k <= p[1] <= n-k
x + maxval <= n
x + minval >= 1
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 2e5 + 5;
typedef long long ll;
ll a[MAXN];
ll psum[MAXN];
int main(int argc,char **argv){
  IOFAST();
  ll n,minval = 1e17,maxval = -1e17;
  cin >> n;
  for (int i = 1; i <= n-1; i++){
    cin >> a[i];
  }
  for (int i = 1; i <= n-1; i++){
    psum[i] = psum[i-1]+a[i];
    minval = min(minval,psum[i]);
    maxval = max(maxval,psum[i]);
  }
  // decide what p[1] is going to be
  ll x = -1;
  for (ll i = 1; i <= n; i++){
    if (i+maxval <= n && i+minval >= 1){
      x = i;
      break;
    }
  }
  if (x == -1) cout << -1 << endl;
  else{
    for (int i = 0; i < n; i++){
      cout << x+psum[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
