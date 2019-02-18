#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int maxval = 0;
int main(int argc,char **argv){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    maxval = max(maxval,a[i]);
  }
  int maxlen = 0,cnt = 0;
  for (int i = 0; i < n; i++){
    if (a[i] == maxval){
      cnt++;
    }else{
      maxlen = max(maxlen,cnt);
      cnt = 0;
    }
  }
  maxlen = max(maxlen,cnt);
  cout << maxlen << endl;
  return 0;
}
