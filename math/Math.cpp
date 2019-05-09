#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
bool power_of_2(int x){
  return (x != 0 && (x & (x-1)) == 0);
}
int main(int argc,char **argv){
  int n;
  scanf("%d",&n);
  if (n == 1){
    return !printf("1 0\n");  
  }
  // we prime factorize n
  map<int,int> mp;
  for (int i = 2; i*i <= n; i++){
    while (n%i == 0){
      mp[i]++;
      n /= i;
    }
  }
  if (n != 1) mp[n]++;
  // find maximum exponent
  int x = 0,ans = 1;
  set<int> st;
  for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
    x = max(x,it->second);
    st.insert(it->second);
    ans *= it->first;
  }
  if (x == 1){
    return !printf("%d 0\n",ans);
  }
  // we can multiply just once to make all the numbers with the equal exponent x and power of 2
  // afterwards, we take the sqrt log(x) times
  int cnt = (st.size() == 1 && power_of_2(x) ? 0 : 1), y = 1;
  while (y < x){
    y <<= 1;
    cnt++;
  }
  printf("%d %d\n",ans,cnt);
  return 0;
}
