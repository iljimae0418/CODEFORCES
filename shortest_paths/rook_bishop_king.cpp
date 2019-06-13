#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
// moves for rook, bishop and king
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(int argc,char **argv){
  IOFAST();
  int r1,c1,r2,c2;
  cin >> r1 >> c1 >> r2 >> c2;
  int rook = 0, bishop = 0, king = 0;
  // rook moves
  if (r1 == r2 || c1 == c2){
    rook = 1;
  }else{
    rook = 2;
  }
  // bishop moves
  if (abs(r1-r2) == abs(c1-c2)){
    bishop = 1;
  }else if ((abs(r1-r2)+abs(c1-c2))%2 == 0){
    bishop = 2;  
  }
  // king moves
  king = max(abs(r1-r2),abs(c1-c2));
  cout << rook << " " << bishop << " " << king << "\n";
  return 0;
}
