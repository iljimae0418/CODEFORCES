#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc,char **argv){
  vector<int> even,odd;
  int n,x,sum = 0;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> x;
    sum += x;
    if (x&1){
      odd.push_back(x);
    }else{
      even.push_back(x);
    }
  }
  sort(odd.begin(),odd.end());
  sort(even.begin(),even.end());
  if (even.size() == odd.size()){
    cout << 0 << endl;
  }else if (even.size() > odd.size()){
    int i,j;
    for (i = odd.size()-1,j = even.size()-1; i >= 0; i--,j--){
      sum -= (odd[i]+even[j]);
    }
    sum -= even[j];
    cout << sum << endl;
  }else{
    int i,j;
    for (i = odd.size()-1, j = even.size()-1; j >= 0; i--,j--){
      sum -= (odd[i]+even[j]);
    }
    sum -= odd[i];
    cout << sum << endl;
  }
  return 0;
}
