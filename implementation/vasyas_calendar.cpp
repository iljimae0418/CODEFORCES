#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[2005]; 
int main(int argc,char **argv){
	int d,n,clicks = 0; 
	cin >> d >> n; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
	}
	for (int i = 1; i <= n; i++){
		if (i == n) continue;  
		clicks += d-a[i];  
	}
	cout << clicks << "\n"; 
	return 0; 
}
