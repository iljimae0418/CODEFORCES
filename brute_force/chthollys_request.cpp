#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll> v;
ll power(ll a,ll x){
  if (x == 0LL) return 1LL;
  if (x == 1LL) return a;
  return power(a,x/2)*power(a,x/2)*power(a,x%2);
}
void form(int i,int d,ll x){ // d is even
  if (i > d/2){
    v.push_back(x);
    return;
  }
  for (int j = 0; j <= 9; j++){
    if (i == 1 && j == 0) continue;
    x += j*power(10,d-i) + j*power(10,i-1);
    form(i+1,d,x);
    x -= j*power(10,d-i) + j*power(10,i-1);
  }
}
int main(int argc,char **argv){
  int k,p;
  cin >> k >> p;
  // preprocessing step
  for (int d = 2; d <= 10; d += 2){
    form(1,d,0);
  }
  v.push_back(100000000001LL);
  // computation step 
  ll ans = 0;
  for (int i = 0; i < k; i++){
    ans += v[i];
    ans %= p;
  }
  cout << ans << "\n";
  return 0;
}
