#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int a[101],b[101];  
int main(){
	int n,m; 
	cin >> n;  
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	cin >> m; 
	for (int i = 0; i < m; i++){
		cin >> b[i]; 
	}
	int i = 0, j = 0; // two pointers 
	int cnt = 0; 
	sort(a,a+n); 
	sort(b,b+m); 
	while (i < n && j < m){
		if (abs(a[i]-b[j]) <= 1){
			cnt++;  
			i++; 
			j++; 
		}else if (a[i]-b[j] > 1){
			j++; 
		}else if (b[j]-a[i] > 1){
			i++; 
		}
	}
	cout << cnt << endl; 
	return 0; 
}
