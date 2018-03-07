#include <iostream>
#include <queue> 
#include <set> 
#include <algorithm> 
using namespace std; 
int main(){
	int n,m,cnt=0;  
	cin >> n >> m; 
	while (n != m){
		if (m < n){
			m++;  
		}else if (m > n){
			if (m%2 == 0) m /= 2; 
			else m++;  
		}
		cnt++;  
	}
	cout << cnt << endl; 
	return 0;  
}
