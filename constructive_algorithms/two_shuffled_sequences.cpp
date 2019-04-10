/*
The idea is that if we have more than two of some number,
it is impossible to form a strictly increasing and decreasing sequence
*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 2e5+5;
int cnt[MAXN];
int main(int argc,char **argv){
  int n,x;
  cin >> n;
  vector<int> f,s;
  for (int i = 0; i < n; i++){
    cin >> x;
    cnt[x]++;
    if (cnt[x] == 1){
      f.push_back(x);
    }else if (cnt[x] == 2){
      s.push_back(x);
    }else if (cnt[x] >= 3){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  sort(f.begin(),f.end());
  sort(s.begin(),s.end());
  cout << f.size() << endl;
  for (int i = 0; i < f.size(); i++){
    cout << f[i] << " ";
  }
  cout << endl;
  cout << s.size() << endl;
  for (int i = s.size()-1; i >= 0; i--){
    cout << s[i] << " ";
  }
  cout << endl;
  return 0;  
}
