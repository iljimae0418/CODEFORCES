#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
int t[MAXN],cnt[MAXN];
int psum[MAXN];
int main(int argc,char **argv){
  int n,A,B,C,T,maxt = 0;
  cin >> n >> A >> B >> C >> T;
  for (int i = 1; i <= n; i++){
    cin >> t[i];
    cnt[t[i]]++;
  }
  sort(t+1,t+n+1);
  maxt = t[n];
  if (C <= B){
    cout << n*A << endl;
  }else{
    for (int i = 1; i <= T; i++){
      psum[i] = psum[i-1]+cnt[i];
    }
    int ans = 0;
    for (int i = 1; i <= T-1; i++){
      ans += C*psum[i];
    }
    for (int i = 1; i <= n; i++){
      ans += (A-B*(T-t[i]));
    }
    cout << max(ans,n*A) << endl;
  }
  return 0;
}
