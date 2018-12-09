#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[100005],b[100005];  
int main(){
	int n; 
	double cnt = 0; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		b[i] = a[i];  
	}
	sort(b,b+n);  
	for (int i = 0; i < n; i++){
		if (a[i] != b[i]) cnt++;  
	}
	cnt /= 2;  
	if (cnt <= 1){
		cout << "YES" << "\n"; 
	}else{
		cout << "NO" << "\n"; 
	}
	return 0; 
}
