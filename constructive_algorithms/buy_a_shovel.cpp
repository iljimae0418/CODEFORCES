#include <iostream>
#include <cstdlib> 
using namespace std; 
int main(){
	int k,r; 
	cin >> k >> r; 
	int x;   
	for (x = 1;;x++){
		if ((x*k-r)%10 == 0 || x*k%10 == 0){
			cout << x << endl; 
			break; 
		}
	}
	return 0;  
}
