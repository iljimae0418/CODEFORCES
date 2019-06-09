#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// if i,j are coprime, then they should be assigned different numbers
const int MAXN = 100005;
int prime[MAXN];
int ans[MAXN];
int main(int argc,char **argv){
  IOFAST();
  int n;
  cin >> n;
  for (int i = 0; i < MAXN; i++){
    prime[i] = 1;
  }
  prime[0] = prime[1] = 0;
  int assign = 1;
  for (long long i = 2; i < MAXN; i++){
    if (prime[i]){
      ans[i] = assign;
      for (long long j = i*i; j < MAXN; j += i){
        prime[j] = 0;
        ans[j] = assign;
      }
      assign++;
    }
  }
  // print solution
  for (int i = 2; i <= n; i++){
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}
