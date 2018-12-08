#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
int main(){
	typedef long long ll; 
	ll x,y; 
	cin >> x >> y; 
	if (y == 0){
		cout << "No" << endl; 
		return 0;  
	}else if (y == 1 && x > 0){
		cout << "No" << endl; 
		return 0;  
	}
	// we can always make original 
	ll d = x-(y-1);   
	if (d < 0){
		cout << "No" << endl; 
		return 0; 
	}
	if (d%2 != 0){
		cout << "No" << endl; 
		return 0;  
	}
	cout << "Yes" << endl; 
	return 0; 
}
