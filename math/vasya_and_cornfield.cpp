#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n,d; 
	cin >> n >> d; 
	int m; 
	cin >> m;  
	while (m--){
		int a,b; 
		cin >> a >> b; 
		int k1 = -a+2*n-d; 
		int k2 = -a+d; 
		int k3 = a+d; 
		int k4 = a-d; 
		if (b >= min(k1,k2) && b <= max(k1,k2) && 
			b >= min(k3,k4) && b <= max(k3,k4)){
			cout << "YES" << endl; 
		}else{
			cout << "NO" << endl; 
		}
	}
	return 0; 
}
