#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[101]; 
int main(){
	int n; 
	cin >> n; 
	int sum = 0; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		sum += a[i]; 
	}
	sort(a,a+n,greater<int>()); 
	int my = 0,i; 
	for (i = 0; i < n; i++){
		my += a[i]; 
		sum -= a[i]; 
		if (my > sum) break; 
	}
	cout << i+1 << endl; 
	return 0; 
}
