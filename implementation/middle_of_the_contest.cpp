#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main(int argc,char **argv){
  string s1,s2;
  string sh1,sm1,sh2,sm2;
  int dh = 0,dm = 0;
  char c; // :
  cin >> s1 >> s2;
  sh1 = s1.substr(0,2);
  sm1 = s1.substr(3);
  sh2 = s2.substr(0,2);
  sm2 = s2.substr(3);
  int h1 = 10*(sh1[0]-'0')+(sh1[1]-'0');
  int m1 = 10*(sm1[0]-'0')+(sm1[1]-'0');
  int h2 = 10*(sh2[0]-'0')+(sh2[1]-'0');
  int m2 = 10*(sm2[0]-'0')+(sm2[1]-'0');
  // find difference between the two times
  // half that difference
  // add that difference to h1:m1
  if (m1 > m2){
    dm = m2+60-m1;
    dh -= 1;
  }else if (m1 <= m2){
    dm = m2-m1;
  }
  dh += h2-h1;
  // the differences are guaranteed to be even
  int totalMin = (dh*60 + dm)/2;
  m1 += totalMin;
  while (m1 >= 60){
    m1 -= 60;
    h1++;
  }
  if (h1 <= 9){
    cout << "0" << h1 << ":";
  }else{
    cout << h1 << ":";
  }
  if (m1 <= 9){
    cout << "0" << m1 << "\n";
  }else{
    cout << m1 << "\n";
  }
  return 0;
}
