#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
  int n,k,ans = 1e9,q,r;  
  cin >> n >> k;  
  for (int i = 1; i*i <= n; i++){
    if (n%i == 0){
    	if (n/i < k && i < k){
	  r = max(n/i,i);  
          q = min(n/i,i);  
	}else if (n/i < k){
	  r = n/i; 
	  q = i;  
	}else if (i < k){
	  r = i; 
	  q = n/i;  
 	} 
    }
    ans = min(ans,k*q+r); 
  } 
  cout << ans << endl; 
  return 0; 
}
