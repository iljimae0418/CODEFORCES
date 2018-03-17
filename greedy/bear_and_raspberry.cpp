#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int n,c;  
int a[101]; 
int main(){
	cin >> n >> c; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	int maxProfit = -987654321; 
	for (int i = 0; i < n-1; i++){
		maxProfit = max(maxProfit,a[i]-a[i+1]-c);  
	}
	cout << max(0,maxProfit) << endl;
	return 0; 
}	
