#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm>
#include <vector> 
using namespace std; 
int main(int argc,char **argv){
  int q,l1,r1,l2,r2;  
  scanf("%d",&q); 
  while (q--){
    scanf("%d %d %d %d",&l1,&r1,&l2,&r2); 
    if (l1 <= l2 && r2 <= r1){
      printf("%d %d\n",l1,r2); 
    }else if (l2 <= l1 && r1 <= r2){
      printf("%d %d\n",r1,l2);  
    }else if (l1 == r2){
      printf("%d %d\n",r1,l2); 
    }else if (r1 == l2){
      printf("%d %d\n",l1,r2); 
    }else{
      // no overlap
      printf("%d %d\n",l1,l2); 
    }
  }
  return 0; 
} 
