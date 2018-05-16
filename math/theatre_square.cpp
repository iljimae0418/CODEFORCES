#include <iostream>
#include <cstdlib>
#include <cmath> 
using namespace std; 
typedef long long ll;  
int main(){
	ll n,m,a; 
	cin >> n >> m >> a;
	cout << ((n+a-1)/a) * ((m+a-1)/a) << endl; 
	return 0; 
}
