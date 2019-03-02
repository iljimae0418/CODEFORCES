#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;
map<char,vector<int> > mp;
void DEBUG(){
  for (map<char,vector<int> >::iterator it = mp.begin(); it != mp.end(); it++){
    cout << it->first << ":";
    for (int i = 0; i < it->second.size() ;i++){
      cout << it->second[i] << " ";
    }
    cout << endl;
  }
}
int main(int argc,char **argv){
  int n,k,cnt = 0;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i+1 < n; i++){
    if (s[i] == s[i+1]){
      cnt++;
    }else{
      mp[s[i]].push_back(cnt+1);
      cnt = 0;
    }
  }
  if (cnt == 0){
    cnt++;
    mp[s[n-1]].push_back(cnt);
  }else if (cnt > 0){
    mp[s[n-1]].push_back(cnt+1);
  }
  // DEBUG();
  int maxLevel = 0;
  for (map<char,vector<int> >::iterator it = mp.begin(); it != mp.end(); it++){
    vector<int> v = it->second;
    int level = 0;
    for (int i = 0; i < v.size(); i++){
      level += v[i]/k;
    }
    maxLevel = max(maxLevel,level);
  }
  cout << maxLevel << endl;
  return 0;
}
