#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  

int main(){
	int n1,n2,k1,k2; 
	cin >> n1 >> n2 >> k1 >> k2; 
	if (n1 == n2){
		cout << "Second" << endl; 
	}else{
		cout << (n1 > n2 ? "First" : "Second") << endl; 
	}
	return 0;  
}
