#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int q,x; 
	cin >> q; 
	while (q--){
		cin >> x; 
		if (x%2 == 0){
			cout << x/2 << endl; 
		}else{
			cout << 1+(x-3)/2 << endl;  
		}
	}
	return 0; 
}
