#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n,m; 
	cin >> n >> m;  
	cout << min(n,m)+1 << endl;   
	for (int i = 0, k = min(n,m); i < min(n,m)+1; i++,k--){
		cout << i << " " << k << endl; 
	}
	return 0;  
}
