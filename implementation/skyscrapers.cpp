#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int MAXN = 1005;
const int MAXM = 1005;
int a[MAXN][MAXM];
int rsize[MAXN];
int csize[MAXM];
int kr[MAXN],kc[MAXM];
vector<int> rpos[MAXN],cpos[MAXM];
int main(int argc,char **argv){
  int n,m;
  scanf("%d %d",&n,&m);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      scanf("%d",&a[i][j]);
    }
  }
  // investigate rows
  for (int i = 0; i < n; i++){
    set<int> st;
    for (int j = 0; j < m; j++){
      st.insert(a[i][j]);
    }
    for (set<int>::iterator it = st.begin(); it != st.end(); it++){
      rpos[i].push_back(*it);
    }
    rsize[i] = st.size();
  }
  // investigate columns
  for (int i = 0; i < m; i++){
    set<int> st;
    for (int j = 0; j < n; j++){
      st.insert(a[j][i]);
    }
    for (set<int>::iterator it = st.begin(); it != st.end(); it++){
      cpos[i].push_back(*it);
    }
    csize[i] = st.size();
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      int rel_r_pos = lower_bound(rpos[i].begin(),rpos[i].end(),a[i][j])-rpos[i].begin()+1;
      int rel_c_pos = lower_bound(cpos[j].begin(),cpos[j].end(),a[i][j])-cpos[j].begin()+1;
      int Gr = rsize[i]-rel_r_pos;
      int Lr = rsize[i]-Gr-1;
      int Gc = csize[j]-rel_c_pos;
      int Lc = csize[j]-Gc-1;
      printf("%d ",max(Lr,Lc)+1+max(Gr,Gc)); 
    }
    puts("");
  }
  return 0;
}
