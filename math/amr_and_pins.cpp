#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <algorithm>
using namespace std; 
int main(){
	double r,x,y,gx,gy;  
	cin >> r >> x >> y >> gx >> gy;  
	double d = sqrt((gx-x)*(gx-x) + (gy-y)*(gy-y));  
	cout << ceil(d/(2*r)) << endl; 
	return 0; 
}
