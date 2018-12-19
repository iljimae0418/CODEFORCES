#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[100005]; 
int main(){
	int n,k; 
	cin >> n >> k; 
	int flag = 0;  
	for (int i = 1; i <= k; i++){
		if (!flag){
			cout << i*2-1 << " " << i*2;  
		}else{
			cout << " " << i*2-1 << " " << i*2; 
		}
		flag = 1; 
	}
	for (int i = k+1; i <= n; i++){
		if (!flag) cout << i*2 << " " << i*2-1; 
		else cout << " " << i*2 << " " << i*2-1; 
		flag = 1;  
	}
	cout << endl; 
	return 0; 
}
