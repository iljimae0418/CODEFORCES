#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int a[2001]; 
int main(){
	int n,k; 
	cin >> n >> k; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	sort(a,a+n); 
	int cnt = 0, trail = 0; 
	for (int i = 0; i < n; i++){
		if (trail == 3){
			cnt++; 
			trail = 0; 
		}
		if (a[i]+k <= 5){
			trail++; 
		}else if (a[i]+k > 5){
			break; 
		}
	}
	if (trail == 3){
		cnt++; 
	}
	cout << cnt << endl; 
	return 0; 
}
