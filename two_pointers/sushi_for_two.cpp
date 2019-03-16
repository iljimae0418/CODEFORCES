// this code is incorrect 
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int t[MAXN];
int eel = 0, tuna = 0;
int main(int argc, char **argv){
  int n;
  scanf("%d",&n);
  for (int i = 1; i <= n; i++){
    scanf("%d",&t[i]);
  }
  int l = 1, r = 1;
  int change = 0, idx = 0,maxlen = 0;
  while (l <= n){
    while (r <= n && change < 2){
      if (r > 1 && t[r-1] != t[r]){
        if (change == 0) idx = r-1;
        change++;
      }
      if (t[r] == 1) tuna++;
      else if (t[r] == 2) eel++;
      if (tuna == eel) maxlen = max(maxlen,r-l+1);  
      r++;
    }
    if (eel == tuna) maxlen = max(maxlen,r-l);
    if (t[l] == 1) tuna--;
    else if (t[l] == 2) eel--;
    if (l == idx) change--;
    l++;
  }
  return !printf("%d\n",maxlen);
}
