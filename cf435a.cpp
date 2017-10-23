// mex : min non-negative 
#include <iostream>
#include <algorithm>
using namespace std; 
int a[101],present[101]; 
int main(){
	int n,x; 
	cin >> n >> x; 
	int maxval = 0; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
		present[a[i]] = 1;  
		maxval = max(maxval,a[i]);  
	}
	int cnt = 0; 
	if (present[x]){
		// take out x 
		cnt++; 
	}
	for (int i = 0; i < x; i++){
		if (!present[i]){
			// put in i < x
			cnt++; 
		}
	}
	cout << cnt << endl; 
	return 0;  
}
