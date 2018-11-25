#include <iostream>
using namespace std; 
int main(){
	typedef long long ll; 
	int t; 
	cin >> t; 
	while (t--){
		ll a,b,k; 
		cin >> a >> b >> k;  
		if (k%2 == 0){
			cout << (k/2)*a - (k/2)*b << "\n"; 
		}else{
			cout << ((k-1)/2 + 1)*a - ((k-1)/2)*b << "\n"; 
		}
	}
	return 0; 
}
