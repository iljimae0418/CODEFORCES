#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <cmath> 
#include <algorithm>
using namespace std; 
int a[111]; 
int closed[111];  
int main(){
	int n,k; 
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	int maxval = 0;  
	for (int b = 1; b <= n; b++){
		memset(closed,0,sizeof(closed)); 
		int l = (1-b)/k; 
		int r = (n-b)/k;   
		int e = 0, s = 0;  
		for (int i = l; i <= r; i++){
			closed[b+i*k] = 1;  
		}
		for (int i = 1; i <= n; i++){
			if (!closed[i] && a[i] == 1) e++;  
			else if (!closed[i] && a[i] == -1) s++;  
		}
		maxval = max(maxval,abs(e-s)); 
	}
	cout << maxval << endl;
	return 0;  
}
