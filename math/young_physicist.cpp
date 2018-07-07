#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;  
int a[101][3];  
int main(){
	int n,x = 0,y = 0,z = 0; 
	cin >> n;  
	for (int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2]; 
		x += a[i][0], y += a[i][1], z += a[i][2];  
	}
	if (x == 0 && y == 0 && z == 0) cout << "YES" << endl; 
	else cout << "NO" << endl; 
	return 0; 
}
