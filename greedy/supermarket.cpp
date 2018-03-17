#include <iostream>
#include <algorithm>
using namespace std; 
int main(){
	int n; 
	double m; 
	cin >> n >> m; 
	double minval = 191919191;  
	for (int i = 0; i < n; i++){
		double a,b; 
		cin >> a >> b; 
		minval = min(minval,a/b); 
	}	
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(8); 
	cout << minval*m << endl; 
	return 0;  	
}
