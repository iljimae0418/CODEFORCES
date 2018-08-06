#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath> 
using namespace std;  
int main(){
	typedef long long ll; 
	ll x,y; 
	cin >> x >> y;  
	if (y*log(x) > x*log(y)){
		cout << ">" << endl; 
	}else if (y*log(x) < x*log(y)){
		cout << "<" << endl; 
	}else{
		cout << "=" << endl; 
	}
	return 0; 
}
