#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[101]; 
int main(){
	int n; 
	cin >> n; 
	double sum = 0; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		sum += a[i];  
	}
	double ans = sum/(double)n;  
	cout.setf(ios::showpoint); 
	cout.setf(ios::fixed); 
	cout.precision(15); 
	cout << ans << endl; 
	return 0; 
}
