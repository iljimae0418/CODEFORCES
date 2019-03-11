#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN = 101;
int l[MAXN],r[MAXN];
int main(int argc,char **argv){
  int n,k,cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> l[i] >> r[i];
  }
  cin >> k;
  for (int i = 0; i < n; i++){
    if (k > r[i]){
      cnt++;
    }else{
      break; 
    }
  }
  cout << n-cnt << endl;
  return 0;
}
