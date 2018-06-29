#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;  
int main(){
	double a,b,c,d;  
	cin >> a >> b >> c >> d;  
	double x = (1.0 - a/b)*(1.0 - c/d);  
	double ans = (a/b)*(1/(1-x));  
	cout.setf(ios::showpoint);  
	cout.setf(ios::fixed); 
	cout.precision(12); 
	cout << ans << endl; 
	return 0; 
}
