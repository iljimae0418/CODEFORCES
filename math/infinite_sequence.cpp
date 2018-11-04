#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	long long a,b,c; 
	cin >> a >> b >> c; 
	if (c == 0){
		cout << (a == b ? "YES" : "NO") << endl; 
	}else if (c > 0 && b < a){
		cout << "NO" << endl; 
	}else if (c < 0 && a < b){
		cout << "NO" << endl; 
	}else{
		cout << ((b-a)%c == 0 ? "YES" : "NO") << endl; 
	}
	return 0; 
}
