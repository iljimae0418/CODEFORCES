#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	typedef long long ll; 
	ll n; 
	cin >> n;  
	if (n%2 == 0){
		cout << n/2 << endl; 
	}else{
		cout << n/2 - n << endl; 
	}
	return 0; 
}
