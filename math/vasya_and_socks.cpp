#include <iostream>
using namespace std; 
int main(){
	int n,m,left,cnt = 0;   
	cin >> n >> m;  
	left = n;  
	for (int i = 1; left >= 1; i++){
		left--;  
		if (i%m == 0) left++; 
		cnt++; 
	}
	cout << cnt << endl; 
	return 0; 
}
