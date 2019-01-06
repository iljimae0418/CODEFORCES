#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <algorithm>
using namespace std;  
int main(){
	int n; 
	cin >> n; 
	if (n == 1) cout << 2 << endl; 
	else if (n == 2) cout << 3 << endl; 
	else{
		int k = sqrt(n); 
		int l = ceil((double)n/k);  
		cout << l+k << endl; 
	}
	return 0;  
}
