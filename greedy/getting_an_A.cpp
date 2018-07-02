#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <algorithm>
using namespace std;  
int a[101]; 
int main(){
	int n,sum = 0; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		sum += a[i];  
	}
	int avg = round((double)sum/n); 
	if (avg == 5){
		cout << 0 << endl; 
	}else{
		sort(a,a+n); 
		int cnt = 0;  
		for (int i = 0; i < n; i++){
			cnt++;  
			sum = sum-a[i]+5; 
			avg = round((double)sum/n);  
			if (avg == 5){
				cout << cnt << endl; 
				break; 
			}
		}
	}
	return 0;  
}
