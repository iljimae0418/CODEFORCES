#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> P;
const int MAXN = 1005;
const int INF = (int)1e9;
int a[MAXN],b[MAXN];
int main(int argc,char **argv){
  int n,k;
  scanf("%d %d",&n,&k);
  for (int i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  for (int i = 0; i < n; i++){
    scanf("%d",&b[i]);
  }
  priority_queue<P,vector<P>,greater<P> > pq;
  for (int i = 0; i < n; i++){
    pq.push(P(b[i]/a[i],i));
  }
  while (k){
    P p = pq.top(); pq.pop();
    int idx = p.second;
    // need to add val to b[idx] in order to bake one more cookie
    int val = a[idx]-b[idx]%a[idx];
    if (k >= val){
      k -= val;
      b[idx] += val;
    }else{
      k = 0;
      b[idx] += k;
    }
    pq.push(P(b[idx]/a[idx],idx));
  }
  int ans = INF;
  for (int i = 0; i < n; i++){
    ans = min(ans,b[i]/a[i]);
  }
  printf("%d\n",ans);
  return 0;
}
