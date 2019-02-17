#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 2e5+5;
char s[MAXN];
int main(int argc,char **argv){
  int n,cnt = 0;
  scanf("%d",&n);
  for (int i = 0; i < n; i++){
    scanf(" %c",&s[i]);
  }
  for (int i = 0; i+1 < n; i++){
    char x[3] = {'R','G','B'};
    if (s[i] == s[i+1]){
      cnt++;
      if (i+2 < n && s[i+1] == s[i+2]){
        // we change index i+1
        for (int j = 0; j < 3; j++){
          if (s[i] != x[j] && s[i+2] != x[j]){
            s[i+1] = x[j];
            break;
          }
        }
      }else{
        // we change index i
        for (int j = 0; j < 3; j++){
          if (i-1 >= 0 && s[i-1] != x[j] && s[i+1] != x[j]){
            s[i] = x[j];
            break;
          }else if (i == 0 && s[i+1] != x[j]){
            s[i] = x[j];
            break;
          }
        }
      }
    }
  }
  printf("%d\n",cnt);
  printf("%s\n",s);
  return 0;
}
