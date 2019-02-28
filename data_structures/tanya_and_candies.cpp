#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
typedef long long ll;
ll esum[MAXN],osum[MAXN];
int main(int argc,char **argv){
  int n,cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
    if ((i&1) && i > 1){
      osum[i] = osum[i-2]+a[i];
      osum[i-1] = osum[i-2];
    }else if ((i&1) && i == 1){
      osum[i] = a[i];
    }else{
      esum[i] = esum[i-2]+a[i];
      esum[i-1] = esum[i-2];
    }
  }
  if (n&1){ // n is odd
    ll es = esum[n-1];
    ll os = osum[n];
    for (int i = 1; i <= n; i++){
      ll t_es = es;
      ll t_os = os;
      if (i == n){
        t_os -= a[i];
        cnt += (t_es == t_os ? 1 : 0);
        continue;
      }else if (i == n-1){
        t_os -= a[n];
        t_es = t_es-a[n-1]+a[n];
        cnt += (t_es == t_os ? 1 : 0);
        continue;
      }
      if (i&1){
        t_es = t_es-(esum[n-1]-esum[i])+(osum[n]-osum[i+1]);
        t_os = t_os-(osum[n]-osum[i-1])+(esum[n-1]-esum[i]);
      }else{
        t_es = t_es-(esum[n-1]-esum[i-1])+(osum[n]-osum[i]);
        t_os = t_os-(osum[n]-osum[i])+(esum[n-1]-esum[i+1]);
      }
      cnt += (t_es == t_os ? 1 : 0);
    }
  }else{ // n is even
    ll es = esum[n];
    ll os = osum[n-1];
    for (int i = 1; i <= n; i++){
      ll t_es = es;
      ll t_os = os;
      if (i == n){
        t_es -= a[i];
        cnt += (t_es == t_os ? 1 : 0);
        continue;
      }else if (i == n-1){
        t_os = t_os-a[n-1]+a[n];
        t_es = t_es-a[n];
        cnt += (t_es == t_os ? 1 : 0);
        continue;
      }
      if (i&1){
        t_es = t_es-(esum[n]-esum[i])+(osum[n-1]-osum[i+1]);
        t_os = t_os-(osum[n-1]-osum[i-1])+(esum[n]-esum[i]);
      }else{
        t_es = t_es-(esum[n]-esum[i-1])+(osum[n-1]-osum[i]);
        t_os = t_os-(osum[n-1]-osum[i])+(esum[n]-esum[i+1]);
      }
      cnt += (t_es == t_os ? 1 : 0);
    }
  }
  cout << cnt << "\n";
  return 0;
}
