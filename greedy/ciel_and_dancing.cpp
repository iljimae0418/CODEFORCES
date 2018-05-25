#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n,m; 
	cin >> n >> m; 
	cout << m + (n-1) << endl; 
	for (int i = 1; i <= n; i++){
		if (i == 1){
			for (int j = 1; j <= m; j++){
				cout << i << " " << j << endl; 
			}
		}else{
			cout << i << " " << 1 << endl; 
		}
	}
	return 0; 
}
