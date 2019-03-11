#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main(int argc,char **argv){
  int n,k,cnt = 0;
  scanf("%d %d",&n,&k);
  if (k-1 <= n-k){
    // throw the stone on kth manhole to k+1 th manhole
    cnt++;
    // open and pick the coin on the kth manhole
    cnt++;
    // move left k-1 times and repeat the step of throwing the stone
    // to the kth manhole, then picking up the stone.
    cnt += 3*(k-1);
    // move right all the way to the k+1 th manhole
    cnt += k;
    // throw two stones to the kth manhole
    cnt += 2;
    // open the k+1 th manhole and pick up coin
    cnt++;
    // move right n-k-1 times and repeat the step of throwing the stone
    // to the kth manhole, then picking up the stone
    cnt += 3*(n-k-1);
  }else{
    // throw the stone on kth manhole to k-1th manhole
    cnt++;
    // pick up coin on the kth manhole
    cnt++;
    // move right n-k times
    cnt += 3*(n-k);
    // move left all the way to the k-1th manhole
    cnt += (n-k+1);
    // throw two stones to kth manhole
    cnt += 2;
    // open k-1 th manhole and pick up the coin
    cnt++;
    // move left to the 1st manhole
    cnt += 3*(k-2);
  }
  return !printf("%d\n",cnt);
}
