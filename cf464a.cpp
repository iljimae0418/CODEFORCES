#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;  
int f[5005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 1; i <= n; i++){
		cin >> f[i]; 
	}
	bool flag = false;  
	for (int i = 1; i <= n; i++){
		if (f[f[f[i]]] == i){
			flag = true; 
			break; 
		}
	}
	if (flag) cout << "YES" << endl; 
	else cout << "NO" << endl; 
	return 0; 
}
