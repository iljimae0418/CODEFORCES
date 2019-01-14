#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <algorithm> 
using namespace std; 
const double PI = 3.141592653589793238462643383279502884197;  
int main(int argc,char **argv){
	double n,r;
	cin >> n >> r;  
	double x = (360.0/n)*(PI/180.0);  
	double k = sqrt(4*r*r*(cos(x)-1)*(cos(x)-1) - 4*(1+cos(x))*(r*r*(cos(x)-1))); 
	double R = (-2*r*(cos(x)-1) + k)/(2*(1+cos(x))); 
	cout.setf(ios::showpoint); 
	cout.setf(ios::fixed); 
	cout.precision(7);  
	cout << R << endl;    
	return 0;  
}
