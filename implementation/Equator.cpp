#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[200005];  
int main(){
	int n,sum = 0,track = 0; 
	cin >> n; 
	for (int i = 0; i < n; i++){	
		cin >> a[i];
		sum += a[i];   
	}
	for (int i = 0; i < n; i++){
		track += a[i];  
		if (track >= (sum+1)/2){
			cout << i+1 << endl; 
			break; 
		}
	}
	return 0;  
}
