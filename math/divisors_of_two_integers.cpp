#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector> 
using namespace std; 
int a[130],mark[130],seen[10005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n); 
	int x = a[n-1]; // the largest number has to be oeither x or y
	for (int i = 0; i < n; i++){
		if (x%a[i] == 0 && !seen[a[i]]){
			seen[a[i]] = 1; 
			mark[i] = 1; 
		}
	}
	int y = -1; 
	for (int i = 0; i < n; i++){
		if (!mark[i]){
			y = max(y,a[i]); 
		}
	}
	if (y == -1) y = x; 
	cout << x << " " << y << endl; 
	return 0; 
}
