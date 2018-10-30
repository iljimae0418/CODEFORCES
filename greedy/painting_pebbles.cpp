#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;  
int a[101]; 
int main(){
	int n,k,minH = (int)1e9,maxH = -(int)1e9; 
	cin >> n >> k; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		minH = min(minH,a[i]); 
		maxH = max(maxH,a[i]);  
	}
	if (maxH-minH > k){
		cout << "NO" << endl; 
	}else{
		cout << "YES" << endl; 
		for (int i = 0; i < n; i++){
			int c = 1;  
			for (int j = 0; j < a[i]; j++){
				if (c == k){
					cout << c << " "; 
					c = 1;  
				}else{
					cout << c << " "; 
					c++; 
				}
			}
			cout << endl; 
		}
	}
	return 0; 
}
