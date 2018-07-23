#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n,cnt = 0; 
	cin >> n; 
	int a[5] = {1,2,3,4,5}; 
	for (int i = 4; i >= 0; i--){
		cnt += n/a[i];  
		n -= (n/a[i])*a[i]; 
	}
	cout << cnt << endl; 
	return 0; g
}
