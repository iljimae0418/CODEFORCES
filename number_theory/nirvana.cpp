#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc,char **argv){
  int n;
  cin >> n;
  vector<int> a;
  while (n){
    a.push_back(n%10);
    n /= 10;
  }
  reverse(a.begin(),a.end());
  int maxProduct = 1;
  for (int i = 0; i < a.size(); i++){
    maxProduct *= a[i];
  }
  int len = a.size();
  for (int i = len-2; i >= 0; i--){
    if (i == 0){
      int product = 1;
      if (a[i] >= 2){
        product *= a[i]-1;
        for (int j = 1; j < len; j++){
          product *= 9;
        }
      }else{
        for (int j = 1; j < len; j++){
          product *= 9;
        }
      }
      maxProduct = max(maxProduct,product);
    }else{
      if (a[i] >= 2){
        int product = 1;
        for (int j = 0; j <= i-1; j++){
          product *= a[j];
        }
        product *= (a[i]-1);
        for (int j = i+1; j < len; j++){
          product *= 9;
        }
        maxProduct = max(maxProduct,product);
      }
    }
  }
  cout << maxProduct << endl;
  return 0;
}
