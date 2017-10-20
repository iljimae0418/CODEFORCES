#include <iostream>
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	int a,b,c;  
	cin >> a >> b >> c; 
	if (n == 1){
		cout << 0 << endl; 
	}else if (n > 1){ // n > 1 
		int minval = min(a,min(b,c)); 
		if (minval == a){
			cout << a*(n-1) << endl; 
		}else if (minval == b){
			cout << b*(n-1) << endl; 
		}else{
			cout << min(a,b)+minval*(n-2) << endl; 
		}
	}
	return 0; 
}
