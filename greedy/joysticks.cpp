#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int main(){
	int a,b; 
	cin >> a >> b; 
	if (a == 1 && b == 1){
		cout << 0 << endl; 
		return 0; 
	}
	int cnt = 0; 
	while (a > 0 && b > 0){
		if (a >= b){
			a -= 2; 
			b++; 
		}else{
			a++; 
			b -= 2; 
		}
		cnt++; 
	}
	cout << cnt << endl; 
	return 0; 
}
