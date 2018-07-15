#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std;  
int c[1001]; 
int a[1001]; 
int main(){
	int n,m; 
	cin >> n >> m;  
	for (int i = 1; i <= n; i++){
		cin >> c[i]; 
	}
	for (int i = 1; i <= m; i++){
		cin >> a[i]; 
	}
	int num = 1,idx = 1;  
	while (idx <= n && num <= m){
		if (a[num] >= c[idx]){
			num++; 
		} 
		idx++; 
	}
	cout << num-1 << endl; 
	return 0; 
}
