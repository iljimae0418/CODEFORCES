#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std;  
// algorithm: 
// if x[i] == y[i]: we let z[i] >= x[i] 
// if x[i] < y[i]: -1, because the result must've been x[i] but it's not 
// if x[i] > y[i]: z[i] = y[i] 
int main(){
	string x,y,z = ""; 
	cin >> x >> y; 
	for (int i = 0; i < x.size(); i++){
		if (x[i] == y[i]){
			z += x[i]; 
		}else if (x[i] < y[i]){
			cout << -1 << endl; 
			return 0;  
		}else if (x[i] > y[i]){
			z += y[i]; 
		}
	}
	cout << z << endl; 
	return 0; 
}
