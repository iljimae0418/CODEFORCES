#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std; 
bool isPrime(int x){
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0) return false;  
	}
	return x != 1;  
}
int main(){ 
	int n; 
	cin >> n; 
	for (int i = 2; i <= n; i++){
		if (!isPrime(i) && !isPrime(n-i)){
			cout << i << " " << n-i << endl; 
			break; 
		}
	}
	return 0; 
}
