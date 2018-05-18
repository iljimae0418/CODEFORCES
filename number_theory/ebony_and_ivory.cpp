#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 

int main(){
	int a,b,c; 
	cin >> a >> b >> c; 
	bool can = false; 
	for (int x = 0; a*x <= c; x++){
		if ((c-a*x)%b == 0){
			can = true; 
			cout << "Yes" << endl; 
			break; 
		}
	}
	if (!can) cout << "No" << endl; 
	return 0; 
}
