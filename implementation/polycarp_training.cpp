#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
int main(int argc,char **argv){
  int n,k = 1;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  sort(a,a+n);
  for (int i = 0; i < n; i++){
    if (k <= a[i]){
      k++;
    }
  }
  cout << k-1 << endl;
  return 0;
}
