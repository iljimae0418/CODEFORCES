#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
// idea: decompose the number into sum of prime numbers  
// because the prime numbers have factors only 1 and itself  
// this means for a part n_i (which is prime), we only have to pay 1 burles 
bool isPrime(int x){
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0) return false; 
	}
	return x != 1;  
}
int main(){
	int n; // verified at least up to 40,000,000,000 
	cin >> n; 
	if (isPrime(n)){
		cout << 1 << endl; 
	}else if (n%2 == 0){ // all even numbers can be expressed as a sum of two primes 
		cout << 2 << endl; 
	}else{ // n is odd 
		if (isPrime(n-2)){
			cout << 2 << endl; 
		}else{ // all odd numbers can be expressed as a sum of three primes 
			cout << 3 << endl; 
		}
	}
	return 0; 
}
