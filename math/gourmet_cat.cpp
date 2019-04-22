#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  int a,b,c;
  cin >> a >> b >> c;
  int full = min(a/3,min(b/2,c/2));
  a -= 3*full;
  b -= 2*full;
  c -= 2*full;
  int ans = 7*full;
  for (int start = 0; start <= 6; start++){
    int add = 0;
    int ta = a, tb = b, tc = c;
    for (int k = start;;k++){
      if (k == 7){
        k = 0;
      }
      if (k == 0 || k == 3 || k == 6){
        if (ta > 0){
          ta--;
          add++;
        }else if (ta == 0){
          break;
        }
      }else if (k == 1 || k == 5){
        if (tb > 0){
          tb--;
          add++;
        }else if (tb == 0){
          break;
        }
      }else if (k == 2 || k == 4){
        if (tc > 0){
          tc--;
          add++;
        }else if (tc == 0){
          break;
        }
      }
    }
    ans = max(ans,7*full+add);
  }
  cout << ans << "\n";
  return 0;
}
