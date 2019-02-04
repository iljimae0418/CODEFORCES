#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm> 
#include <vector> 
using namespace std; 
#define HALF_MAXN 100005 
typedef long long ll;  
ll b[HALF_MAXN];
int main(int argc,char **argv){
  int n; 
  scanf("%d",&n); 
  for (int i = 1; i <= n/2; i++){
    scanf("%lld",b+i);  
  } 
  vector<ll> fh,sh; // first half, second half 
  ll p1 = -1, p2 = -2; 
  for (int i = 1; i <= n/2; i++){
    if (i == 1){
      fh.push_back(0); 
      sh.push_back(b[1]); 
      p1 = 0; 
      p2 = b[1]; 
    }else if (i > 1){
      ll k = max(b[i]-p2,p1); 
      fh.push_back(k); 
      sh.push_back(b[i]-k);  
      p1 = k;  
      p2 = b[i]-k;  
    } 
  } 
  for (int i = 0; i < fh.size(); i++){
    printf("%lld ",fh[i]); 
  } 
  for (int i = sh.size()-1; i >= 0; i--){
    printf("%lld ",sh[i]);  
  } 
  puts(""); 
  return 0;  
} 
