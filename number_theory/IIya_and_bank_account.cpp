#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	if (n > 0){
		cout << n << endl;
		return 0; 
	}
	n *= -1;  
	int k1 = n%10, k2 = n%100; 
	k2 /= 10;  
	//cout << k1 << " " << k2 << endl; 
	if (k1 > k2){
		// delete k1 
		n /= 10; 
		cout << -n << endl; 
	}else{
		// delete k2 
		n /= 100;  
		n = n*10+k1;  
		cout << -n << endl; 
	}
	return 0;  
}
