#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+5;
const int MAXM = 1e7+7;
int prime[MAXM];
vector<int> primes;
int cnt = 0;
void eratos(){
  for (int i = 0; i < MAXM; i++){
    prime[i] = 1;
  }
  prime[0] = prime[1] = 0;
  for (ll i = 2; i < MAXM; i++){
    if (prime[i]){
      primes.push_back(i);
      for (ll j = i*i; j < MAXM; j += i){
        prime[j] = 0;
      }
    }
  }
}
int main(int argc,char **argv){
  int n;
  scanf("%d",&n);
  eratos();
  for (int i = 0; i < n; i++){
    printf("%d ",primes[i]);
  }
  puts(""); 
  return 0;
}
