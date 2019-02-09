#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
typedef long long ll; 
ll a[300005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n);  
	if (n&1){
		cout << a[n/2] << endl; 
	}else{	
		cout << a[n/2-1] << endl; 
	}
	return 0;  
}
