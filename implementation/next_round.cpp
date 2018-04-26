// kth place finisher: kth from 1st to bottom (1st has highest score) 
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[55]; 
int main(){
	int n,k,cnt = 0; 
	cin >> n >> k; 
	for (int i = 1; i <= n; i++){
		cin >> a[i];  
	}
	sort(a+1,a+n+1); 
	for (int i = 1; i <= n; i++){
		if (a[i] >= a[n-k+1] && a[i] > 0){
			cnt++;  
		}
	}
	cout << cnt << endl; 
	return 0;  
}
