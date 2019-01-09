#include <iostream>
#include <algorithm> 
using namespace std; 
int a[111]; 
int main(){
	int n,x,y,cnt = 0; 
	cin >> n >> x >> y; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
		if (a[i] <= x) cnt++; 
	}
	if (x > y){
		cout << n << endl; 
	}else{
		cout << (cnt+1)/2 << endl; 
	}
	return 0;  
}
