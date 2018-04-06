#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std;  
int a[200005];  
int b[200005];  
int psum[200005]; 
int main(){
	int n,t,c; 
	cin >> n >> t >> c; 
	for (int i = 1; i <= n; i++){
		cin >> a[i]; 
		if (a[i] <= t) b[i] = 0; 
		else b[i] = 1; 
	}
	for (int i = 1; i <= n; i++){
		psum[i] = psum[i-1]+b[i];  
	}
	int cnt = 0; 
	for (int i = 1; i+c-1 <= n; i++){
		if (psum[i+c-1]-psum[i-1] == 0){
			cnt++; 
		}
	}
	cout << cnt << endl;
	return 0; 
}
