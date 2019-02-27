#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc,char **argv){
  typedef long long ll;
  ll w1,h1,w2,h2;
  cin >> w1 >> h1 >> w2 >> h2;
  cout << (w1+h1+h1+2)+(w2+h2+h2+2)+(w1-w2) << endl;  
  return 0;
}
