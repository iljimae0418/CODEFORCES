#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 100005;
int a[MAXN];
int main(int argc,char **argv){
  IOFAST();
  int n, even = 0, odd = 0;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> a[i];
    if (a[i]&1) odd++;
    else even++;
  }
  if (even != n && odd != n){
    sort(a,a+n);
  }
  for (int i = 0; i < n; i++){
    cout << a[i] << " ";
  }
  cout << endl; 
  return 0;
}
