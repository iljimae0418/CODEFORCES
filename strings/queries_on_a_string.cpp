#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc,char **argv){
  string s;
  cin >> s;
  int m;
  cin >> m;
  while (m--){
    int l,r,k;
    cin >> l >> r >> k;
    l--,r--; // using 0-based indexing
    int len = r-l+1;
    k %= len;
    if (k == 0) continue;
    string t = s.substr(l,len);
    string t1 = t.substr(0,len-k);
    string t2 = t.substr(len-k);
    t = t2+t1;
    s = s.substr(0,l) + t + s.substr(r+1);
  }
  cout << s << "\n";
  return 0; 
}
