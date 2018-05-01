#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int factorial(int x){
	if (x == 0 || x == 1) return 1; 
	return x*factorial(x-1); 
}
int main(){
	int a,b; 
	cin >> a >> b; 
	cout << factorial(min(a,b)) << endl; 
	return 0; 
}
