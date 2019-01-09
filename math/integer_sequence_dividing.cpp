#include <iostream>
using namespace std; 
typedef long long ll; 
int main(){
	ll n; 
	cin >> n; 
	ll sum = n*(n+1)/2LL; 
	if (sum % 2 == 0){
		cout << 0 << endl; 
	}else{
		cout << 1 << endl; 
	}
	return 0;  
}
