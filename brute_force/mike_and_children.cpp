#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int MAXN = 1005;
int a[MAXN];
int main(int argc,char **argv){
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++){
    scanf("%d",a+i);  
  }
  map<int,int> mp;
  for (int i = 0; i < n; i++){
    for (int j = i+1; j < n; j++){
      mp[a[i]+a[j]]++;
    }
  }
  int maxnum = 0;
  for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
    maxnum = max(maxnum,it->second);
  }
  return !printf("%d\n",maxnum);
}
