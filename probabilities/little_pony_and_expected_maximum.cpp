#include <iostream>
#include <cstdlib>
#include <cmath> // pow()
#include <algorithm>
using namespace std; 
int main(int argc,char **argv){
	double m,n;  
	cin >> m >> n;  
	double ans = 0; 
	for (double i = 1; i <= m; i++){
		ans += i*(pow(i/m,n) - pow((i-1)/m,n));  
	}
	cout.setf(ios::showpoint); 
	cout.setf(ios::fixed); 
	cout.precision(12); 
	cout << ans << endl; 
	return 0; 
}
