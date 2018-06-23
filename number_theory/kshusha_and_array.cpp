#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int a[100005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n); 
	for (int i = 1; i < n; i++){
		if (a[i]%a[0] != 0){
			cout << -1 << endl; 
			return 0;  
		}
	}
	cout << a[0] << endl; 
	return 0; 
}
