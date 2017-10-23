#include <iostream>
#include <cstdlib>
using namespace std; 
const int pw = 1<<17; 
int main(){
	int n,x; 
	cin >> n >> x; 
	if (n == 2 && x == 0){
		cout << "NO" << endl; 
	}else{
		if (n == 1){
			cout << "YES" << endl; 
			cout << x << endl; 
		}else if (n == 2){
			cout << "YES" << endl; 
			cout << 0 << " " << x << endl; 
		}else{
			cout << "YES" << endl; 
			int cmp = 0; 
			for (int i = 1; i <= n-3; i++){
				cmp ^= i; 
			}
			if (cmp == x){
				for (int i = 1; i <= n-3; i++){
					cout << i << " "; 
				}
				cout << pw << " " << pw*2 << " " << (pw^(pw*2)) << endl; 
			}else{
				for (int i = 1; i <= n-3; i++){
					cout << i << " "; 
				}
				cout << 0 << " " << pw << " " << (pw^x^cmp) << endl; 
			}
		}
	}
	return 0; 
}
