#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int MAXN = 100005;
int a[MAXN],b[MAXN];
int main(int argc,char **argv){
  int n,cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    b[i] = i;
  }
  for (int i = 0; i < n; i++){
    if (a[i]==b[i]) cnt++;
  }
  if (cnt == n){
    cout << n << endl;
  }else{
    bool exists = false;
    for (int i = 0; i < n; i++){
      if (a[i] != b[i] && a[a[i]] == i){
        exists = true;
      }
    }
    if (exists) cout << cnt+2 << endl;
    else cout << cnt+1 << endl;
  }
  return 0;
}
