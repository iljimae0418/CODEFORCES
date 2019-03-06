#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<int,int> P;
const int MAXN = 5005;
const int INF = 987654321;
P a[MAXN];
int freq[MAXN],pa2[MAXN],pa3[MAXN];
vector<int> v;
int main(){
  IOFAST();
  int n,q,total = 0;
  cin >> n >> q;
  for (int i = 0; i < q; i++){
    cin >> a[i].first >> a[i].second;
    for (int j = a[i].first; j <= a[i].second; j++){
      freq[j]++;
    }
  }
  for (int i = 1; i <= n; i++){
    if (freq[i]) total++;
    pa2[i] = pa2[i-1]+(freq[i] >= 2);
    pa3[i] = pa3[i-1]+(freq[i] >= 3);
  }
  int minval = INF;
  for (int i = 0; i < q; i++){
    for (int j = i+1; j < q; j++){
      int t = 0;
      int u1 = a[i].first, v1 = a[i].second;
      int u2 = a[j].first, v2 = a[j].second;
      if (u1 > v2 || u2 > v1){
        // no overlaps
        t += (v1-u1+1)-(pa2[v1]-pa2[u1-1]);
        t += (v2-u2+1)-(pa2[v2]-pa2[u2-1]);
      }else if (u1 <= u2 && v2 <= v1){
        // [u2,v2] is the overlapping region
        t += (v2-u2+1)-(pa3[v2]-pa3[u2-1]);
        // [u1,u2-1], [v2+1,v1] are non overlapping regions
        if (u2-1 >= u1) t += (u2-u1)-(pa2[u2-1]-pa2[u1-1]);
        if (v2+1 <= v1) t += (v1-v2)-(pa2[v1]-pa2[v2]);
      }else if (u2 <= u1 && v1 <= v2){
        // [u1,v1] is the overlapping region
        t += (v1-u1+1)-(pa3[v1]-pa3[u1-1]);
        // [u2,u1-1], [v1+1,v2] are non overlapping regions
        if (u1-1 >= u2) t += (u1-u2)-(pa2[u1-1]-pa2[u2-1]);
        if (v1+1 <= v2) t += (v2-v1)-(pa2[v2]-pa2[v1]);
      }else if (u2 >= u1 && v1 <= v2 && u2 <= v1){
        // [u2,v1] is the overlapping region
        t += (v1-u2+1)-(pa3[v1]-pa3[u2-1]);
        // [u1,u2-1],[v1+1,v2] are non overlapping regions
        if (u2-1 >= u1) t += (u2-u1)-(pa2[u2-1]-pa2[u1-1]);
        if (v1+1 <= v2) t += (v2-v1)-(pa2[v2]-pa2[v1]);
      }else if (u1 >= u2 && v2 <= v1 && u1 <= v2){
        // [u1,v2] is the overlapping region
        t += (v2-u1+1)-(pa3[v2]-pa3[u1-1]);
        // [u2,u1-1],[v2+1,v1] are non overlapping regions
        if (u2 <= u1-1) t += (u1-u2)-(pa2[u1-1]-pa2[u2-1]);
        if (v2+1 <= v1) t += (v1-v2)-(pa2[v1]-pa2[v2]);
      }
      minval = min(minval,t);
    }
  }
  cout << total-minval << "\n";
  return 0;
}
