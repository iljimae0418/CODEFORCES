#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int a[100005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	sort(a,a+n); 
	bool can = false; 
	for (int i = 0; i < n-2; i++){
		if (a[i+1]+a[i+2] > a[i] && a[i]+a[i+1] > a[i+2] && 
			a[i]+a[i+2] > a[i+1]){
			can = true; 
			break; 
		}
	}
	cout << (can ? "YES" : "NO") << endl; 
	return 0;  
}
