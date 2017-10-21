#include <iostream>
#include <cmath> 
#include <cstdlib>
#include <algorithm> 
using namespace std;  
typedef long long ll;  
int main(){
	ll a,b; 
	cin >> a >> b;  
	// b!/a! = (a+1)(a+2)...(b) 
	ll prod = 1; 
	for (ll i = a+1; i <= b; i++){
		// this will iterate at most 10 times only 
		prod *= i;  
		prod %= 10;  
		if (prod == 0){
			break; 
		}
	}
	cout << prod << endl;
	return 0; 
}
