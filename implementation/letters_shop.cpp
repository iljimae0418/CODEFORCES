#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
int main(int argc,char **argv){
  int n,q;
  cin >> n;
  string s,t;
  cin >> s;
  map<char,vector<int> > mp;
  for (int i = 0; i < s.size(); i++){
    mp[s[i]].push_back(i+1);
  }
  cin >> q;
  while (q--){
    cin >> t;
    map<char,int> cnt;
    int ans = -1;
    for (int i = 0; i < t.size(); i++){
      cnt[t[i]]++;
    }
    for (map<char,int>::iterator it = cnt.begin(); it != cnt.end(); it++){
      char c = it->first;
      int idx = it->second;
      ans = max(ans,mp[c][idx-1]);
    }
    cout << ans << "\n";
  }
  return 0;
}
