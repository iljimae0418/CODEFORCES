#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int x[55],y[55];
int main(){
	int n,sumx = 0,sumy = 0; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> x[i]; 
		sumx += x[i]; 
	}
	for (int i = 0; i < n; i++){
		cin >> y[i]; 
		sumy += y[i]; 
	}
	if (sumy <= sumx) cout << "Yes" << endl; 
	else cout << "No" << endl; 
	return 0;  
}  
