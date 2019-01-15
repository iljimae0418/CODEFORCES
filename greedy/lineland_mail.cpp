#include <iostream>
#include <algorithm>
using namespace std;
int a[111111]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	for (int i = 0; i < n; i++){
		if (i == 0){
			cout << min(a[1]-a[0],a[n-1]-a[0]) << " " << max(a[1]-a[0],a[n-1]-a[0]) << endl; 
		}else if (i == n-1){
			cout << min(a[n-1]-a[0],a[n-1]-a[n-2]) << " " << max(a[n-1]-a[0],a[n-1]-a[n-2]) << endl; 
		}else{
			cout << min(a[i+1]-a[i],a[i]-a[i-1]) << " " << max(a[n-1]-a[i],a[i]-a[0]) << endl; 
		}
	}
	return 0; 
} 
