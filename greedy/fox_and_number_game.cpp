#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[111]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	bool changed = true; 
	while (changed){
		changed = false; 
		sort(a,a+n); 
		int smallest = a[0];
		for (int i = 0; i < n; i++){
			if (smallest < a[i]){
				if (a[i]%smallest == 0){
					a[i] = smallest; 
				}else{
					a[i] = a[i]%smallest;  
				}
				changed = true;  
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++){
		sum += a[i];    
	}
	cout << sum << endl; 
	return 0; 
}
