#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
int a[100005]; 
int main(){
	IOFAST(); 
	int n; 
	cin >> n; 
	int minThrough = (int)2e9+88, ans = -1; 
	for (int i = 1; i <= n; i++){
		cin >> a[i];  
		int j = -1; 
		if (a[i]-i < 0){
			j = 0;  
		}else if (a[i]-i >= 0){
			j = (a[i]-i)/n + 1;  
		}
		if (minThrough > i+j*n){
			minThrough = i+j*n;  
			ans = i; 
		}
	}
	cout << ans << endl; 
	return 0; 
}
