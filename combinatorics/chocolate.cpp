#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
long long result = 0;  
int main(){
	int n; 
	cin >> n; 
	int prev = -1;  
	for (int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		if (x == 1){
			if (prev == -1) result = 1; 
			else result *= i-prev; 
			prev = i;  
		}
	}
	cout << result << endl; 
	return 0; 
}
