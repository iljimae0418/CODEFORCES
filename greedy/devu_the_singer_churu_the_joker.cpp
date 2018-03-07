#include <iostream>
#include <algorithm> 
#include <cstdlib>
using namespace std;  
int a[101];  
int main(){
	int n,d,sum = 0;  
	cin >> n >> d;  
	for (int i = 0; i < n; i++){
		cin >> a[i];  
		sum += a[i]; 
	}
	if (sum+10*(n-1) > d){ // impossible to find proper arrangement  
		cout << -1 << endl; 
	}else{
		cout << (d-sum)/5 << endl; 
	}
	return 0;  
}
