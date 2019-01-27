#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int t[100005];  
int main(){
  int n; 
  cin >> n; 
  for (int i = 0; i < n; i++){
    cin >> t[i];  
  } 
  if (n == 1){
  	cout << "1 0" << endl; 
  	return 0; 
  }
  int l = 0, r = n-1, Acnt = 0, Bcnt = 0;  
  while (l < r){
  	//cout << t[r] << " " << Bcnt << endl; 
    bool Amove = false, Bmove = false; 
	if (t[l] == t[r]){
	  t[l] = t[r] = 0;  
	  Acnt++; 
	  Bcnt++; 
	  l++; 
	  r--;  
	  Amove = Bmove = true; 
	}else if (t[l] < t[r]){
	  t[r] -= t[l]; 
	  t[l] = 0;  
	  Acnt++;  
	  l++; 
	  Amove = true; 
	  if (l == r){
	  	Bcnt++; 
	  	break; 
	  }
	}else if (t[l] > t[r]){
	  t[l] -= t[r];  
	  t[r] = 0;  
	  Bcnt++;  
	  r--; 
	  Bmove = true; 
	  if (l == r){
	  	Acnt++; 
	  	break; 
	  }
	}
	if (l == r && Amove && Bmove){
	  Acnt++;  
	  break; 
	}
  }
  cout << Acnt << " " << Bcnt << endl;
  return 0; 
} 

