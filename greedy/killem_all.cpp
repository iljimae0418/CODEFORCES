#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int seen[100005];
int main(int argc,char **argv){
  IOFAST();
  int q;
  cin >> q;
  while (q--){
    int n,r,x;
    cin >> n >> r;
    set<int> st;
    for (int i = 0; i < n; i++){
      cin >> x;
      st.insert(x);
    }
    // elements in set are unique and are already sorted
    n = st.size(); // update the number of elements without duplicates
    int ans = 1; // we need to explode at least once (and at most n times)
    int cnt = 0;
    for (int val : st){
      if (val-(n-cnt-1)*r > 0){
        ans = n-cnt;
        break;
      }else{
        cnt++;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
