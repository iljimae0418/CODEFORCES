#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	if (n%2 == 0){
		cout << 3*(n/2) << endl; 
	}else{
		cout << (n-1)/2 + (n+1)/2 + (n-1)/2 << endl; 
	}
	for (int i = 2; i <= n; i += 2){
		cout << i << " "; 
	}
	for (int i = 1; i <= n; i += 2){
		cout << i << " "; 
	}
	for (int i = 2; i <= n; i += 2){
		cout << i << " "; 
	}
	cout << endl;
	return 0; 
}
