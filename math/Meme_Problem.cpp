#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath> 
using namespace std; 

int main(){
	int t; 
	cin >> t; 
	cout.setf(ios::showpoint); 
	cout.setf(ios::fixed); 
	cout.precision(9); 
	while (t--){
		double d; 
		cin >> d; 
		if (d*d-4*d < 0){
			cout << "N" << endl; 
		}else{
			double a1 = (d+sqrt(d*d-4*d))/2.0;  
			double b1 = d-a1; 
			double a2 = (d-sqrt(d*d-4*d))/2.0; 
			double b2 = d-a2; 
			if (a1 >= 0 && b1 >= 0){
				cout << "Y " << a1 << " " << b1 << endl; 
			}else if (a2 >= 0 && b2 >= 0){
				cout << "Y " << a2 << " " << b2 << endl; 
			}else{
				cout << "N" << endl; 
			}
		}
	}
	return 0; 
}
