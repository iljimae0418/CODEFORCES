#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;  
typedef long long ll; 
int main(){
	ll a,b; 
	cin >> a >> b; 	
	while (true){ 
		if (a == 0 || b == 0) break; 
		if (a >= 2*b){
			ll k = a/(2*b); 
			a -= k*2*b;  
		}else if (b >= 2*a){
			ll k = b/(2*a); 
			b -= k*2*a;  
		}else break; 
	}
	cout << a << " " << b << endl;
	return 0; 
}
