#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  int n;
  cin >> n;
  while (n--){
    string s;
    cin >> s;
    bool passed = true;
    sort(s.begin(),s.end());
    for (int i = 1; i < s.size(); i++){
      if (s[i]-s[i-1] != 1){
        passed = false;
        cout << "No" << endl;
        break;
      }
    }
    if (passed) cout << "Yes" << endl;
  }
  return 0;
}
