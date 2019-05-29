#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
int main(int argc,char **argv){
  ll a,b;
  scanf("%lld %lld",&a,&b);
  if (a == b){
    return !printf("0\n");
  }
  map<ll,ll> f1,f2;
  for (ll i = 2; i*i <= a; i++){
    while (a%i == 0){
      f1[i]++;
      a /= i;
    }
  }
  if (a != 1) f1[a]++;
  for (ll i = 2; i*i <= b; i++){
    while (b%i == 0){
      f2[i]++;
      b /= i;
    }
  }
  if (b != 1) f2[b]++;
  int moves = 0;
  int taken[6] = {0,0,0,0,0,0};
  for (map<ll,ll>::iterator it = f1.begin(); it != f1.end(); it++){
    ll x = it->first;
    if (x != 2 && x != 3 && x != 5){
      if (!f2.count(x) || f2[x] != f1[x]){
        return !printf("-1\n");
      }
    }else{
      taken[x] = 1;
      if (!f2.count(x)){
        moves += f1[x];
      }else{
        moves += abs(f1[x]-f2[x]);
      }
    }
  }
  for (map<ll,ll>::iterator it = f2.begin(); it != f2.end(); it++){
    ll x = it->first;
    if ((x == 2 || x == 3 || x == 5) && !taken[x]){
      moves += f2[x];
    }else if (x != 2 && x != 3 && x != 5){
      if (!f1.count(x) || f1[x] != f2[x]){
        return !printf("-1\n");
      }
    }
  }
  return !printf("%d\n",moves);
}
