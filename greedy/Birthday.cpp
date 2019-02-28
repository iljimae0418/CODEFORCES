#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int MAXN = 111;
int n;
int a[MAXN];
int main(int argc,char **argv){
  cin >> n;
  map<int,int> mp;
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a+1,a+n+1);
  vector<int> p1,p2;
  for (int i = 1; i <= n; i++){
    if (i&1) p1.push_back(a[i]);
    else p2.push_back(a[i]);
  }
  for (int i = 0; i < p1.size(); i++){
    cout << p1[i] << " ";
  }
  for (int i = p2.size()-1; i >= 0; i--){
    cout << p2[i] << " ";
  }
  cout << endl;
  return 0;
}
